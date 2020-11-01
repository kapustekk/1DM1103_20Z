#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int wczytaj(FILE *fin, float *tablica) {
    int wlasciwie_zinterpretowane;
    int dlugosc = 0;
    int i;
    float liczba;

    if ((wlasciwie_zinterpretowane = fscanf(fin, "%d", &dlugosc)) != 1) {
        printf("Pierwszy napis nie jest liczbą całkowitą "
               "(Liczba prawidłowo zinterpretowanych argumentów: %d)!\n", 
               wlasciwie_zinterpretowane);
        exit(-1);
    }

    for (i=0; i < dlugosc; i++) {
        if (fscanf(fin, "%f", &liczba) != 1) {
            printf("%d-ta liczba w pliku nie jest liczbą zmiennoprzecinkową.\n", i+1);
            exit(-2);
        }
        tablica[i] = liczba;
    }

    return dlugosc;
}

float suma(float *tablica, int dlugosc) {
    float suma = 0;
    for (int i=0; i < dlugosc; i++) {
        suma += tablica[i];
    }

    return suma;
}

void wypisz_wektor(float *w, int n) {
    printf("(%d) [", n);
    for (int j=0; j<n; j++)
        printf("%f ", w[j]);
    printf("]\n");
}

// wczytal z pliku wektor liczb i wyswietli na ekranie ich sume!
int main(int argc, char *argv[]) {
    FILE *fin; //
    float wektor[100];
    int dlugosc;

    fin = fopen( argv[1], "r");
    dlugosc = wczytaj(fin, wektor);
    printf("%d\n", dlugosc);

    wypisz_wektor(wektor, dlugosc);

    printf("Suma %d liczb z pliku %s: %f\n", dlugosc, argv[1], suma(wektor, dlugosc));

    return 0;
}