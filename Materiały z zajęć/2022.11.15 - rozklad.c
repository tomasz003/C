#include <stdio.h>
#include <stdlib.h> // void* malloc(size_t)  void free(void*)
                    // void* realloc( void*, size_t)

int main(){
   int liczba;
   printf("Podaj liczbe naturalna: ");
   scanf("%d", &liczba);

   int k=2;
   while( liczba > 1 ){
      if( liczba % k == 0 ){
         printf("%d*", k);
         liczba /= k;
      }
      else
         ++k;
   }


   return 0;
}
