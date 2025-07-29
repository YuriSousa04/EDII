#include <stdlib.h>

void insertionSortBucket(float arr[], int n) {
    for (int i = 1; i < n; i++) {
        float val = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > val) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = val;
    }
}

void bucketSort(float arr[], int n) {
    int i, j, k;
    int numBuckets = 10;
    float **buckets = malloc(numBuckets * sizeof(float*));
    int *bucketSizes = calloc(numBuckets, sizeof(int));

    for (i = 0; i < numBuckets; i++)
        buckets[i] = malloc(n * sizeof(float));

    for (i = 0; i < n; i++) {
        int bi = arr[i] * numBuckets;
        buckets[bi][bucketSizes[bi]++] = arr[i];
    }

    for (i = 0; i < numBuckets; i++)
        insertionSortBucket(buckets[i], bucketSizes[i]);

    k = 0;
    for (i = 0; i < numBuckets; i++)
        for (j = 0; j < bucketSizes[i]; j++)
            arr[k++] = buckets[i][j];

    for (i = 0; i < numBuckets; i++) free(buckets[i]);
    free(buckets);
    free(bucketSizes);
}
