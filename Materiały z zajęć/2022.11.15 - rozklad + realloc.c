#include <stdio.h>
#include <stdlib.h> // void* malloc(size_t)  void free(void*)
                    // void* realloc( void*, size_t)

int *rozklad( int liczba, int *rozm );

int main(){
   int liczba;
   printf("Podaj liczbe naturalna: ");
   scanf("%d", &liczba);

   int rozmiar;
   int *tablica = rozklad( liczba, &rozmiar );

   int l2 = 44;
   printf("Podaj druga liczbe naturalna: ");
   scanf("%d", &l2);
   int r2;
   int *ta2 = rozklad( l2, &r2 );

   for( int i=0; i<rozmiar-1; ++i)
      printf("%d x ", tablica[i]);
   printf("%d", tablica[rozmiar-1]);

   free( tablica );
   tablica=NULL;
   return 0;
}

int *rozklad( int liczba, int *rozm ){
   int rozmiar = 0; // aktualny rozmiar tablicy
   int *tablica = NULL, *pomoc=NULL;
   int k=2;
   while( liczba > 1 ){
      if( liczba % k == 0 ){
         ++rozmiar;
         pomoc = realloc(tablica, sizeof(int)*rozmiar);
         if( pomoc == NULL ){
            printf("Nie udalo sie poszerzyc tablicy.");
            exit(1);
         }
         tablica = pomoc;
         tablica[rozmiar-1] = k;
         liczba /= k;
      }
      else
         ++k;
   }
   pomoc=NULL;

   *rozm = rozmiar;
   return tablica;
}
