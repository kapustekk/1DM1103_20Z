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

    struct _Student *next;
} Student;

typedef struct _Przedmiot
{

    char *kod;
    char *nazwa;
    char *semestr;

    struct _Przedmiot *next;
} Przedmiot;

typedef struct _Ocena
{
    char *nr_albumu;
    char *kod_przedmiotu;
    float ocena;
    char *komentarz;

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

#endif