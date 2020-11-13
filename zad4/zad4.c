/**
Mamy mini bazę studentów (tabelę z studentami, przedmiotami i ocenami)
Cel: obliczyć ranking.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _student {
    char imie[25];
    char nazwisko[50];
    char nr_albumu[10];
    char kod_przed[10];
    char nazwa_przed[255];
    float ocena;
    int ects;
} student, *pstudent;

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

void naj_przedmiot(student dane[100], int ile_rekordow)
{
    char kod_przedmiotu[100][10];
    int przedmioty=znajdz_przedmiot(kod_przedmiotu,dane,ile_rekordow);;//ile jest unikalnych przedmiotow
    char nazwa_przedmiotu[100][255];
    float suma_ocen[100];
    float srednia[100];
    float liczba_ocen[100];//ile ocen z danego przedmiotu
    int i,j;
    int pozycja;
    int naj_pozycja;
    float najgorsza_srednia = 100.0f;
    float najlepsza_srednia = 0.0f;

    for (i=0; i < ile_rekordow; i++) {
        pozycja = znajdz(dane[i].kod_przed, kod_przedmiotu,przedmioty);
        suma_ocen[pozycja] += dane[i].ocena;//dodaje do konkretnego przedmiotu kolejne oceny
        liczba_ocen[pozycja]++;
        strcpy(nazwa_przedmiotu[pozycja],dane[i].nazwa_przed);
        
    }

    for (i=0; i < przedmioty; i++)
        srednia[i] = suma_ocen[i]/liczba_ocen[i];

    for (i=0; i<przedmioty;i++)
    {
        if(najgorsza_srednia>srednia[i])
        {
            najgorsza_srednia=srednia[i];
            naj_pozycja=i;
        }
    }
    printf("Najtrudniejszy przedmiot: %s - %s:%f\n",kod_przedmiotu[naj_pozycja],nazwa_przedmiotu[naj_pozycja],srednia[naj_pozycja]);
   
    for (j=0; j<przedmioty;j++)
        if(najlepsza_srednia<srednia[j])
        {
            najlepsza_srednia=srednia[j];
            naj_pozycja=j;
        }
    
    printf("Najlatwiejszy przedmiot: %s - %s:%f\n",kod_przedmiotu[naj_pozycja],nazwa_przedmiotu[naj_pozycja],srednia[naj_pozycja]);
}

int main(int argc, char ** argv) {
    student dane[100];
    int ile,ilex;
    // dane == &dane[0]
    ile = wczytaj(dane, argv[1]);
    wypisz(dane, ile);

    naj_przedmiot(dane,ile);

    return 0;
}