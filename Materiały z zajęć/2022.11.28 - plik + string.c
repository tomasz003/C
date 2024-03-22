#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void szalenstwo( char wyraz[] );

int main(){
//   char nazwa_pliku[36];
//   gets( nazwa_pliku );
//   printf( "%s", nazwa_pliku );

   FILE *plik = fopen( "slownik.txt", "r" );
   if( !plik ){
      exit(1);
   }
   FILE *zapis = fopen( "kopia.txt", "w" );
   if( !zapis ){
      exit(1);
   }

   char wyraz[52];
   while( fscanf(plik, "%s", wyraz ) == 1 ){
      szalenstwo( wyraz );
      fprintf(zapis ,"%s\n", wyraz);
   }

//   char pierwszy[]={'a','s','d','\0'};
//   char drugi[]="drugi string";
//   char trzeci[40+1];
//   trzeci[0]='e';
//   trzeci[1]='e';
//   trzeci[2]='e';
//   trzeci[3]='\0';
//   char czwarty[30];
//   strcpy( czwarty, trzeci+1 );
//   char piaty[99]="";
//   strcat(piaty, pierwszy );
//   strcat(piaty, drugi );
//   strcat(piaty, trzeci );
//   strcat(piaty, czwarty );
//
//   printf("%s\n", pierwszy );
//   printf("%s\n", drugi );
//   printf("%s\n", trzeci );
//   printf("%s\n", czwarty );
//   printf("%s\n", piaty );
//   strlen(   )
   return 0;
}

// Przyk³ady
// Dla slowa:    ma daæ:
//  aba           AbA
//  abba          AbbA
//  abcba         AbCbA
//  abccba        AbCCbA
//
void szalenstwo( char wyraz[] ){
//   char znak= 'a';
//   znak = tolower( znak );
//   znak = toupper( znak );
// strlen( wyraz )
   for( int i = 0, j = strlen(wyraz) - 1; i <= j; ++i, --j){
      if( i % 2 == 0){
         wyraz[i] = toupper(wyraz[i]);
         wyraz[j] = toupper(wyraz[j]);
      }
      else{
         wyraz[i] = tolower(wyraz[i]);
         wyraz[j] = tolower(wyraz[j]);
      }
   }

}
