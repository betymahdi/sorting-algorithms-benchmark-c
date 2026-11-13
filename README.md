# Sorting Algorithms Benchmark (C)

Comparaison des performances de neuf algorithmes de tri, implémentés en C, en fonction de la taille du tableau à trier. Les temps d'exécution sont mesurés puis tracés avec Gnuplot.

## Algorithmes comparés

Tri à bulles, tri par sélection, tri par insertion, tri rapide (quicksort), tri fusion (merge sort), tri par tas (heap sort), tri par comptage, tri par base (radix sort) et tri de Shell.

## Contenu du projet

Les sources se trouvent dans le dossier `ALGO C[1]/ALGO C` :

- `main.c` : programme principal, mesure du temps d'exécution de chaque algorithme
- `sorts.c` et `sorts.h` : implémentation des algorithmes de tri
- `resultat.txt` : temps mesurés (une ligne par taille de tableau, une colonne par algorithme)
- `courbe.gnu` : script Gnuplot qui trace les courbes de performance

## Compilation et exécution

```bash
cd "ALGO C[1]/ALGO C"
gcc main.c sorts.c -o tri
./tri
gnuplot courbe.gnu
```

## Ce que montre l'étude

Les tris quadratiques (bulles, sélection, insertion) voient leur temps d'exécution augmenter nettement avec la taille du tableau, alors que les tris plus avancés (rapide, fusion, tas, comptage, radix, Shell) restent proches de zéro sur les tailles testées.

## Technologies

C, Gnuplot
