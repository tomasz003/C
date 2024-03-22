#include <stdio.h>
#include <stdlib.h> // void* malloc(size_t)  void free(void*)
                    // void* realloc( void*, size_t)


typedef struct _Andrzej{
   int rozmiar;
   int *tab;
   int liczba;
} czynniki;

czynniki *rozklad( int liczba );
void wypisz_rozklad( czynniki *R );
void zniszcz( czynniki *R );

int main(){

   int liczba;
   printf("Podaj liczbe naturalna: ");
   scanf("%d", &liczba);
   czynniki *ro1 = rozklad( liczba );

   printf("Podaj druga liczbe naturalna: ");
   scanf("%d", &liczba);
   czynniki *ro2 = rozklad( liczba );

   wypisz_rozklad( ro1 );
   printf("\n");
   wypisz_rozklad( ro2 );

   zniszcz( ro1 );
   zniszcz( ro2 );

   return 0;
}

czynniki *rozklad( int liczba ){
   czynniki *wynik = (czynniki*)malloc( sizeof(czynniki) );
   if( !wynik ){
      printf("Nie udalo sie przygotowaæ struktury.");
      exit(1);
   }
   wynik->liczba = liczba;

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
   wynik->rozmiar = rozmiar;
   wynik->tab = tablica;
   return wynik;
}

void wypisz_rozklad( czynniki *R ){
   printf("%d = ", R->liczba );
   for( int i=0; i<R->rozmiar-1; ++i)
      printf("%d x ", R->tab[i]);
   printf("%d", R->tab[R->rozmiar-1]);
}

void zniszcz( czynniki *R ){
   free( R->tab );
   free( R );
}
