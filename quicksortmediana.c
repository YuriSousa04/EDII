
int medianaDeTres(int arr[], int inicio, int fim) {
    int meio = (inicio + fim) / 2;

    if (arr[inicio] > arr[meio]) {
        int tmp = arr[inicio];
        arr[inicio] = arr[meio];
        arr[meio] = tmp;
    }
    if (arr[inicio] > arr[fim]) {
        int tmp = arr[inicio];
        arr[inicio] = arr[fim];
        arr[fim] = tmp;
    }
    if (arr[meio] > arr[fim]) {
        int tmp = arr[meio];
        arr[meio] = arr[fim];
        arr[fim] = tmp;
    }

    // Troca a mediana com o penúltimo elemento
    int tmp = arr[meio];
    arr[meio] = arr[fim - 1];
    arr[fim - 1] = tmp;
    return arr[fim - 1];
}

void quicksortMediana(int arr[], int inicio, int fim) {
    if (inicio + 2 > fim) {
        for (int i = inicio + 1; i <= fim; i++) {
            int chave = arr[i];
            int j = i - 1;
            while (j >= inicio && arr[j] > chave) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = chave;
        }
        return;
    }

    int pivo = medianaDeTres(arr, inicio, fim);
    int i = inicio;
    int j = fim - 1;

    while (1) {
        while (arr[++i] < pivo);
        while (arr[--j] > pivo);
        if (i < j) {
            int tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
        } else {
            break;
        }
    }

    int tmp = arr[i];
    arr[i] = arr[fim - 1];
    arr[fim - 1] = tmp;

    quicksortMediana(arr, inicio, i - 1);
    quicksortMediana(arr, i + 1, fim);
}
