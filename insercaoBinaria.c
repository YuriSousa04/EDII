int buscaBinaria(int arr[], int item, int low, int high) {
    if (high <= low)
        return (item > arr[low]) ? (low + 1) : low;

    int mid = (low + high) / 2;
    if (item == arr[mid])
        return mid + 1;
    if (item > arr[mid])
        return buscaBinaria(arr, item, mid + 1, high);
    return buscaBinaria(arr, item, low, mid - 1);
}

void insercaoBinaria(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int val = arr[i];
        int j = i - 1;
        int pos = buscaBinaria(arr, val, 0, j);
        while (j >= pos) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[pos] = val;
    }
}
