#include <stdio.h>

long long ciag( int n );

int main(){
   
   int wyraz;
   printf( "Podaj indeks: " );
   scanf( "%d", &wyraz );
   printf( "%lld", ciag(wyraz) );
   return 0;
}

long long ciag( int n ){
   if( n == 1 )
      return 4;
   else if( n == 2 )
      return 5;
   switch( n % 3 ){
      case 0:
         return ciag( n - 1 ) + ciag( n - 2 );
      case 1:
         return ciag( n - 2 ) / 2;
      case 2:
         return ciag( n - 1 ) - 5;
   }
}
