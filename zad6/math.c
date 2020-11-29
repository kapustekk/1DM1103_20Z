#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "math.h"
float norm(Macierz *m)
{
    float s=0;
    int i,j;
    for (i = 0; i < m->r; i++) 
        for (j=0; j < m->c; j++) 
            s += m->tab[i][j] * m->tab[i][j];

    return sqrt(s);
}

Macierz* suma_macierzy(Macierz *ma, Macierz *mb) //dodaj dwie macierze
{
    Macierz *liczba;
    liczba = (Macierz*) malloc(sizeof(Macierz));
    liczba->r=ma->r;
    liczba->c=ma->c;
    liczba->tab = (float**) malloc(sizeof(float*) * liczba->r);
    for (int i = 0; i < ma->r; i++)
    {
        liczba->tab[i] = (float*) malloc(sizeof(float) * liczba->c);
        for (int j=0; j < ma->c; j++) 
            liczba->tab[i][j] = ma->tab[i][j] + mb->tab[i][j];
    }
    return liczba;
}

float suma_elementow(Macierz *m) //funkcja sumy wszystkich elementów danej macierzy
{ 
    float s = 0;
    int i,j;

    for (i = 0; i < m->r; i++)
        for (j=0; j < m->c; j++)
            s += m->tab[i][j];

    return s;
}

Macierz* pomnoz_skalar(int k, Macierz *m)
{
    Macierz *suma;
    suma = (Macierz*) malloc(sizeof(Macierz));
    suma->r=m->r;
    suma->c=m->c;

    
    for (int i = 0; i < m->r; i++) 
        for (int j=0; j < m->c; j++) 
            suma->tab[i][j] = m->tab[i][j] * k;

    return suma;
}

Macierz *iloczyn(Macierz *a, Macierz *b)
{
    Macierz *liczba;
    liczba=(Macierz*) malloc(sizeof(Macierz));
    liczba->r=a->r;
    liczba->c=b->c;

    liczba->tab = (float**) malloc(sizeof(float*) * liczba->r);
    for(int wiersz=0; wiersz<a->r; wiersz++)
    {
    liczba->tab[wiersz] = (float*) malloc(sizeof(float) * liczba->c);
        for(int kolumna=0; kolumna<b->c; kolumna++)
            for(int n=0; n<a->c; n++)
                liczba->tab[wiersz][kolumna] += a->tab[wiersz][n]*b->tab[n][kolumna];
    }

    return liczba;
}

Macierz *odejmij(Macierz *ma, Macierz *mb)
{
    Macierz *liczba;
    liczba = (Macierz*) malloc(sizeof(Macierz));
    liczba->r=ma->r;
    liczba->c=ma->c;
    liczba->tab = (float**) malloc(sizeof(float*) * liczba->r);
    for (int i = 0; i < ma->r; i++)
    {
        liczba->tab[i] = (float*) malloc(sizeof(float) * liczba->c);
        for (int j=0; j < ma->c; j++) 
            liczba->tab[i][j] = ma->tab[i][j] - mb->tab[i][j];
    }
    return liczba;
}
