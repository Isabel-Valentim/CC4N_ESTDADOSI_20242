#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 50


void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        // Últimos i elementos já estarão na ordem correta
        for (int j = 0; j < n - i - 1; j++) {
            // Troca os elementos se eles estiverem na ordem errada
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
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

    // Medindo o tempo do Bubble Sort
    copyArray(arr, arrCopy, SIZE);
    clock_t start = clock();
    bubbleSort(arrCopy, SIZE);
    clock_t end = clock();
    double timeBubble = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Bubble Sort:\n");
    printArray(arrCopy, SIZE);
    printf("Tempo: %f segundos\n", timeBubble);

    return 0;
}


// resultado: 

// tempo de execução foi de 0.000005 segundos