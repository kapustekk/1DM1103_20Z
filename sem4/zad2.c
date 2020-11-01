#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int wczytaj_macierz(FILE *filea,float tablicaa[][100]){
    int wierszea, kolumnya;
    float liczbaa;

    if((fscanf(filea, "%d%d", &wierszea, &kolumnya)) != 2) {
        printf("Podany rozmiar w macierzy nie jest liczbą całkowitą!\n ");
        exit(-1);
    }
    for(int i=0; i<wierszea; i++)
        for(int j=0; j<kolumnya; j++)
        {
            if (fscanf(filea, "%f", &liczbaa)!=1)
            {
                printf("liczba o wpolrzednych (w=%d,k=%d) z macierzy nie jest zmiennoprzecinkowa!\n", i+1, j+1);
                exit(-3);
            }
            tablicaa[i][j]=liczbaa;
        }
        return wierszea;
}
int wczytaj_wektor(FILE *filex, float tablicax[]){
    
    int wierszex, kolumnyx;
    float liczbax;

    fscanf(filex, "%d%d", &wierszex, &kolumnyx);
    for (int i=0; i < wierszex; i++) {
        if (fscanf(filex, "%f", &liczbax) != 1) {
            printf("%d-ta liczba z wektora nie jest liczbą zmiennoprzecinkowa!\n", i+1);
            exit(-2);
        }
        tablicax[i] = liczbax;
    }
    return wierszex;
}
int wymnoz_i_wypisz(float macierz[][100], float wektor[100], int wierszea, int wierszex)
{
    float wynik=0;
    printf("(%d) [",wierszea);
    for(int i=0;i<wierszea;i++)
    {
        for(int j=0;j<wierszex;j++)
        {
            wynik+=(macierz[i][j])*wektor[j];
        }
        printf("%.1f ",wynik);
        wynik=0;
    }
    printf("\b]");
    
}

int main(int argc, char **argv)
{
    
    int wierszea, kolumnya, wierszex, kolumnyx;    
    FILE *filea;//plik macierzy
    float tablicaa[100][100];
    float tablicax[100];
    FILE *filex;//plik wektora
    //otwieram pliki
    filea = fopen(argv[1], "r");
    filex = fopen(argv[2], "r");
    
    wierszex = wczytaj_wektor(filex, tablicax);
    wierszea = wczytaj_macierz(filea, tablicaa);
    wymnoz_i_wypisz(tablicaa,tablicax,wierszea,wierszex);
    //printf("%.1f %.1f\n%.1f %.1f\n%.1f %.1f\n",tablicaa[0][0],tablicaa[0][1],tablicaa[1][0],tablicaa[1][1],tablicaa[2][0],tablicaa[2][1]);
    //printf("\n\n\n");
    //printf("%.1f\n%.1f\n",tablicax[0],tablicax[1]);

}
