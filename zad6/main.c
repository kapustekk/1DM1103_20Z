/*
Niestety po kompilacji otrzymuje komunikat segmentation fault.
nie wiem gdzie może leżeć problem, nie udało mi się znaleźć jego źródła.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "math.h"
#include "in_out.h"


int main(int argc, char *argv[]) {
    Macierz *maca;
    Macierz *macb;
    FILE * fina;
    FILE *finb;

    if ( strcmp( argv[1], "norm") == 0) {
        fina  = fopen(argv[2], "r");
        maca=wczytaj(fina);
        fclose(fina);
        if (argc == 3)
        printf("norma macierzy z pliku %s = %f\n", argv[2],norm(maca));
        else if (argc==4)
        zapisz_liczbe(argv[3], norm(maca));
        else
        {
        printf("Nieprawidłowe argumenty!\n");   
        exit(-2);
        }     
    }

    else if ( strcmp( argv[1], "sum") == 0) {
        fina = fopen(argv[2], "r");
        finb = fopen(argv[3], "r");
        macb=wczytaj(finb);
        maca=wczytaj(fina);
        fclose(fina);
        fclose(finb);
        if((maca->r!=macb->r)||(maca->c!=macb->c))
        {
            printf("rozmiary macierzy nie są równe!\n");
            exit(-1);
        }
        else if(argc==5)
        zapisz_macierz(argv[4], suma_macierzy(maca, macb));
        else if (argc == 4)
        wypisz(suma_macierzy(maca, macb));
       
        else
        {
        printf("Nieprawidłowe argumenty!\n");
        exit(-3);
        }   
    }

    else if ( strcmp( argv[1], "multiply") == 0) 
    {
        fina = fopen(argv[2], "r");
        maca=wczytaj(fina);
        fclose(fina);
        int skalar = atof(argv[3]);
        if (argc == 4)
        wypisz(pomnoz_skalar(skalar, maca));
        else if (argc == 5)
        zapisz_macierz( argv[4] , pomnoz_skalar(skalar, maca));
        else
        {
        printf("Nieprawidłowe argumenty!\n");
        exit(-4);
        } 
    }

    else if ( strcmp( argv[1], "prod") == 0) 
    {
        fina = fopen(argv[2], "r");
        finb = fopen(argv[3], "r");
        macb=wczytaj(finb);
        maca=wczytaj(fina);
        fclose(fina);
        fclose(finb);
        if (maca->c!=macb->r)
        {
            printf("nieprawdiłowe rozmiary macierzy!\n");
            exit(-8);
        }
        else if (argc == 4)
        wypisz(iloczyn(maca, macb));
        else if (argc == 5)
        zapisz_macierz(argv[4], iloczyn(maca, macb));
        else
        {
        printf("Nieprawidłowe argumenty!\n");
        exit(-5);
        }
    }

    else if ( strcmp( argv[1], "substract") == 0)
    {
        fina = fopen(argv[2], "r");
        finb = fopen(argv[3], "r");
        macb=wczytaj(finb);
        maca=wczytaj(fina);
        fclose(fina);
        fclose(finb);
        if ((maca->r!=macb->r)||(maca->c!=macb->c))
        {
            printf("nieprawdiłowe rozmiary macierzy!\n");
            exit(-7);
        }
        else if (argc == 4)
        wypisz(odejmij(maca, macb));
        else if (argc == 5)
        zapisz_macierz(argv[4], odejmij(maca, macb));
        else
        {
        printf("Nieprawidłowe argumenty!\n");
        exit(-6);
        }
    }
    return 0;
    zwolnij(maca);
    zwolnij(macb);
}
