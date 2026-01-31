#!/bin/bash

# ==============================================================================
#  PUSH_SWAP GOD MODE TESTER
# ==============================================================================
# Usage: ./tester.sh [short|mid|long]
#   short : Rapide (Validation de base)
#   mid   : Recommandé (Test solide)
#   long  : Cauchemar (Test intensif avant soutenance)

PUSH_SWAP="./push_swap"
CHECKER="./checker_linux"
LOG_FILE="trace_god_mode.log"

# Couleurs
RED='\033[1;31m'
GREEN='\033[1;32m'
YELLOW='\033[1;33m'
BLUE='\033[1;34m'
PURPLE='\033[1;35m'
CYAN='\033[1;36m'
NC='\033[0m'

# Configuration des itérations (x4 par rapport à la normale)
MODE="${1:-mid}"
case "$MODE" in
    short) ITER_100=20; ITER_500=20 ;;
    mid)   ITER_100=100; ITER_500=100 ;;
    long)  ITER_100=500; ITER_500=500 ;;
    *) echo -e "${RED}Mode inconnu. Utilise: short, mid, long${NC}"; exit 1 ;;
esac

# Nettoyage
> "$LOG_FILE"
rm -f .user_out .user_err

echo -e "${PURPLE}======================================================${NC}"
echo -e "${PURPLE}       🔥 PUSH_SWAP GOD MODE TESTER ($MODE) 🔥       ${NC}"
echo -e "${PURPLE}======================================================${NC}"

if [ ! -f "$PUSH_SWAP" ]; then
    echo -e "${RED}❌ $PUSH_SWAP manquant. Fais 'make'.${NC}"
    exit 1
fi
if [ ! -f "$CHECKER" ]; then
    echo -e "${YELLOW}⚠️ $CHECKER manquant. Tests de tri moins stricts.${NC}"
    CHECKER=""
fi

# Fonction de barre de progression
progress_bar() {
    local current=$1
    local total=$2
    local percent=$((current * 100 / total))
    local bar_len=40
    local filled=$((percent * bar_len / 100))
    local empty=$((bar_len - filled))
    printf "\r["; printf "%0.s#" $(seq 1 $filled); printf "%0.s-" $(seq 1 $empty); printf "] %d%%" "$percent"
}

# Fonction générique de test
run_test() {
    local name="$1"
    local arg="$2"
    local expected="$3" # OK, Error, Ignore
    local limit="$4"

    # Exécution séparant STDOUT et STDERR
    $PUSH_SWAP $arg > .user_out 2> .user_err
    
    # Lecture résultats
    output_out=$(cat .user_out)
    output_err=$(cat .user_err)
    instr_count=$(echo -n "$output_out" | grep -c '^')

    # 1. Gestion des ERREURS (Doit être sur STDERR)
    if [ "$expected" == "Error" ]; then
        if echo "$output_err" | grep -q "Error"; then
            echo -e "${GREEN}[OK]${NC} $name (Error caught on STDERR)"
        elif echo "$output_out" | grep -q "Error"; then
            echo -e "${YELLOW}[WARN]${NC} $name (Error on STDOUT instead of STDERR - fix main.c)"
        else
            echo -e "${RED}[KO]${NC} $name (Expected Error, got nothing)"
            echo "FAIL_ERROR: $name | Args: '$arg' | Out: '$output_out' | Err: '$output_err'" >> "$LOG_FILE"
        fi
        return
    fi

    # 2. Gestion des CAS VIDES / TRIÉS (Rien attendu)
    if [ "$expected" == "Ignore" ]; then
        if [ "$instr_count" -eq 0 ] && [ -z "$output_err" ]; then
            echo -e "${GREEN}[OK]${NC} $name (Silent)"
        else
            echo -e "${RED}[KO]${NC} $name (Expected silence, got output)"
            echo "FAIL_SILENT: $name | Args: '$arg' | Instr: $instr_count | Err: '$output_err'" >> "$LOG_FILE"
        fi
        return
    fi

    # 3. Validation du TRI (Avec Checker)
    if [ -n "$CHECKER" ]; then
        check_res=$(echo "$output_out" | $CHECKER $arg 2>&1)
        if [[ "$check_res" == *"OK"* ]]; then
            if [ -n "$limit" ] && [ "$instr_count" -gt "$limit" ]; then
                echo -e "${RED}[LIMIT]${NC} $name: $instr_count > $limit ops"
                echo "FAIL_LIMIT: $name | Args: $arg | Count: $instr_count" >> "$LOG_FILE"
            else
                echo -e "${GREEN}[OK]${NC} $name ($instr_count ops)"
            fi
        else
            echo -e "${RED}[KO]${NC} $name (Checker: $check_res)"
            echo "FAIL_SORT: $name | Args: $arg | Checker: $check_res" >> "$LOG_FILE"
        fi
    else
        echo -e "${YELLOW}[UNK]${NC} $name ($instr_count ops)"
    fi
}

