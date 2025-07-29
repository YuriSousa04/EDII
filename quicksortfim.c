
void quicksortFim(int arr[], int inicio, int fim) {
    if (inicio >= fim) return;

    int pivo = arr[fim];
    int i = inicio - 1;
    for (int j = inicio; j < fim; j++) {
        if (arr[j] <= pivo) {
            i++;
            int tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
        }
    }
    int tmp = arr[i+1];
    arr[i+1] = arr[fim];
    arr[fim] = tmp;

    quicksortFim(arr, inicio, i);
    quicksortFim(arr, i+2, fim);
}
