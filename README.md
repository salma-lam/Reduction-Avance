# Mini Projet : Optimisation de Calculs Parallèles avec OpenMP

## Description

Ce projet a pour objectif d'explorer des scénarios complexes d'optimisation de calculs parallèles en utilisant la réduction en OpenMP. Vous mettrez en pratique les concepts de réduction et explorerez des notions avancées telles que la gestion des dépendances, l'équilibrage de charge entre threads, et la réduction des temps d'attente.

## Étapes principales

#### Phase 1 : Implémentation d'un Calcul Parallèle Simple avec Réduction

- Implémentation simple de l'algorithme de Monte-Carlo pour estimer la valeur de π.
- Utilisation de la réduction en OpenMP pour paralléliser le calcul du nombre de points à l'intérieur du cercle.

#### Phase 2 : Optimisation des Performances

- Utilisation de différentes stratégies d'optimisation : gestion des dépendances, équilibrage des charges (schedule), et limitation des conflits de cache.
- Test de différentes tailles de problème et configurations de threads pour analyser les gains de performance.

#### Phase 3 : Mesure et Analyse des Performances

- Mesure du speedup et de l'efficacité en augmentant le nombre de threads et en comparant les versions optimisées et non optimisées.
- Analyse des points de contention et des goulots d'étranglement dans le calcul parallèle.

## Prérequis

- [OpenMP](https://www.openmp.org/)
- Un compilateur C/C++ compatible avec OpenMP (comme GCC).
- - Python avec les bibliothèques Matplotlib et NumPy.

## Exécution  
Sur MinGW ou MSYS2. 
Pour MSYS2, assurez-vous d'installer le package mingw-w64.
 
 ```bash

gcc -fopenmp -o code code.c
./code 
