#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 500

void selectionSort(int arr[]) {
    for (int i = 0; i < SIZE - 1; i++) {

        int min = i;

        for (int j = i + 1; j < SIZE; j++) {
            if (arr[j] < arr[min])
                min = j;
        }

        int temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }
}

int main() {

    int arr[SIZE];

    srand(time(NULL));

    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand() % 1001;
    }

    clock_t start = clock();

    selectionSort(arr);

    clock_t end = clock();

    printf("Selection Sort Süre: %lf\n",
           (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}
