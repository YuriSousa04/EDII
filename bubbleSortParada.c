void bubbleSortMelhorado(int arr[], int n) {
    int trocou;
    for (int i = 0; i < n-1; i++) {
        trocou = 0;
        for (int j = 0; j < n-i-1; j++)
            if (arr[j] > arr[j+1]) {
                int tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
                trocou = 1;
            }
        if (!trocou) break;
    }
}
