#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "math.h"

Macierz* wczytaj(FILE * fin) {
    int i,j;
    Macierz *m=(Macierz*) malloc(sizeof(Macierz));
    // fscanf(fin, "%d", &(*m).r);
    // fscanf(fin, "%d", &(*m).c);
    fscanf(fin, "%d", &m->r);
    fscanf(fin, "%d", &m->c);

    m->tab = (float**) malloc(sizeof(float*) * m->r);
    for (i=0;i<m->r;i++)
        m->tab[i] = (float*) malloc(sizeof(float) * m->c);
    
    for (i=0; i < m->r; i++)
        for (j=0; j < m->c; j++)
            fscanf(fin, "%f", &m->tab[i][j]);
}

void wypisz(Macierz *m) {
    int i, j;
    for (i = 0; i < m->r; i++) {
    printf("[ ");
        for (j=0; j < m->c; j++) {
            printf("%.1f ", m->tab[i][j]);
        }
            printf("]\n");
    }
    printf("\n");
}

void zapisz_macierz(char nazwa[], Macierz *m) {
    FILE * fout = fopen(nazwa, "w");
    int i,j;

    fprintf(fout, "%d\n%d\n", m->r, m->c);
    for (i = 0; i < m->r; i++)
        for (j=0; j < m->c; j++) 
            fprintf(fout, "%.1f\n", m->tab[i][j]);//dla wiekszej dokladnosci po przecinku usunac .1!

    fclose(fout);
}
void zapisz_liczbe(char nazwa[], float liczba)
{
    FILE *fout = fopen(nazwa, "w+");
    fprintf(fout, "norma macierzy = %f\n", liczba);
    fclose(fout);
}
void zwolnij(Macierz *m){
    for (int i = 0; i <m->r; i++) 
    free(m->tab[i]);
    free(m->tab);
    free(m);
}
