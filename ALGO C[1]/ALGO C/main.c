//Groupe B
//Lemrani Kenza : CCN
//Mahdi Ibtissam : CCN
//Moutawakil Latifa : BDCC

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sorts.h" // Inclure le fichier des fonctions de tris

// Fonction pour remplir un tableau avec des valeurs aleatoires
void remplirTableau(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000; 
    }
}
//Afficher les elements d'un tableau
void afficherTableau(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
//Fonction pour mesurer le temps d'execution
double mesurerTemps(void (*tri)(int[], int), int arr[], int n) {
    clock_t start = clock(); // Mesurer le temps d'execution (debut)
    tri(arr, n);// Appeler la fonction de tri
    clock_t end = clock(); // Mesurer le temps d'execution (fin)
    //retourner le temps en secondes
    return (double)(end - start) / CLOCKS_PER_SEC; 
}
//Fonction pour tracer la courbe
void tracerCourbe() {
    FILE *fgnuplot = fopen("courbe.gnu", "w"); // cree un fichier pour les instructions gnuplot
    if (fgnuplot == NULL) {
        perror("Impossible d'ouvrir le fichier");
        return;
    }

    fprintf(fgnuplot, "set title 'Resultat des tris'\n"); 
    fprintf(fgnuplot, "set xrange [1000:10000];\n"); //limite de l'axe x
    fprintf(fgnuplot, "set yrange [0:0.02];\n"); //limite de l'axe y
    fprintf(fgnuplot, "set xlabel 'taille du tableau'\n"); 
    fprintf(fgnuplot, "set ylabel 'Temps en  (s)'\n");
    fprintf(fgnuplot, "set key right top box;\n"); 

    //  Trace les courbes pour chaque algorithme de tri à partir des colonnes de 'resultat.txt'
    fprintf(fgnuplot, "plot 'resultat.txt' using 1:2 with linespoints title 'Bubble Sort' lt rgb 'blue', \\\n");// Bleu
    fprintf(fgnuplot, "     'resultat.txt' using 1:3 with linespoints title 'Selection Sort' lt rgb 'red', \\\n");// Rouge
    fprintf(fgnuplot, "     'resultat.txt' using 1:4 with linespoints title 'Insertion Sort' lt rgb 'green', \\\n");// Vert
    fprintf(fgnuplot, "     'resultat.txt' using 1:5 with linespoints title 'Quick Sort' lt rgb '#9400D3', \\\n"); // Violet
    fprintf(fgnuplot, "     'resultat.txt' using 1:6 with linespoints title 'Heap Sort' lt rgb '#FF8C00', \\\n"); // Orange foncé
    fprintf(fgnuplot, "     'resultat.txt' using 1:7 with linespoints title 'Merge Sort' lt rgb '#4682B4', \\\n"); // Bleu acier
    fprintf(fgnuplot, "     'resultat.txt' using 1:8 with linespoints title 'Counting Sort' lt rgb 'purple', \\\n");// Mauve
    fprintf(fgnuplot, "     'resultat.txt' using 1:9 with linespoints title 'Radix Sort' lt rgb '#A52A2A', \\\n"); // Marron
    fprintf(fgnuplot, "     'resultat.txt' using 1:10 with linespoints title 'Shell Sort' lt rgb 'magenta'\n");// Magenta

    fprintf(fgnuplot, "pause mouse\n");// Permet de mettre en pause le graphique
    
    fclose(fgnuplot);
    printf("Fichier Gnuplot créé avec succès \n");
}


int main() {
    //taleau de pointeurs vers les fonctions de tri
   void (*sortFunctions[])(int[], int) = {
    bubbleSort, selectionSort, insertionSort, quickSortAdapter, heapSort, mergeSortAdapter, countingSort, radixSort, shellSort
};
const char *sortNames[] = {
    "Bubble Sort", "Selection Sort", "Insertion Sort", "Quick Sort", "Heap Sort", "Merge Sort", "Counting Sort", "Radix Sort", "Shell Sort"
};
    // Ouvre un fichier pour stocker les résultats des temps d'exécution
    FILE *fp = fopen("resultat.txt", "w");
    if (fp == NULL) {
        printf("Impossible d'ouvrir le fichier\n");
        return 1;
    }
 // Itère sur différentes tailles de tableau
  for (int n = 1000; n <= 10000; n += 1000) {
    fprintf(fp, "%d ", n); 
    for (int i = 0; i < sizeof(sortFunctions) / sizeof(sortFunctions[0]); i++) {
        int *arr = malloc(n * sizeof(int));
        if (arr == NULL) {
            printf("Erreur d'allocation de mémoire\n");
            fclose(fp);
            return 1;
        }
        remplirTableau(arr, n);
        
        double tempsEcoule = mesurerTemps(sortFunctions[i], arr, n); 
        printf("%s pour n=%d: %.6f secondes\n", sortNames[i], n, tempsEcoule);
        
        fprintf(fp, "%.6f ", tempsEcoule);
        free(arr);
    }
    fprintf(fp, "\n");
}


    fclose(fp);
    tracerCourbe();// Appelle la fonction pour créer le fichier Gnuplot
    return 0;
}