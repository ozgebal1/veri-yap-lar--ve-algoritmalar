#include <stdio.h>

#define N 7

void ozelsirala(int dizi[], int N) {

    int temp;

    // Küçükten büyüğe sıralama
    for (int i = 0; i < N - 1; i++) {

        for (int j = 0; j < N - i - 1; j++) {

            if (dizi[j] > dizi[j + 1]) {

                temp = dizi[j];
                dizi[j] = dizi[j + 1];
                dizi[j + 1] = temp;
            }
        }
    }

    int sonuc[N];

    int bas = 0;
    int son = N - 1;
    int index = 0;

    while (bas <= son) {

        if (bas != son) {

            sonuc[index++] = dizi[son--];
            sonuc[index++] = dizi[bas++];

        } else {

            sonuc[index++] = dizi[bas++];
        }
    }

    printf("Ozel siralama sonucu:\n");

    for (int i = 0; i < N; i++) {
        printf("%d ", sonuc[i]);
    }
}

int main() {

    int dizi[N] = {60, 83, 3, 9, 57, 14, 30};

    ozelsirala(dizi, N);

    return 0;
}
