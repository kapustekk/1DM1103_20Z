#include "baza.h"
//modyfikacja
Student * ostatni_stud(Student *glowa) {
    Student *el = glowa;
    if (el != NULL) {
        while (el->next != NULL)
            el = el->next;

        return el;
    } else
        return NULL;
}

Student * wczytaj_studentow(FILE *fin) {
    char bufor[255];
    int n, i;
    char *s;
    Student *glowa = NULL;
    fgets(bufor, 254, fin);
    sscanf(bufor, "%d", &n);
    Student *c;

    for (i=0; i<n; i++) {
        Student *stud = (Student*) malloc(sizeof(Student));
        stud->next = NULL;
        stud->poprz = NULL;

        if (glowa == NULL)
            glowa = stud;
        else {
            c = ostatni_stud(glowa);
            c->next = stud;
            stud->poprz = c;
        }

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
Przedmiot * ostatni_przed(Przedmiot *glowa) {
    Przedmiot *el = glowa;
    if (el != NULL) {
        while (el->next != NULL)
            el = el->next;

        return el;
    } else
        return NULL;
}
Przedmiot *wczytaj_przedmioty(FILE *fin)
{
    char bufor[255];
    int n, i;
    char *s;
    Przedmiot *glowa = NULL;
    fgets(bufor, 254, fin);
    sscanf(bufor, "%d", &n);
    Przedmiot *c;

    for (i = 0; i < n; i++)
    {
        Przedmiot *stud = (Przedmiot *)malloc(sizeof(Przedmiot));
        stud->next = NULL;
        stud->poprz = NULL;

        if (glowa == NULL)
            glowa = stud;
        else {
            c = ostatni_przed(glowa);
            c->next = stud;
            stud->poprz = c;
        }

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

Ocena * ostatnia_ocena(Ocena *glowa) {
    Ocena *el = glowa;
    if (el != NULL) {
        while (el->next != NULL)
            el = el->next;

        return el;
    } else
        return NULL;
}
Ocena *wczytaj_oceny(FILE *fin)
{

    char bufor[255];
    int n, i;
    char *s;
    Ocena *glowa = NULL;
    fgets(bufor, 254, fin);
    sscanf(bufor, "%d", &n);
    Ocena *c;

    for (i = 0; i < n; i++)
    {
        Ocena *o = (Ocena *)malloc(sizeof(Ocena));
        o->next = NULL;
        o->poprz = NULL;

        if (glowa == NULL)
            glowa = o;
        else {
            c = ostatnia_ocena(glowa);
            c->next = o;
            o->poprz = c;
        }
        fgets(bufor, 254, fin);

        s = strtok(bufor, ";");
        o->kod_przedmiotu = (char *)malloc(sizeof(char) * (strlen(s) + 1));
        strcpy(o->kod_przedmiotu, s);

        s = strtok(NULL, ";");
        o->nr_albumu = (char *)malloc(sizeof(char) * (strlen(s) + 1));
        strcpy(o->nr_albumu, s);

        s = strtok(NULL, ";");
        o->ocena = (char *)malloc(sizeof(char) * (strlen(s) + 1));
        strcpy(o->ocena, s);

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
        fprintf(fin, "%s;%s;%s;%s\n", o->kod_przedmiotu, o->nr_albumu, o->ocena, o->komentarz);
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
//dodane funkcje w ramach zad8 cz.2
//student


Student * usun_stud(Student *glowa, Student *el) {
    Student *c = glowa;
    if (glowa == el) {
        glowa = glowa->next;
    } else {
        while (c != NULL) {
            if (c == el) {
                c->poprz->next = c->next;
                if (c->next != NULL)
                    c->next->poprz = c->poprz;

                break;
            }

            c = c->next;
        }
    }
    c->next = NULL;
    c->poprz = NULL;
    return glowa;
}

Student * najwiekszy_stud(Student *el) {
    Student * max = NULL;
    while (el != NULL) {
        if (max == NULL) {
            max = el;
        } else {
            if ( strcmp(el->nazwisko, max->nazwisko) > 0 ) 
                max = el;
        }
        el = el->next;
    }
    return max;
}

Student * sortuj_stud_przez_wybieranie(Student *glowa) {
    Student * nglowa = NULL;
    Student * m;
    Student * o; // = NULL;

    while (glowa != NULL) {
        m = najwiekszy_stud(glowa);
        glowa = usun_stud(glowa, m);
        
        o = ostatni_stud(nglowa);
        if (o == NULL) {
            nglowa = m;
        } else {
            o->next = m;
            m->poprz = o;
        }
        // o = m;

        // printf("Najwiekszy: %s\n", m->nazwisko);
        // wypisz_rekurencyjnie(glowa);
    }

    return nglowa;
}
Student * zwroc_stud(Student *glowa, int i) {
    while (glowa != NULL && i-- > 0) // i jest zmniejszany postfixowo - czyli po porownaniu z 0
        glowa = glowa->next;    
    
    return glowa;
}
void listuj_studentow_od_konca(SBaza *b) {
    // Student *ogon = ostatni(b->lista_studentow);
    Student *c;
    /*
    while (c != null) {

        c = c->poprz;
    }
    */
    // for (c=ogon; c != NULL; c = c->poprz) {
    //     printf("%s %s %s %s\n", c->imie, c->nazwisko, c->nr_albumu, c->email);        
    // }

    int i;
    int n = ile_studentow(b);
    for (i=(n-1); i >= 0; i--) {
        c = zwroc_stud(b->lista_studentow, i);
        printf("%s %s %s %s\n", c->imie, c->nazwisko, c->nr_albumu, c->email);        
    }
}
//przedmiot
Przedmiot * usun_przed(Przedmiot *glowa, Przedmiot *el) {
    Przedmiot *c = glowa;
    if (glowa == el) {
        glowa = glowa->next;
    } else {
        while (c != NULL) {
            if (c == el) {
                c->poprz->next = c->next;
                if (c->next != NULL)
                    c->next->poprz = c->poprz;

                break;
            }

            c = c->next;
        }
    }
    c->next = NULL;
    c->poprz = NULL;
    return glowa;
}

Przedmiot * najwiekszy_kod_przed(Przedmiot *el) {
    Przedmiot * max = NULL;
    while (el != NULL) {
        if (max == NULL) {
            max = el;
        } else {
            if ( strcmp(el->kod, max->kod) > 0 ) 
                max = el;
        }
        el = el->next;
    }
    return max;
}

Przedmiot * sortuj_przed_po_kodach(Przedmiot *glowa) {
    Przedmiot * nglowa = NULL;
    Przedmiot * m;
    Przedmiot * o; // = NULL;

    while (glowa != NULL) {
        m = najwiekszy_kod_przed(glowa);
        glowa = usun_przed(glowa, m);
        
        o = ostatni_przed(nglowa);
        if (o == NULL) {
            nglowa = m;
        } else {
            o->next = m;
            m->poprz = o;
        }
    }

    return nglowa;
}
Przedmiot * najwieksza_nazwa_przed(Przedmiot *el) {
    Przedmiot * max = NULL;
    while (el != NULL) {
        if (max == NULL) {
            max = el;
        } else {
            if ( strcmp(el->nazwa, max->nazwa) > 0 ) 
                max = el;
        }
        el = el->next;
    }
    return max;
}

Przedmiot * sortuj_przed_po_nazwach(Przedmiot *glowa) {
    Przedmiot * nglowa = NULL;
    Przedmiot * m;
    Przedmiot * o; // = NULL;

    while (glowa != NULL) {
        m = najwieksza_nazwa_przed(glowa);
        glowa = usun_przed(glowa, m);
        
        o = ostatni_przed(nglowa);
        if (o == NULL) {
            nglowa = m;
        } else {
            o->next = m;
            m->poprz = o;
        }
    }

    return nglowa;
}
Przedmiot * zwroc_przed(Przedmiot *glowa, int i) {
    while (glowa != NULL && i-- > 0) // i jest zmniejszany postfixowo - czyli po porownaniu z 0
        glowa = glowa->next;    
    
    return glowa;
}
void listuj_przedmioty_od_konca(SBaza *b) {
    Przedmiot *c;

    int i;
    int n = ile_przedmiotow(b);
    for (i=(n-1); i >= 0; i--) {
        c = zwroc_przed(b->lista_przedmiotow, i);
        printf("%s %s %s \n", c->kod, c->nazwa, c->semestr);      
    }
}

int znalezione_kody(Ocena *glowao, char *kod_przedmiotu)
{
    int a=0;
    while(glowao!=NULL)
    {   
        if(strcmp(glowao->kod_przedmiotu, kod_przedmiotu)==0) 
        {
            a++;
        }
        glowao=glowao->next;
    }
    return a;
}

Ocena * filtruj_przedmiot(Ocena *glowao, char *kod_przedmiotu) {

    Ocena *glowa = NULL;
    Ocena *c=NULL;
    while(glowao!=NULL)
    {   
        if(strcmp(glowao->kod_przedmiotu, kod_przedmiotu)==0) 
        {
            Ocena *o = (Ocena *)malloc(sizeof(Ocena));
            o->next = NULL;
            o->poprz = NULL;
            if(glowa==NULL)
            glowa=o;
            else
            {
                // printf("cyk\n");
                c = ostatnia_ocena(glowa);
                ostatnia_ocena(glowa)->next = o;
                o->poprz = c;
                glowa=glowa->next;
            }
            // printf("kopiuje elementy\n");
            glowa->nr_albumu=glowao->nr_albumu;
            glowa->kod_przedmiotu=glowao->kod_przedmiotu;
            glowa->ocena=glowao->ocena;
            glowa->komentarz=glowao->komentarz;
            // printf("%s %s %s %s \n", glowa->kod_przedmiotu, glowa->nr_albumu, glowa->ocena, glowa->komentarz);
        }
        glowao=glowao->next;
    }
   
    return glowa;
}
int znalezione_albumy(Ocena *glowao, char *album)
{
    int a=0;
    while(glowao!=NULL)
    {   
        if(strcmp(glowao->nr_albumu, album)==0) 
        {
            a++;
        }
        glowao=glowao->next;
    }
    return a;
}

Ocena * filtruj_student(Ocena *glowao, char *album) {

    Ocena *glowa = NULL;
    Ocena *c=NULL;
    while(glowao!=NULL)
    {   
        if(strcmp(glowao->nr_albumu, album)==0) 
        {
            Ocena *o = (Ocena *)malloc(sizeof(Ocena));
            o->next = NULL;
            o->poprz = NULL;
            if(glowa==NULL)
            glowa=o;
            else
            {
                c = ostatnia_ocena(glowa);
                ostatnia_ocena(glowa)->next = o;
                o->poprz = c;
                glowa=glowa->next;
            }
            glowa->nr_albumu=glowao->nr_albumu;
            glowa->kod_przedmiotu=glowao->kod_przedmiotu;
            glowa->ocena=glowao->ocena;
            glowa->komentarz=glowao->komentarz;
        }
        glowao=glowao->next;
    }
   
    return glowa;
}
void wypisz_glowe_ocen(Ocena*glowa)
{
    printf("%s - %s - %s - %s \n", glowa->kod_przedmiotu, glowa->nr_albumu, glowa->ocena, glowa->komentarz);
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
        printf("%s %s %s %s \n", stud->kod_przedmiotu, stud->nr_albumu, stud->ocena, stud->komentarz);
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