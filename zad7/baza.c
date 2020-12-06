#include "baza.h"

Student *wczytaj_studentow(FILE *fin)
{
    char bufor[255];
    int n, i;
    char *s;
    Student *last_student = NULL;
    Student *glowa = NULL;
    fgets(bufor, 254, fin);
    sscanf(bufor, "%d", &n);
    //printf("xd\n");
    for (i = 0; i < n; i++)
    {
        Student *stud = (Student *)malloc(sizeof(Student));
        stud->next = NULL;

        if (last_student == NULL)
            glowa = stud;
        else
            last_student->next = stud;
        last_student = stud;

        fgets(bufor, 254, fin);
        s = strtok(bufor, ";");
        stud->imie = (char *)malloc(sizeof(char) * (strlen(s) + 1));
        strcpy(stud->imie, s);

        s = strtok(NULL, ";");
        stud->nazwisko = (char *)malloc(sizeof(char) * (strlen(s) + 1));
        strcpy(stud->nazwisko, s);

        s = strtok(NULL, ";");
        stud->nr_albumu = (char *)malloc(sizeof(char) * (strlen(s) + 1));
        strcpy(stud->nr_albumu, s);

        s = strtok(NULL, "\n");
        stud->email = (char *)malloc(sizeof(char) * (strlen(s) + 1));
        strcpy(stud->email, s);
        //printf("xd\n");
    }

    return glowa;
}
Przedmiot *wczytaj_przedmioty(FILE *fin)
{
    char bufor[255];
    int n, i;
    char *s;
    Przedmiot *last_przedmiot = NULL;
    Przedmiot *glowa = NULL;
    fgets(bufor, 254, fin);
    sscanf(bufor, "%d", &n);

    for (i = 0; i < n; i++)
    {
        Przedmiot *stud = (Przedmiot *)malloc(sizeof(Przedmiot));
        stud->next = NULL;

        if (last_przedmiot == NULL)
            glowa = stud;
        else
            last_przedmiot->next = stud;
        last_przedmiot = stud;

        fgets(bufor, 254, fin);
        s = strtok(bufor, ";");
        stud->kod = (char *)malloc(sizeof(char) * (strlen(s) + 1));
        strcpy(stud->kod, s);

        s = strtok(NULL, ";");
        stud->nazwa = (char *)malloc(sizeof(char) * (strlen(s) + 1));
        strcpy(stud->nazwa, s);

        s = strtok(NULL, "\n");
        stud->semestr = (char *)malloc(sizeof(char) * (strlen(s) + 1));
        strcpy(stud->semestr, s);
    }
    return glowa;
}
Ocena *wczytaj_oceny(FILE *fin)
{

    char bufor[255];
    int n, i;
    char *s;
    Ocena *last_ocena = NULL;
    Ocena *glowa = NULL;
    fgets(bufor, 254, fin);
    sscanf(bufor, "%d", &n);

    for (i = 0; i < n; i++)
    {
        Ocena *o = (Ocena *)malloc(sizeof(Ocena));
        o->next = NULL;

        if (last_ocena == NULL)
            glowa = o;
        else
            last_ocena->next = o;
        last_ocena = o;

        fgets(bufor, 254, fin);

        s = strtok(bufor, ";");
        o->kod_przedmiotu = (char *)malloc(sizeof(char) * (strlen(s) + 1));
        strcpy(o->kod_przedmiotu, s);

        s = strtok(NULL, ";");
        o->nr_albumu = (char *)malloc(sizeof(char) * (strlen(s) + 1));
        strcpy(o->nr_albumu, s);

        s = strtok(NULL, ";");
        o->ocena = atof(s);

        s = strtok(NULL, "\n");
        o->komentarz = (char *)malloc(sizeof(char) * (strlen(s) + 1));
        //printf("%s\n", s);
        strcpy(o->komentarz, s);
    }

    return glowa;
}

SBaza *wczytaj_baze(char *nazwa_pliku)
{
    FILE *fin = fopen(nazwa_pliku, "r");
    if (fin == NULL)
    {
        printf("BŁĄD! Nie moge otworzyc pliku: %s.\n", nazwa_pliku);
        exit(-1);
    }

    //printf("xd\n");
    SBaza *baza = (SBaza *)malloc(sizeof(SBaza));
    //printf("xd\n");
    baza->lista_studentow = wczytaj_studentow(fin);
    //printf("xd\n");
    baza->lista_przedmiotow = wczytaj_przedmioty(fin);
    //printf("xd\n");
    baza->lista_ocen = wczytaj_oceny(fin);
    //printf("xd\n");
    fclose(fin);
    return baza;
}

void zapisz_baze(char *nazwa_pliku, SBaza *baza)
{
    FILE *fin = fopen(nazwa_pliku, "w+");
    fprintf(fin, "%d\n", ile_studentow(baza));

    Student *stud = baza->lista_studentow;
    Przedmiot *p = baza->lista_przedmiotow;
    Ocena *o = baza->lista_ocen;

    for (int i = 0; i < ile_studentow(baza); i++)
    {
        fprintf(fin, "%s;%s;%s;%s\n", stud->imie, stud->nazwisko, stud->nr_albumu, stud->email);
        stud = stud->next;
    }

    fprintf(fin, "%d\n", ile_przedmiotow(baza));
    //printf("ile przedmiotow =%d\n", ile_przedmiotow(baza));
    for (int i = 0; i < ile_przedmiotow(baza); i++)
    {
        fprintf(fin, "%s;%s;%s\n", p->kod, p->nazwa, p->semestr);
        p = p->next;
    }

    fprintf(fin, "%d\n", ile_ocen(baza));
    for (int i = 0; i < ile_ocen(baza); i++)
    {
        fprintf(fin, "%s;%s;%4.2f;%s\n", o->kod_przedmiotu, o->nr_albumu, o->ocena, o->komentarz);
        o = o->next;
    }
    fclose(fin);
}

