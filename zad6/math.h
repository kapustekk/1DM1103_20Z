typedef struct _Macierz {
    int r;
    int c;
    float **tab;
}Macierz;

float norm(Macierz *m);
Macierz* suma_macierzy(Macierz *ma, Macierz *mb);
float suma_elementow(Macierz *m);
Macierz* pomnoz_skalar(int k, Macierz *m);
Macierz *iloczyn(Macierz *a, Macierz *b);
Macierz *odejmij(Macierz *ma, Macierz *mb);