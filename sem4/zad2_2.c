#include<stdio.h>
#include<string.h>
#include<stdlib.h>


int main(int argc, char **argv)
{
    int wierszea, kolumnya, dlugosc;
    FILE *filea;//plik macierzy
    float tablicaa[100][100];
    float tablicaw[100];
    FILE *filex;//plik wektora

    //otwieram pliki
    filea = fopen(argv[1], "r");
    
    fscanf(filea, "%d", &dlugosc);
    printf("%d", dlugosc);
}
