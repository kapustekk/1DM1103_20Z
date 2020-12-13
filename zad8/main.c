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
    else if (strcmp("sort_students", argv[2]) == 0) {
        baza -> lista_studentow = sortuj_stud_przez_wybieranie(baza->lista_studentow);
        if(argc == 4&&strcmp("reverse",argv[3])==0)
        listuj_studentow_od_konca(baza);
        else
        listuj_studentow(baza);
    }
    else if(strcmp("sort_subjects_by_name",argv[2])==0){
        baza -> lista_przedmiotow = sortuj_przed_po_nazwach(baza->lista_przedmiotow);
        if(argc == 4&&strcmp("reverse",argv[3])==0)
        listuj_przedmioty_od_konca(baza);
        else
        listuj_przedmioty(baza);
    }
    else if(strcmp("sort_subjects_by_code",argv[2])==0){
        baza -> lista_przedmiotow = sortuj_przed_po_kodach(baza->lista_przedmiotow);
        if(argc == 4&&strcmp("reverse",argv[3])==0)
        listuj_przedmioty_od_konca(baza);
        else
        listuj_przedmioty(baza);
    }
    else if(strcmp("filter_subject",argv[2])==0)
    {
        int n=znalezione_kody(baza->lista_ocen,argv[3]);
        Ocena*glowa;
        glowa= filtruj_przedmiot(baza->lista_ocen,argv[3]);
        // printf("%d\n",znalezione_kody(baza->lista_ocen,argv[3]));
        printf("znalezione oceny z przedmiotu: %s\n",argv[3]);
        for(int i=0;i<n;i++)
        {
            if(n>1)
            {
            wypisz_glowe_ocen(glowa->poprz);
            // alternatywnie:
            // printf("%s - %s - %s \n", glowa->poprz->nr_albumu, glowa->poprz->ocena, glowa->poprz->komentarz);
            glowa->poprz=glowa->poprz->next;
            }
            else if(n==1)
            wypisz_glowe_ocen(glowa);
            else if(n==0)
            printf("brak ocen dla tego przedmiotu!\n");
        }
    }
    else if(strcmp("filter_student",argv[2])==0)
    {
        int n=znalezione_albumy(baza->lista_ocen,argv[3]);
        Ocena*glowa;
        glowa= filtruj_student(baza->lista_ocen,argv[3]);
        printf("znalezione oceny studenta o albumie: %s\n",argv[3]);
        for(int i=0;i<n;i++)
        {
            if(n>1)
            {
            wypisz_glowe_ocen(glowa->poprz);
            // printf("%s - %s - %s \n", glowa->poprz->kod_przedmiotu, glowa->poprz->ocena, glowa->poprz->komentarz);
            glowa->poprz=glowa->poprz->next;
            }
            else if(n==1)
            wypisz_glowe_ocen(glowa);
            else if(n==0)
            printf("brak ocen dla tego studenta!\n");

        }
    }

    // else if (strcmp("list_students_from_end", argv[2]) == 0) {
    //     listuj_studentow_od_konca(baza);
    // }

    zapisz_baze(argv[1], baza);
    zwolnij(baza);
    return 0;
}