#ifndef _BAZA_H
#define _BAZA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Student
{
    char *imie;
    char *nazwisko;
    char *nr_albumu;
    char *email;

    struct _Student *poprz;
    struct _Student *next;
} Student;

typedef struct _Przedmiot
{

    char *kod;
    char *nazwa;
    char *semestr;

    struct _Przedmiot *poprz;
    struct _Przedmiot *next;
} Przedmiot;

typedef struct _Ocena
{
    char *nr_albumu;
    char *kod_przedmiotu;
    char *ocena;
    char *komentarz;

    struct _Ocena *poprz;
    struct _Ocena *next;
} Ocena;

typedef struct _SBaza
{
    Student *lista_studentow; /* Głowa listy! */
    Przedmiot *lista_przedmiotow;
    Ocena *lista_ocen;
} SBaza;

SBaza *wczytaj_baze(char *nazwa_pliku);
Ocena *wczytaj_oceny(FILE *fin);
Przedmiot *wczytaj_przedmioty(FILE *fin);
void zapisz_baze(char *nazwa_pliku, SBaza *baza);
void listuj_studentow(SBaza *baza);
void listuj_oceny(SBaza *baza);
void listuj_przedmioty(SBaza *baza);
void zwolnij(SBaza *baza);
int ile_studentow(SBaza *baza);
int ile_przedmiotow(SBaza *baza);
int ile_ocen(SBaza *baza);
void add_student(SBaza *baza, char *imie, char *nazwisko, char *nr_albumu, char *email);
void add_subject(SBaza *baza, char *kod, char *nazwa, char *semestr);

Student * najwiekszy(Student *el);
Student * usun(Student *glowa, Student *el);
Student * ostatni(Student *glowa);
Student * sortuj_stud_przez_wybieranie(Student *glowa);
Przedmiot * sortuj_przed_po_nazwach(Przedmiot *glowa);
Przedmiot * sortuj_przed_po_kodach(Przedmiot *glowa);
Ocena * sortuj_ocena_przez_wybieranie(Ocena *glowa);
void listuj_studentow_od_konca(SBaza *baza);
void listuj_przedmioty_od_konca(SBaza *b);
void listuj_oceny_od_konca(SBaza *b);

int znalezione_kody(Ocena *glowao, char *kod_przedmiotu);
Ocena * filtruj_przedmiot(Ocena *glowao, char *kod_przedmiotu);
int znalezione_albumy(Ocena *glowao, char *album);
Ocena * filtruj_student(Ocena *glowao, char *album);
void wypisz_glowe_ocen(Ocena*glowa);

#endif