#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Otwórz plik tekstowy i przepisz go do nowego pliku pozbywając się cyfr i odstępów,
// każdy wyraz kończący się literą ma kończyć się dużą literą

void wyrzuc_cyfry( char napis[], char wynik[] );
int main(){
   FILE *zrodlo = fopen( "zrodlo.txt", "r" );
   if( !zrodlo )
      exit( 1 );
   FILE *zapis = fopen( "wynik.txt", "w" );
   if( !zapis )
      exit( 1 );
   char napis[41], przetworzone[41];
   while( fscanf( zrodlo, "%s", napis ) == 1 ){
      wyrzuc_cyfry( napis, przetworzone );
      przetworzone[strlen( przetworzone ) - 1] = toupper( przetworzone[strlen( przetworzone ) - 1] );
      fprintf( zapis, "%s", przetworzone );
   }
   fclose( zrodlo );
   fclose( zapis );
   return 0;
}

void wyrzuc_cyfry( char napis[], char wynik[] ){
   int n = 0, w = 0;
   while( napis[n] ){
      if( !isdigit( napis[n] ) )
         wynik[w++] = napis[n];
      ++n;
   }
   wynik[w] = '\0';
}