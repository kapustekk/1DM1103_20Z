#include<stdio.h>
#include<stdlib.h>

int main(int argc, char*argv[]){
    //unsigned int - całkowita dodatnia lub 0
    float v;
    float a1;
    float a2;
    a1=atof(argv[1]);
    a2=atof(argv[2]);
    v=a1+a2;
    printf("[%s] Suma: %f\n",argv[0], v);
}