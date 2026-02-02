*This project has been created as part of the 42 curriculum by nfiora-d.*

# 🔄 Push_swap

![Language](https://img.shields.io/badge/Language-C-blue)
![School](https://img.shields.io/badge/School-42-black)

## Description

**Push_swap** est un projet d'algorithmique de l'école 42. L'objectif est de trier des données sur une pile (stack), avec un set d'instructions limité, en utilisant le moins de mouvements possibles.

Le programme prend en paramètre une liste d'entiers, les place dans une pile A, et doit afficher la suite d'instructions permettant de trier cette pile, en utilisant une pile auxiliaire B.

### Règles du jeu
Le projet utilise deux piles : **Stack A** et **Stack B**.
Les mouvements autorisés sont :

| Commande | Action |
| :--- | :--- |
| **sa / sb / ss** | Swap : Échange les deux premiers éléments de la pile. |
| **pa / pb** | Push : Prend le premier élément d'une pile et le met sur l'autre. |
| **ra / rb / rr** | Rotate : Décale tous les éléments vers le haut (le premier devient dernier). |
| **rra / rrb / rrr** | Reverse Rotate : Décale tous les éléments vers le bas (le dernier devient premier). |

## Instructions

### 1. Compilation
Pour compiler le projet, clonez le dépôt et utilisez la commande `make` à la racine (aussi dispo sur github):

```bash
git clone [https://github.com/nfiora-d/push_swap.git](https://github.com/nfiora-d/push_swap.git)
cd push_swap
make