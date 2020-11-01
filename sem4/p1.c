#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void nawielkie(char * n) 
{
    for (int i=0; i< strlen(n); i++)
        n[i] = toupper(n[i]);
}
        
int main(int argc, char *argv[]) 
{
    char napis[255];
    printf("%s ma dlugosc: %ld\n", argv[1], strlen(argv[1]));
    strncpy(napis, argv[2], 254);
    nawielkie(napis);
    printf("%s ma dlugosc: %ld\n", napis, strlen(napis));
    return 0;
    
}

//-------------------WERSJA ALTERNATYWNA--------------------------
    //  #include <stdio.h>
    //  #include <stdlib.h>
    //  
    //  // int dlugosc_napisu(char napis[]) {
    //  int dlugosc_napisu(char *napis) {
    //      // printf("Pierwszy znak napisu: %c\n", napis[0]);
    //  //    int l;
    //  //    for (l=0; napis[l] != 0; l++) {
    //  //    }
    //  //        
    //  
    //      int l = 0;
    //      while (napis[l] != 0) 
    //          l++;
    //      return l;
    //  }
    //  
    //  void skopiuj(char *gdzie, char *co, int max) {
    //      int i=0;
    //      while ((co[i] != 0) && (i<max)) {
    //          gdzie[i] = co[i];
    //          i++;
    //      }
    //      gdzie[i] = 0;
    //  }
    //  
    //  /**
    //  * Zwraca -1 gdy nie znajdzie znaku w napisie.
    //  */
    //  int znajdz(char z, char *n) {
    //      int i = 0;
    //      int max = dlugosc_napisu(n);
    //  
    //      while ( (z != n[i]) && (i < max) )
    //          i++;
    //      
    //      // albo i<max? - wtedy znalazlem znak z i jest on na itej pozycji w n
    //      // albo i==max - wtedy po prostu nie znalazlem znaku z w n
    //  
    //      if (i<max)
    //          return i;
    //      else
    //          return -1;
    //  }
    //  
    //  void nawielkie(char * n) {
    //      char *male = "abcdefghijklmnopqrstuvwxyz";
    //      char *duze = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    //      int i,j;
    //  
    //      for (i=0; i< dlugosc_napisu(n); i++) {
    //          j = znajdz(n[i], male);
    //          if (j >= 0)
    //              n[i] = duze[j];
    //      }
    //  }
    //  
    //  // cel: napisać samemu funkcje:
    //  // 1. ktora zwroci dlugosc napisu (liczbe znakow)
    //  // 2. ktora skopiuje napis z jednego miejsca pamieci w drugie
    //  int main(int argc, char *argv[]) {
    //      char napis[255];
    //      printf("%s ma dlugosc: %d\n", argv[1], dlugosc_napisu(argv[1]));
    //  
    //      printf("Przed\n");
    //      skopiuj(napis, argv[2], 254);
    //      nawielkie(napis);
    //      printf("Po\n");
    //      printf("%s ma dlugosc: %d\n", napis, dlugosc_napisu(napis));
    //  
    //      return 0;
    //  }
    //  