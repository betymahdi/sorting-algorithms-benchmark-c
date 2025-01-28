//Groupe B
//Lemrani Kenza : CCN
//Mahdi Ibtissam : CCN
//Moutawakil Latifa : BDCC

#include "sorts.h"
#include <stdio.h>
#include <stdlib.h>

// Tri à bulles (Bubble Sort)
// Algorithme simple qui compare les éléments adjacents et les échange si nécessaire.
//complexité O(n^2)
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) { 
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}

// Tri par sélection (Selection Sort)
// Trouve le plus petit élément et l'échange avec le premier élément non trié.
//complexité O(n^2)
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        if (min != i) {
            int tmp = arr[min];
            arr[min] = arr[i];
            arr[i] = tmp;
        }
    }
}

// Tri par insertion (Insertion Sort)
// Insère chaque élément dans sa position correcte dans la partie triée.
//complexité O(n^2)
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int tmp = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > tmp) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = tmp;
    }
}

// Fonction principale pour le tri rapide (Quick Sort)
// Utilise une stratégie de division pour trier rapidement un tableau.
//complexité O(n log n)
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = arr[low];
        int i = low - 1;
        int j = high + 1;
        while (1) {
            do { i++; } while (arr[i] < pivot);
            do { j--; } while (arr[j] > pivot);
            if (i >= j) {
                break;
            }
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
        quickSort(arr, low, j);
        quickSort(arr, j + 1, high);
    }
}

// Fonction pour transformer un tableau en tas (Heapify)
// Crée un tas en utilisant la stratégie de division.
//complexité O(log n)
void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }
    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, n, largest);
    }
}

// Tri par tas (Heap Sort)
// Crée un tas et extrait les éléments triés un par un.
//complexité O(n log n)
void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
    for (int i = n - 1; i >= 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0);
    }
}

// Fusionne deux sous-tableaux triés (Merge Function)
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Tri fusion (Merge Sort)
// Divise le tableau en deux parties, les trie, puis les fusionne.
//complexité O(n log n)
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// Adaptateurs pour le tri rapide et le tri fusion
void quickSortAdapter(int arr[], int n) {
    quickSort(arr, 0, n - 1);
}

void mergeSortAdapter(int arr[], int n) {
    mergeSort(arr, 0, n - 1);
}

// Tri par comptage (Counting Sort)
// Compte les occurrences des éléments et les trie en conséquence.
//complexité O(n + k)
void countingSort(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];

    int* count = (int*)calloc(max + 1, sizeof(int));
    for (int i = 0; i < n; i++)
        count[arr[i]]++;

    int index = 0;
    for (int i = 0; i <= max; i++) {
        while (count[i] > 0) {
            arr[index++] = i;
            count[i]--;
        }
    }
    free(count);
}

// Tri par base (Radix Sort)
// Trie les nombres en traitant chaque chiffre individuellement.

void countingSortRadix(int arr[], int n, int exp) {
    int* output = (int*)malloc(n * sizeof(int));
    int count[10] = {0};

    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (int i = 0; i < n; i++)
        arr[i] = output[i];

    free(output);
}

// Tri par base (Radix Sort)
// Trie les nombres en traitant chaque chiffre individuellement.
// Complexité : 
// - Meilleur cas : O(n * k), où n est la taille du tableau et k est le nombre de chiffres du plus grand élément.
// - Cas moyen : O(n * k).
// - Pire cas : O(n * k).
// Radix Sort est efficace lorsque la plage des valeurs (ou la base) est limitée.
void radixSort(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) // Trouver le plus grand élément.
        if (arr[i] > max)
            max = arr[i];

    for (int exp = 1; max / exp > 0; exp *= 10) // Itérer sur chaque chiffre (unités, dizaines...).
        countingSortRadix(arr, n, exp);
}

// Tri de Shell (Shell Sort)
// Une variante optimisée du tri par insertion en utilisant un intervalle décroissant (gap).
// Complexité : 
// - Meilleur cas : O(n log n), dépend de la séquence des gaps utilisée.
// - Cas moyen : O(n^(3/2)) ou pire selon la séquence des gaps.
// - Pire cas : O(n^2), pour une mauvaise séquence de gaps.
// Remarque : Ce tri est in-situ (utilise peu de mémoire supplémentaire).
void shellSort(int arr[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) { // Réduire progressivement le gap.
        for (int i = gap; i < n; i++) { // Appliquer un tri par insertion modifié.
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) // Déplacer les éléments.
                arr[j] = arr[j - gap];
            arr[j] = temp; // Placer l'élément à la bonne position.
        }
    }
}
