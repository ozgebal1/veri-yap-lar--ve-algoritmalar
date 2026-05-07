#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 500

void insertionSort(int arr[]) {
    for (int i = 1; i < SIZE; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

int main() {
    int arr[SIZE];

    srand(time(NULL));

    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand() % 1001;
    }

    clock_t start = clock();

    insertionSort(arr);

    clock_t end = clock();

    printf("Insertion Sort Süre: %f\n",
           (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}
