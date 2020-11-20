#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "studenci.h"

void najtrudniejszy_przedmiot(student dane[100], int ile_rekordow)
{
    char kod_przedmiotu[100][10];
    int przedmioty=znajdz_przedmiot(kod_przedmiotu,dane,ile_rekordow);;//ile jest unikalnych przedmiotow
    char nazwa_przedmiotu[100][255];
    float suma_ocen[100];
    float srednia[100];
    float liczba_ocen[100];//ile ocen z danego przedmiotu
    int i;
    int pozycja;
    int naj_pozycja;
    float najgorsza_srednia = 100.0f;

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

}
void najlatwiejszy_przedmiot(student dane[100], int ile_rekordow)
{
    char kod_przedmiotu[100][10];
    int przedmioty=znajdz_przedmiot(kod_przedmiotu,dane,ile_rekordow);;//ile jest unikalnych przedmiotow
    char nazwa_przedmiotu[100][255];
    float suma_ocen[100];
    float srednia[100];
    float liczba_ocen[100];//ile ocen z danego przedmiotu
    int i;
    int pozycja;
    int naj_pozycja;
    float najgorsza_srednia = 0.0f;

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
        if(najgorsza_srednia<srednia[i])
        {
            najgorsza_srednia=srednia[i];
            naj_pozycja=i;
        }
    }
    printf("Najłatwiejszy przedmiot: %s - %s:%f\n",kod_przedmiotu[naj_pozycja],nazwa_przedmiotu[naj_pozycja],srednia[naj_pozycja]);

}



void najlepszy_student(student dane[100], int ile_rekordow) {
    char nr_albumow[100][10];
    int ile_studentow;
    float sumy_wazonych_ocen[100];
    int sumy_ects[100];
    int i;
    int pozycja;
    int najlepsza_pozycja;
    float najlepsza = 0.0f;

    ile_studentow = znajdz_studentow(nr_albumow, dane, ile_rekordow);
    for(int k=0; k<ile_rekordow; k++)
    {
    sumy_ects[k]=0;
    sumy_wazonych_ocen[k]=0;
    }
    for (i=0; i < ile_rekordow; i++) {
        pozycja = szukaj( dane[i].nr_albumu, nr_albumow, ile_studentow );
        // if (pozycje >= 0)
        sumy_wazonych_ocen[pozycja] += dane[i].ocena * dane[i].ects;
        sumy_ects[pozycja] += dane[i].ects;
    }    

    // for (i=0;i<ile_studentow; i++) 
    //     printf("Student [%d]: %s - %f:%d - %f \n", i+1, nr_albumow[i], 
    //     sumy_wazonych_ocen[i], sumy_ects[i], sumy_wazonych_ocen[i] / sumy_ects[i]);

    for (i=0; i < ile_studentow; i++) {
        if (najlepsza < sumy_wazonych_ocen[i] / sumy_ects[i]) {
            najlepsza = sumy_wazonych_ocen[i] / sumy_ects[i];
            najlepsza_pozycja = i;
        }
    }

    printf("Najlepszy student: \n");
    printf("Student [%d]: %s - %f \n", 
        najlepsza_pozycja+1, nr_albumow[najlepsza_pozycja],
        sumy_wazonych_ocen[najlepsza_pozycja] / sumy_ects[najlepsza_pozycja]
    );
}