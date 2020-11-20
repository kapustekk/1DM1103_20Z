#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "studenci.h"

int wczytaj(student dane[100], char *fnazwa) {
    FILE * fin = fopen(fnazwa, "r");
    int cnt, i;
    char bufor[1024];
    char *w;

    fgets(bufor, 1023, fin);
    sscanf(bufor, "%d", &cnt);
 
    for (i=0; i<cnt; i++) {
        fgets(bufor, 1023, fin);
        // printf("%s", bufor);
        w = strtok(bufor, "|");
        strncpy(dane[i].imie, w, 24);

        w = strtok(NULL, "|");
        strncpy(dane[i].nazwisko, w, 49);
        
        w = strtok(NULL, "|");
        strncpy(dane[i].nr_albumu, w, 9);

        w = strtok(NULL, "|");
        strncpy(dane[i].kod_przed, w, 9);

        w = strtok(NULL, "|");
        strncpy(dane[i].nazwa_przed, w, 254);

        w = strtok(NULL, "|");
        dane[i].ocena = atof(w);

        w = strtok(NULL, "|");
        dane[i].ects = atoi(w);
    }

    fclose(fin);
    return cnt;
}

void wypisz(student dane[100], int n) {
    int i;
    for (i=0; i<n;i++) {
        printf("{ Student: %s - %s %s, z przedmiotu: [%s] %s za ECTS: %d otrzymał %.1f\n",
            dane[i].nr_albumu, dane[i].imie, dane[i].nazwisko,
            dane[i].kod_przed, dane[i].nazwa_przed,
            dane[i].ects, dane[i].ocena
        );
    }
}

int znajdz(char *szukany_nr, char kod_przedmiotu[100][10], int n) {//znajdz kod przedmiotu; powtarza sie to wraca indeks
    int i;
    for (i=0; i<n; i++) {
        if (strcmp(szukany_nr, kod_przedmiotu[i]) == 0)
            return i;
    }
    return -1;
}

int szukaj(char *szukany_nr, char nr_albumow[100][10], int n) {
    int i;
    for (i=0; i<n; i++) {
        if (strcmp(szukany_nr, nr_albumow[i]) == 0)
            return i;
    }
    return -1;
}

int znajdz_studentow(char nr_albumow[100][10], student dane[100], int n) {
    int ile_znalazlem = 0;
    int i;

    for (i=0; i <n; i++) {
        if (szukaj(dane[i].nr_albumu, nr_albumow, ile_znalazlem ) == -1) {
            strncpy(nr_albumow[ile_znalazlem], dane[i].nr_albumu, 9);
            ile_znalazlem++;
        }
    }
    return ile_znalazlem;
}

int znajdz_przedmiot(char kod_przed[100][10], student dane[100], int n) {
    int ile_znalazlem = 0;

    for (int i=0; i <n; i++) {
        if (znajdz(dane[i].kod_przed, kod_przed, ile_znalazlem ) == -1) {//porownaj mi kod przedmiotu rekordu 1,2,3... z kodem pojedynczym 
            strncpy(kod_przed[ile_znalazlem], dane[i].kod_przed, 9);//skopiuj do 9 znakow z kodów do danych, w danych mam teraz unikalne (4) kody
            ile_znalazlem++;
        }
    }
    return ile_znalazlem;
}
