#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 50

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        // Move elementos do array que são maiores que a chave uma posição à frente
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key; // Insere a chave na posição correta
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

    // Medindo o tempo do Insertion Sort
    copyArray(arr, arrCopy, SIZE);
    clock_t start = clock();
    insertionSort(arrCopy, SIZE);
    clock_t end = clock();
    double timeInsertion = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Insertion Sort:\n");
    printArray(arrCopy, SIZE);
    printf("Tempo: %f segundos\n", timeInsertion);

    return 0;
}

// resultado: 

// tempo de execução doi de 0.000002 segundos