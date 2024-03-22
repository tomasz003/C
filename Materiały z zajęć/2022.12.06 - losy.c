#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void funkcja();

int main(){
   srand( time( NULL ) );

//   rand() // {0, 1, ..., RAND_MAX}
printf("%d\n", RAND_MAX);

   // [a, b]  - dlugość b-a
   // [0, RAND_MAX] <- +a -> [a, RAND_MAX+a] <-  ->
   // [0, RAND_MAX] <- /(RAND_MAX + 1.)  *(b-a) +a -> [a,b)
   double a = -3.1415, b = 3.14;
   double pomoc;
   for( int i=0; i<10; ++i){
      pomoc = rand() / (RAND_MAX + 1.) * (b-a) + a;
      printf("%f\t: %f\t: %f\n", a, pomoc, b );
   }

   // [a,b] - całkowite
   // [0, RAND_MAX] <- %(b-a+1) +a -> [a,b]

   int A=-12, B=45;
   int pom;
   for( int i=0; i<10; ++i){
      pom = rand()%(B-A+1) + A;
      printf("%d : %d : %d\n", A, pom, B );
   }
   funkcja();
   return 0;
}

void funkcja(){
   // [ilość_znaków] losujemy z przedziału [7, 50]
   // losujemy [liczbę] z {1,... ,6}
   // jak jest parzysta to bierzemy znak '+'
   // jak nie parzysta to znak '-'
   // jak jest podzielna przez 4 to [ilość_znaków] x2
   // jak jest podzielna przez 5 to [ilość_znaków] -5

   // wypisujemy odpowiedni znak [ilość_znaków] razy
   // na ekranie w jednej linijce

   // losujemy tyle razy ile razy użytkownik chce

   int ile_razy;
   printf( "Podaj ile linijek: " );
   scanf( "%d", &ile_razy );
   int liczba, ilosc_znakow;
   char znak;
   for( int i = 0; i < ile_razy; ++i ){
      liczba = rand() % 6 + 1;
      ilosc_znakow = rand() % 43 + 7;
      if( liczba % 2 )
         znak = '-';
      else
         znak = '+';
      if( liczba % 4 == 0 )
         ilosc_znakow *= 2;
      if( ! liczba % 5 )
         ilosc_znakow -= 5;
      printf( "\n" );
      for( int j = 0; j < ilosc_znakow; ++j )
         printf( "%c", znak );
   }

}
