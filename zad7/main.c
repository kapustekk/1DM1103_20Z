#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "baza.h"

int main(int argc, char ** argv) {
    SBaza *baza;
    baza = wczytaj_baze(argv[1]);

    if (strcmp("list_students", argv[2]) == 0) {
        printf("%d\n",ile_studentow(baza));
        listuj_studentow(baza);
        // printf("%d\n",ile_przedmiotow(baza));
        // listuj_przedmioty(baza);
        // printf("%d\n",ile_ocen(baza));
        // listuj_oceny(baza);
    }
    else if(strcmp("list_base",argv[2])==0)
    {
        printf("%d\n",ile_studentow(baza));
        listuj_studentow(baza);
        printf("%d\n",ile_przedmiotow(baza));
        listuj_przedmioty(baza);
        printf("%d\n",ile_ocen(baza));
        listuj_oceny(baza);
    }
    else if (strcmp("count_students", argv[2]) == 0) {
        printf("Liczba studentów: %d\n", ile_studentow(baza));
        printf("Liczba przedmiotów: %d\n", ile_przedmiotow(baza));
        printf("Liczba ocen: %d\n", ile_ocen(baza));
    }
    else if(strcmp("add_student",argv[2])==0){
        add_student(baza, argv[3],argv[4],argv[5],argv[6]);
    }
    else if(strcmp("add_subject",argv[2])==0){
        add_subject(baza, argv[3],argv[4],argv[5]);
    }

    zapisz_baze(argv[1], baza);
    zwolnij(baza);
    return 0;
}