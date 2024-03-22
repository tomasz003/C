#include <stdio.h>
#include <stdlib.h>

typedef struct element{
   struct element *poprz;
   int wartosc;
   struct element *nast;
} element;

typedef struct Lista{
   element *glowa;
   element *ogon;
} Lista;

Lista *UtworzLista( void );
element *UtworzElement( int x );
void WstawNaLista( element *wstawiany, element *za_ktory );

int main(){
   Lista *L = UtworzLista();
   element *E = UtworzElement( 4 );
   return 0;
}

Lista *UtworzLista( void ){
   Lista *nowa = (Lista*)malloc( sizeof(Lista) );
   if( !nowa ){
      printf( "Problem przy tworzeniu listy." );
      return NULL;
   }
   nowa->glowa = (element*)malloc( sizeof(element) * 2 );
   if( !nowa->glowa ){
      printf( "Problem przy tworzeniu straznikow." );
      free( nowa );
      return NULL;
   }
   nowa->ogon = nowa->glowa + 1;
   nowa->glowa->nast = nowa->ogon;
   nowa->ogon->poprz = nowa->glowa;
   return nowa;
}

element *UtworzElement( int x ){
   element *nowy = (element*)malloc( sizeof(element) );
   if( !nowy ){
      printf( "Problem przy tworzeniu elementu." );
      return NULL;
   }
   nowy->wartosc = x;
   nowy->nast = NULL;
   nowy->poprz = NULL;
   return nowy;
}

void WstawNaLista( element *wstawiany, element *za_ktory ){
   if( !wstawiany || !za_ktory )
      return;

//   wstawiany->poprz = za_ktory->nast->poprz;
   wstawiany->poprz = za_ktory;
   wstawiany->nast = za_ktory->nast;
   za_ktory->nast = wstawiany;
   wstawiany->nast->poprz = wstawiany;
}