int ile_studentow(SBaza *baza)
{
    int n = 0;
    Student *stud = baza->lista_studentow;
    while (stud != NULL)
    {
        n++;
        stud = stud->next;
    }
    return n;
}
int ile_ocen(SBaza *baza)
{
    int n = 0;
    Ocena *o = baza->lista_ocen;
    while (o != NULL)
    {
        n++;
        o = o->next;
    }
    return n;
}
int ile_przedmiotow(SBaza *baza)
{
    int n = 0;
    Przedmiot *p = baza->lista_przedmiotow;
    while (p != NULL)
    {
        n++;
        p = p->next;
    }
    return n;
}

void listuj_studentow(SBaza *baza)
{
    Student *stud = baza->lista_studentow;
    while (stud != NULL)
    {
        printf("%s %s %s %s\n", stud->imie, stud->nazwisko, stud->nr_albumu, stud->email);
        stud = stud->next;
    }
}
void listuj_przedmioty(SBaza *baza) {
    Przedmiot * stud = baza->lista_przedmiotow;
    while (stud != NULL) {
        printf("%s %s %s \n", stud->kod, stud->nazwa, stud->semestr);
        stud = stud->next;
    }
}
void listuj_oceny(SBaza *baza) {
    Ocena * stud = baza->lista_ocen;
    while (stud != NULL) {
        printf("%s %s %f %s \n", stud->kod_przedmiotu, stud->nr_albumu, stud->ocena, stud->komentarz);
        stud = stud->next;
    }
}

void add_student(SBaza *baza, char *imie, char *nazwisko, char *nr_albumu, char *email)
{
    Student *new = (Student *)malloc(sizeof(Student));
    Student *present = baza->lista_studentow;
    new->next = NULL;
    new->imie = (char *)malloc(sizeof(char) * (strlen(imie) + 1));
    strcpy(new->imie, imie);
    
    new->nazwisko = (char *)malloc(sizeof(char) * (strlen(nazwisko) + 1));
    strcpy(new->nazwisko, nazwisko);

    new->nr_albumu = (char *)malloc(sizeof(char) * (strlen(nr_albumu) + 1));
    strcpy(new->nr_albumu, nr_albumu);

    new->email = (char *)malloc(sizeof(char) * (strlen(email) + 1));
    strcpy(new->email, email);
    //printf("xa\n");
    if (ile_studentow(baza) == 0)
    {
        baza->lista_studentow = new;
        //printf("xb\n");
    }
    else
    {
        //printf("xc\n");
        for (int i = 1; i < ile_studentow(baza); i++)
        {
            present = present->next;
        }
        present->next = new;
    }
}
void add_subject(SBaza *baza, char *kod, char *nazwa, char *semestr)
{
    Przedmiot *new = (Przedmiot *)malloc(sizeof(Przedmiot));
    Przedmiot *present = baza->lista_przedmiotow;
    new->next = NULL;
    new->kod = (char *)malloc(sizeof(char) * (strlen(kod) + 1));
    strcpy(new->kod, kod);

    new->nazwa = (char *)malloc(sizeof(char) * (strlen(nazwa) + 1));
    strcpy(new->nazwa, nazwa);

    new->semestr = (char *)malloc(sizeof(char) * (strlen(semestr) + 1));
    strcpy(new->semestr, semestr);

    if (ile_przedmiotow(baza) == 0)
        baza->lista_przedmiotow = new;
    else
    {
        for (int i = 1; i < ile_przedmiotow(baza); i++)
            present = present->next;

        present->next = new;
    }
}
void zwolnij_student(Student *s)
{
    free(s->imie);
    free(s->nazwisko);
    free(s->nr_albumu);
    free(s->email);
    free(s);
}
void zwolnij_liste_studentow(Student *s)
{
    Student *n;
    while (s != NULL)
    {
        n = s->next;
        zwolnij_student(s);
        s = n;
    }
}
void zwolnij_przedmiot(Przedmiot *s)
{
    free(s->kod);
    free(s->nazwa);
    free(s->semestr);
    free(s);
}
void zwolnij_liste_przedmiotow(Przedmiot *s)
{
    Przedmiot *n;
    while (s != NULL)
    {
        n = s->next;
        zwolnij_przedmiot(s);
        s = n;
    }
}
void zwolnij_ocene(Ocena *s)
{
    free(s->nr_albumu);
    free(s->kod_przedmiotu);
    free(s->komentarz);
    free(s);
}
void zwolnij_liste_ocen(Ocena *s)
{
    Ocena *n;
    while (s != NULL)
    {
        n = s->next;
        zwolnij_ocene(s);
        s = n;
    }
}

void zwolnij(SBaza *baza)
{
    zwolnij_liste_studentow(baza->lista_studentow);
    zwolnij_liste_przedmiotow(baza->lista_przedmiotow);
    zwolnij_liste_ocen(baza->lista_ocen);
    free(baza);
}