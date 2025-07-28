#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "bubbleSort.h" // Suponha que você tenha criado isso com seu .h e .c

int main() {
    int arr[] = {5, 2, 9, 1, 6,2 ,2,2,2,32,3,3,4,4,4,2,5,5,3213213213,6,6,67,1,7,7,7};
    int n = sizeof(arr) / sizeof(arr[0]);

    clock_t start, end;
    double tempo;

    // Medindo tempo de execução do Bubble Sort
    start = clock();

    bubbleSort(arr, n);

    end = clock();
    tempo = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Tempo Bubble Sort: %.6f segundos\n", tempo);

    return 0;
}
