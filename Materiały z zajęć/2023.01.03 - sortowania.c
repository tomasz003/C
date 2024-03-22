#include <stdio.h>
#include <stdlib.h>

void sortowanie_wybieranie( int tab[], int n );
void sortowanie_wstawianie( int tab[], int n );

int main(){
   int tab[5]={5,4,3,2,1};
   sortowanie_wstawianie(tab,5);
   for(int i = 0; i<5; ++i)
      printf("%d ", tab[i]);
   return 0;
}

void sortowanie_wybieranie( int tab[], int n ){
   int pomoc;
   int min; // oznacza indeks najmniejszego elementu w danym obszarze
   for( int i = 0; i < n - 1; ++i ){
      min = i;
      for( int k = i + 1; k < n; ++k )
         if( tab[k] < tab[min] )
            min = k;
      pomoc = tab[min];
      tab[min] = tab[i];
      tab[i] = pomoc;
   }
}

void sortowanie_wstawianie( int tab[], int n ){
   int pomoc, k;
   for( int i = 1; i < n; ++i ){
      pomoc = tab[i];
      k = i - 1;
      while( k >= 0 && tab[k] > pomoc ){
         tab[k+1] = tab[k];
         k--;
      }
      tab[k+1] = pomoc;
   }
}
