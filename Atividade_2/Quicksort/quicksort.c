#include <stdio.h>

// Função para trocar elementos
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// Função que toma o último elemento como pivô, coloca o pivô em sua posição correta no array ordenado
// e coloca todos menores (menores que o pivô) à esquerda do pivô e todos maiores à direita do pivô
int partition (int arr[], int low, int high) {
    int pivot = arr[high];    // pivô
    int i = (low - 1);  // Índice do menor elemento

    for (int j = low; j <= high - 1; j++) {
        // Se o elemento atual for menor que o pivô
        if (arr[j] < pivot) {
            i++;    // incrementa o índice do menor elemento
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Função principal que implementa QuickSort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // pi é o índice de particionamento, arr[pi] está agora no lugar certo
        int pi = partition(arr, low, high);

        // Ordena separadamente os elementos antes e depois da partição
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Função para imprimir um array de tamanho n
void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Função principal para executar o código acima
int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, n - 1);
    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}
