#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct Macierz {
    int r;
    int c;
    float tab[200][200];
};

void wczytaj(FILE * fin, struct Macierz *m) {
    int i,j;
    // fscanf(fin, "%d", &(*m).r);
    // fscanf(fin, "%d", &(*m).c);
    fscanf(fin, "%d", &m->r);
    fscanf(fin, "%d", &m->c);

    for (i=0; i < m->r; i++) {
        for (j=0; j < m->c; j++) {
            fscanf(fin, "%f", &m->tab[i][j]);
        }
    }
}

void wypisz(struct Macierz m) {
    int i, j;
    for (i = 0; i < m.r; i++) {
    printf("[ ");
        for (j=0; j < m.c; j++) {
            printf("%.1f ", m.tab[i][j]);
        }
            printf("]\n");
    }
    printf("\n");
}

float norm(struct Macierz m) {
    float s = 0;
    int i,j;

    for (i = 0; i < m.r; i++) 
        for (j=0; j < m.c; j++) 
            s += m.tab[i][j] * m.tab[i][j];

    return sqrt(s);
}
struct Macierz suma_macierzy(struct Macierz ma, struct Macierz mb) //dodaj dwie macierze
{
    struct Macierz liczba;
    liczba.r=ma.r;
    liczba.c=ma.c;
    for (int i = 0; i < ma.r; i++) 
        for (int j=0; j < ma.c; j++) 
            liczba.tab[i][j] = ma.tab[i][j] + mb.tab[i][j];

    return liczba;
}

float suma_elementow(struct Macierz m) //funkcja sumy wszystkich elementów danej macierzy
{ 
    float s = 0;
    int i,j;

    for (i = 0; i < m.r; i++)
        for (j=0; j < m.c; j++)
            s += m.tab[i][j];

    return s;
}

void zapisz_macierz(char nazwa[], struct Macierz m) {
    FILE * fout = fopen(nazwa, "w");
    int i,j;

    fprintf(fout, "%d\n%d\n", m.r, m.c);
    for (i = 0; i < m.r; i++)
        for (j=0; j < m.c; j++) 
            fprintf(fout, "%.1f\n", m.tab[i][j]);//dla wiekszej dokladnosci po przecinku usunac .1!

    fclose(fout);
}
void zapisz_liczbe(char nazwa[], float liczba)
{
    FILE *fout = fopen(nazwa, "w+");
    fprintf(fout, "norma macierzy = %f\n", liczba);
    fclose(fout);
}

struct Macierz pomnoz_skalar(int k, struct Macierz m)
{
    
    for (int i = 0; i < m.r; i++) 
        for (int j=0; j < m.c; j++) 
            m.tab[i][j] = m.tab[i][j] * k;

    return m;
}

struct Macierz iloczyn(struct Macierz a, struct Macierz b)
{
    struct Macierz liczba;
    liczba.r=a.r;
    liczba.c=b.c;
    for(int wiersz=0; wiersz<a.r; wiersz++)
        for(int kolumna=0; kolumna<b.c; kolumna++)
            for(int n=0; n<a.c; n++)
                liczba.tab[wiersz][kolumna] += a.tab[wiersz][n]*b.tab[n][kolumna];

    return liczba;
}

struct Macierz odejmij(struct Macierz ma, struct Macierz mb)
{
    struct Macierz liczba;
    liczba.r=ma.r;
    liczba.c=ma.c;
    for (int i = 0; i < ma.r; i++) {
        for (int j=0; j < ma.c; j++) {
            liczba.tab[i][j] = ma.tab[i][j] - mb.tab[i][j];
        }
    }
    return liczba;
}

int main(int argc, char *argv[]) {
    struct Macierz maca;
    struct Macierz macb;
    FILE * fina;
    FILE *finb;

    if ( strcmp( argv[1], "norm") == 0) {
        fina  = fopen(argv[2], "r");
        wczytaj(fina, &maca);
        fclose(fina);
        if (argc == 3)
        printf("norma macierzy z pliku %s = %f\n", argv[2],norm(maca));
        if (argc==4)
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
        wczytaj(finb, &macb);
        wczytaj(fina, &maca);
        fclose(fina);
        fclose(finb);
        if((maca.r!=macb.r)||(maca.c!=macb.c))
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
        wczytaj(fina, &maca);
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
        wczytaj(finb, &macb);
        wczytaj(fina, &maca);
        fclose(fina);
        fclose(finb);
        if (maca.k!=macb.r)
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
        wczytaj(finb, &macb);
        wczytaj(fina, &maca);
        fclose(fina);
        fclose(finb);
        if ((maca.r!=macb.r)||(maca.c!=macb.c))
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
}
