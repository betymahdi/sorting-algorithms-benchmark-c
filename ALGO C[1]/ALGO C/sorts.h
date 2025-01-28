//Groupe B
//Lemrani Kenza : CCN
//Mahdi Ibtissam : CCN
//Moutawakil Latifa : BDCC


#ifndef SORTS_H
#define SORTS_H


// SortFunction est un pointeur vers une fonction prenant un tableau d'entiers (int[]) 
// et un entier (taille du tableau) comme paramètres, et ne retournant rien (void).
typedef void(*SortFunction)(int[], int);

// Déclaration de la fonction de tri à bulles (Bubble Sort)
// Algorithme simple qui compare et échange les éléments adjacents.
void bubbleSort(int arr[], int n);

// Déclaration de la fonction de tri par sélection (Selection Sort)
// Algorithme qui sélectionne à chaque étape le plus petit élément restant et le place à sa position finale.
void selectionSort(int arr[], int n);

// Déclaration de la fonction de tri par insertion (Insertion Sort)
// Algorithme qui insère chaque élément à la bonne position dans une partie triée du tableau.
void insertionSort(int arr[], int n);

// Déclaration de la fonction adaptatrice pour le tri rapide (Quick Sort)
// Utilise une stratégie de division pour trier rapidement un tableau.
void quickSortAdapter(int arr[], int n);

// Déclaration de la fonction adaptatrice pour le tri fusion (Merge Sort)
// Divise le tableau en deux moitiés, les trie, puis fusionne les résultats.
void mergeSortAdapter(int arr[], int n);

// Déclaration de la fonction pour le tri par tas (Heap Sort)
// Algorithme basé sur une structure en tas pour trier efficacement un tableau.
void heapSort(int arr[], int n);

// Déclaration de la fonction pour le tri par comptage (Counting Sort)
// Algorithme non comparatif basé sur le comptage des éléments pour les trier.
void countingSort(int arr[], int n);

// Déclaration de la fonction pour le tri par base (Radix Sort)
// Algorithme non comparatif qui trie les nombres chiffre par chiffre, de la base la plus basse à la plus haute.
void radixSort(int arr[], int n);

// Déclaration de la fonction pour le tri de Shell (Shell Sort)
// Variante optimisée du tri par insertion avec un intervalle (gap) réduisant progressivement.
void shellSort(int arr[], int n);

#endif // Fin de la directive conditionnelle pour éviter les inclusions multiples
