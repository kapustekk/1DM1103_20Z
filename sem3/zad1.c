#include<stdio.h>
#include<stdlib.h>

int main(int argc, char*argv[]){
float kwadrat;
float argument;
argument=atof(argv[1]);
kwadrat=argument*argument;
printf("Wartość %f do kwardratu to %f\n",argument ,kwadrat);
//  jeśli chciałbym przybliżyć wartość np do jednej cyfry po przecinkuu napisałbym:
//      printf("Wartość %.1f do kwardratu to %.1f\n",argument ,kwadrat);
}
