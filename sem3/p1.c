#include<stdio.h>
#include<stdlib.h>


// W plikach nagłówkowych *.h jest DEKLARACJA funkcji 
// W bibliotece wspoldzielonej jest DEFINICJA funckji

int main(int argc, char*argv[]){
    //unsigned int - całkowita dodatnia lub 0
    float v;
    float a1;
    float a2;
    //a1=atof(argv[1]);
    //a2=atof(argv[2]);
    a1=atof("12.3");
    a2=atof("0.4");
    v=a1+a2;
    printf("[%s] Suma: %f\n",argv[0], v);
}