# Fonction Stress Test
run_stress() {
    local size=$1
    local count=$2
    local limit=$3
    
    echo -e "\n${CYAN}>>> STRESS TEST: $size nombres ($count essais)${NC}"
    
    total=0
    max=0
    min=999999
    fails=0

    for ((i=1; i<=count; i++)); do
        ARG=$(shuf -i 1-100000 -n "$size" | tr '\n' ' ')
        $PUSH_SWAP $ARG > .user_out 2> .user_err
        
        check="OK"
        if [ -n "$CHECKER" ]; then
            if ! cat .user_out | $CHECKER $ARG | grep -q "OK"; then
                check="KO"
                fails=$((fails+1))
                echo "FAIL_RANDOM_$size: Run #$i | Args: $ARG" >> "$LOG_FILE"
            fi
        fi
        
        lines=$(grep -c '^' .user_out)
        total=$((total + lines))
        if [ "$lines" -gt "$max" ]; then max=$lines; fi
        if [ "$lines" -lt "$min" ]; then min=$lines; fi
        
        progress_bar $i $count
    done
    echo ""
    
    avg=$((total / count))
    col=$GREEN
    if [ "$avg" -gt "$limit" ]; then col=$RED; fi
    
    echo -e "  -> Moyenne: ${col}$avg${NC} (Obj: <$limit) | Max: $max | Min: $min | Fails: ${RED}$fails${NC}"
}

# --- TESTS ---

echo -e "\n${BLUE}1. PARSING & ERREURS (Vicieux)${NC}"
run_test "Lettres" "1 2 a 3" "Error"
run_test "Doublons" "1 2 3 2" "Error"
run_test "INT_MAX overflow" "2147483648" "Error"
run_test "INT_MIN underflow" "-2147483649" "Error"
run_test "Signe seul (+)" "+" "Error"
run_test "Signe seul (-)" "-" "Error"
run_test "Double signe (--)" "--5" "Error"
run_test "Double signe (++)" "++5" "Error"
run_test "Signe après chiffre (5-)" "5-" "Error"
run_test "Zéro et Zéro" "0 0" "Error"
run_test "0 et 000" "0 000" "Error"
run_test "Espaces vides" "   " "Ignore" # Ou Error selon ton parsing, 'Ignore' est standard pour arg vide
run_test "Vide" "" "Ignore"

echo -e "\n${BLUE}2. IDENTITÉ & TRIVIAL${NC}"
run_test "1 nombre" "42" "Ignore"
run_test "2 triés" "1 2" "Ignore"
run_test "5 triés" "1 2 3 4 5" "Ignore"
run_test "Trié avec négatifs" "-10 -5 0 5 10" "Ignore"

echo -e "\n${BLUE}3. PETITS TESTS (Validité)${NC}"
run_test "2 inversés" "2 1" "OK" 1
run_test "3 random" "2 1 3" "OK" 3
run_test "5 random" "1 5 2 4 3" "OK" 12
run_test "5 inversés" "5 4 3 2 1" "OK" 12
run_test "Cas INT_MIN/MAX" "2147483647 -2147483648 0" "OK" 10

echo -e "\n${BLUE}4. PERFORMANCE (Stress Tests)${NC}"
run_stress 100 $ITER_100 700
run_stress 500 $ITER_500 5500

echo -e "\n${PURPLE}======================================================${NC}"
if [ -s "$LOG_FILE" ]; then
    echo -e "${RED}❌ ERREURS DÉTECTÉES ! Voir $LOG_FILE${NC}"
    head -n 5 "$LOG_FILE"
else
    echo -e "${GREEN}✅ SUCCÈS TOTAL ! PRÊT POUR LA SOUTENANCE !${NC}"
    rm -f .user_out .user_err "$LOG_FILE"
fi