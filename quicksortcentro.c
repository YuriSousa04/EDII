
void quicksortCentro(int arr[], int inicio, int fim) {
    if (inicio >= fim) return;

    int centro = (inicio + fim) / 2;
    int pivo = arr[centro];
    int i = inicio, j = fim;
    while (i <= j) {
        while (arr[i] < pivo) i++;
        while (arr[j] > pivo) j--;
        if (i <= j) {
            int tmp = arr[i];
            arr[i++] = arr[j];
            arr[j--] = tmp;
        }
    }

    if (inicio < j) quicksortCentro(arr, inicio, j);
    if (i < fim) quicksortCentro(arr, i, fim);
}
