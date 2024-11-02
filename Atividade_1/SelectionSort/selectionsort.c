#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 50


void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;

        // Encontra o menor elemento no array não ordenado
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }

        // Troca o elemento encontrado com o primeiro elemento não ordenado
        int temp = arr[minIdx];
        arr[minIdx] = arr[i];
        arr[i] = temp;
    }
}

// Função para imprimir o array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Função para copiar um array para outro
void copyArray(int source[], int destination[], int n) {
    for (int i = 0; i < n; i++) {
        destination[i] = source[i];
    }
}

int main() {
    int arr[SIZE], arrCopy[SIZE];
    srand(time(NULL));

    // Preenche o array com valores aleatórios
    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand() % 100;
    }

    printf("Array original:\n");
    printArray(arr, SIZE);

    // Medindo o tempo do Selection Sort
    copyArray(arr, arrCopy, SIZE);
    clock_t start = clock();
    selectionSort(arrCopy, SIZE);
    clock_t end = clock();
    double timeSelection = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Selection Sort:\n");
    printArray(arrCopy, SIZE);
    printf("Tempo: %f segundos\n", timeSelection);

    return 0;
}

// resultado

// tempo de execução de 0.000004 segundos