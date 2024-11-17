#include <stdio.h>

// Função para realizar o Shell Sort
void shellSort(int arr[], int n) {
    // Começa com um grande intervalo, reduzindo-o até 1
    for (int gap = n/2; gap > 0; gap /= 2) {
        // Faz um "gapped" insertion sort para este intervalo.
        // Os primeiros elementos gap do arr[] já estão em ordem gapped mantendo o gap
        for (int i = gap; i < n; i += 1) {
            // Adiciona arr[i] aos elementos que foram classificados com gapped
            // Salva arr[i] em temp e faz um buraco na posição i
            int temp = arr[i];

            // Desloca elementos anteriores ao gap até encontrar a posição correta de arr[i]
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];

            // Coloca temp (o valor original de arr[i]) em sua posição correta
            arr[j] = temp;
        }
    }
}

// Função para imprimir um array de tamanho n
void printArray(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Função principal para executar o código acima
int main() {
    int arr[] = {12, 34, 54, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Array before sorting: \n");
    printArray(arr, n);

    shellSort(arr, n);

    printf("Array after sorting: \n");
    printArray(arr, n);
    return 0;
}
