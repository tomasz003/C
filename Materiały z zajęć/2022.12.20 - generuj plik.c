#include <stdio.h>
#include <stdlib.h>

float f( float x ){ return x; }
float g( float x ){ return x * x * x; }

// funkcja która otrzyma przedział, liczbę odcinków, nazwę pliku i funkcję (wskaźnik na funkcję)
// a będzie odpowiadać za wygenerowanie pliku
void generator_pliku( float a, float b, int n, char nazwa[], float (*funkcja)(float) );

int main(){
   float af = -12.34, bf = 3.14;
   int liczba_odcinkow = 230;

   float ag= -11.4, bg = -1;
   int liczba_G = 350;

   FILE *zapis = fopen( "f.txt", "w" );
   if( !zapis )
      exit( 1 );
   fprintf( zapis, "%d\n", liczba_odcinkow );
   float x_n;
   float delta = ( bf - af ) / liczba_odcinkow;
   for( int i = 0; i <= liczba_odcinkow; ++i ){
      x_n = af + i * delta;
      fprintf( zapis, "%.2f %.2f\n", x_n, f( x_n ) );
   }
   fclose( zapis );

   // nazwa funkcji jest wskaźnikiem na tę funkcję
   generator_pliku( ag, bg, liczba_G, "g.txt", g );

   return 0;
}

void generator_pliku( float a, float b, int n, char nazwa[], float (*funkcja)(float) ){
   FILE *zapis = fopen( nazwa, "w" );
   if( !zapis )
      exit( 1 );
   fprintf( zapis, "%d\n", n );
   float x_n;
   float delta = ( b - a ) / n;
   for( int i = 0; i <= n; ++i ){
      x_n = a + i * delta;
      fprintf( zapis, "%.2f %.2f\n", x_n, funkcja( x_n ) );
   }
   fclose( zapis );
}