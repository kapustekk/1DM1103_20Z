#include "baza.h"
Ocena * usun_ocena(Ocena *glowa, Ocena *el) {
    Ocena *c = glowa;
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

Ocena * najwiekszy_ocena(Ocena *el) {
    Ocena * max = NULL;
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

Ocena * sortuj_ocena_przez_wybieranie(Ocena *glowa) {
    Ocena * nglowa = NULL;
    Ocena * m;
    Ocena * o; // = NULL;

    while (glowa != NULL) {
        m = najwiekszy_ocena(glowa);
        glowa = usun_ocena(glowa, m);
        
        o = ostatni_ocena(nglowa);
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
Ocena * zwroc_ocena(Ocena *glowa, int i) {
    while (glowa != NULL && i-- > 0) // i jest zmniejszany postfixowo - czyli po porownaniu z 0
        glowa = glowa->next;    
    
    return glowa;
}
void listuj_oceny_od_konca(SBaza *b) {
    // Ocena *ogon = ostatni(b->lista_Ocenaow);
    Ocena *c;
    /*
    while (c != null) {

        c = c->poprz;
    }
    */
    // for (c=ogon; c != NULL; c = c->poprz) {
    //     printf("%s %s %s %s\n", c->imie, c->nazwisko, c->nr_albumu, c->email);        
    // }

    int i;
    int n = ile_Ocenaow(b);
    for (i=(n-1); i >= 0; i--) {
        c = zwroc_ocena(b->lista_Ocenaow, i);
        printf("%s %s %s %s\n", c->imie, c->nazwisko, c->nr_albumu, c->email);        
    }
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
        o->ocena = atof(s);

        s = strtok(NULL, "\n");
        o->komentarz = (char *)malloc(sizeof(char) * (strlen(s) + 1));
        //printf("%s\n", s);
        strcpy(o->komentarz, s);
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