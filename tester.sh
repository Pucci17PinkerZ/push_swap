#!/bin/bash

# Configuration
PUSH_SWAP="./push_swap"
CHECKER="./checker_linux" # Assure-toi d'avoir le checker fourni par 42 ou le tien
LOG_FILE="trace_error.log"

# Couleurs
GREEN='\033[0;32m'
RED='\033[0;31m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color

# Nettoyage du log précédent
> "$LOG_FILE"

# Vérification de l'existence des binaires
if [ ! -f "$PUSH_SWAP" ]; then
    echo -e "${RED}Erreur: $PUSH_SWAP non trouvé. Compile d'abord !${NC}"
    exit 1
fi

if [ ! -f "$CHECKER" ]; then
    echo -e "${YELLOW}Attention: $CHECKER non trouvé. Les tests de validité utiliseront une méthode simple.${NC}"
    CHECKER=""
fi

echo -e "${BLUE}=========================================${NC}"
echo -e "${BLUE}       PUSH_SWAP ULTIMATE TESTER         ${NC}"
echo -e "${BLUE}=========================================${NC}"
echo ""

# Fonction de test générique
run_test() {
    local test_name="$1"
    local arg="$2"
    local expected_status="$3" # "OK" ou "Error" ou "LIMIT"
    local limit="$4"

    echo -n -e "Test: ${YELLOW}$test_name${NC} ... "

    # Exécution
    if [ "$expected_status" == "Error" ]; then
        output=$($PUSH_SWAP $arg 2>&1)
        if echo "$output" | grep -q "Error"; then
            echo -e "${GREEN}[PASS]${NC} (Error detected correctly)"
        else
            echo -e "${RED}[FAIL]${NC} (Expected Error, got: $output)"
            echo "FAIL: $test_name | Args: $arg | Output: $output" >> "$LOG_FILE"
        fi
    else
        instructions=$($PUSH_SWAP $arg)
        line_count=$(echo "$instructions" | wc -l)
        
        # Vérification du tri
        if [ -n "$CHECKER" ]; then
            check_result=$(echo "$instructions" | $CHECKER $arg 2>&1)
        else
            # Fallback si pas de checker: vérifier si la sortie est vide pour une entrée triée
             if [ "$expected_status" == "SORTED" ] && [ "$line_count" -eq 0 ]; then
                check_result="OK"
            elif [ "$expected_status" != "SORTED" ]; then
                # Difficile de vérifier sans checker, on suppose OK si ça ne crash pas
                check_result="Check_Manual"
            else
                 check_result="KO"
            fi
        fi

        # Analyse du résultat
        if [[ "$check_result" == *"OK"* ]]; then
            if [ -n "$limit" ]; then
                if [ "$line_count" -le "$limit" ]; then
                     echo -e "${GREEN}[OK]${NC} | Instr: $line_count (Limit: $limit)"
                else
                     echo -e "${RED}[KO]${NC} | Instr: ${RED}$line_count${NC} (Limit: $limit) - Too many instructions"
                     echo "FAIL_LIMIT: $test_name | Args: $arg | Count: $line_count" >> "$LOG_FILE"
                fi
            else
                echo -e "${GREEN}[OK]${NC} | Instr: $line_count"
            fi
        else
            echo -e "${RED}[KO]${NC} | Checker: $check_result"
            echo "FAIL_SORT: $test_name | Args: $arg | Checker: $check_result" >> "$LOG_FILE"
        fi
    fi
}

# ==========================================
# 1. Tests d'Erreurs (Parsing)
# ==========================================
echo -e "\n${BLUE}--- 1. EDGE CASES : PARSING & ERREURS ---${NC}"
run_test "Non-numeric input" "1 2 a 3" "Error"
run_test "Doubles" "1 2 3 2" "Error"
run_test "Max Int Overflow" "2147483648 1 2" "Error"
run_test "Min Int Underflow" "-2147483649 1 2" "Error"
run_test "Empty argument" "" "NoOutput" # Devrait rien afficher ou ne pas crash

# ==========================================
# 2. Cas Triviaux (Pas d'action requise)
# ==========================================
echo -e "\n${BLUE}--- 2. EDGE CASES : DÉJÀ TRIÉ / VIDE ---${NC}"
run_test "Empty list" "" "SORTED" 0
run_test "One number" "42" "SORTED" 0
run_test "Sorted 2" "1 2" "SORTED" 0
run_test "Sorted 3" "1 2 3" "SORTED" 0
run_test "Sorted 5" "1 2 3 4 5" "SORTED" 0

# ==========================================
# 3. Listes Simples (2, 3, 5 nombres)
# ==========================================
echo -e "\n${BLUE}--- 3. SIMPLE LISTS ---${NC}"
run_test "Random 2" "2 1" "OK" 1
run_test "Random 3 (Case 1)" "1 3 2" "OK" 2
run_test "Random 3 (Case 2)" "2 1 3" "OK" 2
run_test "Random 3 (Case 3)" "3 2 1" "OK" 2
run_test "Random 5" "1 5 2 4 3" "OK" 12

# ==========================================
# 4. Tests Aléatoires (Moyens & Grands)
# ==========================================
echo -e "\n${BLUE}--- 4. RANDOM STRESS TESTS ---${NC}"

# Test 100 nombres (5 essais)
echo -e "${YELLOW}>> Testing 100 Numbers (Goal: < 700 ops)${NC}"
for i in {1..5}; do
    ARG=$(shuf -i 1-5000 -n 100 | tr '\n' ' ')
    run_test "Random 100 #$i" "$ARG" "OK" 700
done

# Test 500 nombres (5 essais)
echo -e "\n${YELLOW}>> Testing 500 Numbers (Goal: < 5500 ops)${NC}"
for i in {1..5}; do
    ARG=$(shuf -i 1-5000 -n 500 | tr '\n' ' ')
    run_test "Random 500 #$i" "$ARG" "OK" 5500
done

# ==========================================
# 5. Cas Spéciaux "Vicieux"
# ==========================================
echo -e "\n${BLUE}--- 5. VICIOUS CASES ---${NC}"
# Liste inversée
run_test "Reverse 5" "5 4 3 2 1" "OK" 12
run_test "Negative Numbers" "-1 -5 -2 0 3" "OK" 12
# Max et Min INT ensemble
run_test "Min & Max INT" "2147483647 -2147483648 0" "OK" 5

echo -e "\n${BLUE}=========================================${NC}"
if [ -s "$LOG_FILE" ]; then
    echo -e "${RED}Tests terminés avec des erreurs. Voir $LOG_FILE pour les détails.${NC}"
    cat "$LOG_FILE"
else
    echo -e "${GREEN}TOUS LES TESTS SONT PASSÉS ! BRAVO !${NC}"
    rm "$LOG_FILE"
fi
echo -e "${BLUE}=========================================${NC}"