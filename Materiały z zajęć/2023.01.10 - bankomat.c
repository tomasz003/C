#include <stdio.h>
#include <stdlib.h>

// zawartosc.txt
// Zawiera jedn� linijk� zawieraj�c� 6 liczb naturalnych
// (0 te� zaliczamy do naturalnych)
// oznacaj�cych liczb� kolejnych nomina��w: 10, 20, 50, 100, 200, 500,
// kt�re znajduj� si� w bankomacie

// Napisz program, kt�ry wczyta plik zawartosc.txt
// Nast�pnie zapyta u�ytkownika jak� kwot� wyp�aci�.
// Program ma wy�wietli� jakimi nomina�ami (nomina� - ilo��)
// mo�na wyp�aci� kwot�.
// ( Nale�y zu�y� jak najmniej nomina��w! )

int main(){
   int nominaly[6][3] = { {10}, {20}, {50}, {100}, {200}, {500} };
   FILE *zawartosc = fopen( "zawartosc.txt", "r" );
   if( !zawartosc )
      exit(1);
   for( int i = 0; i < 6; ++i )
      fscanf( zawartosc, "%d", &nominaly[i][1] );
   fclose( zawartosc );
   zawartosc = NULL;

   int kwota;
   printf( "Podaj kwote do wyplaty: " );
   scanf( "%d", &kwota );

   for( int i = 5; i > -1; --i ){
      nominaly[i][2] = kwota / nominaly[i][0];
      if( nominaly[i][1] < nominaly[i][2] )
         nominaly[i][2] = nominaly[i][1];
      nominaly[i][1] -= nominaly[i][2];
      kwota -= nominaly[i][0] * nominaly[i][2];
   }
   if( kwota == 0 ){
      printf( "Wyplata: \n" );
      for( int i = 0; i < 6; ++i ){
         printf( "%d x %dPLN\n", nominaly[i][2], nominaly[i][0] );
      }
   }
   else{
      printf( "Wyplata niemozliwa." );
   }
   return 0;
}

