#include <stdio.h>
#include <stdlib.h>

int main(){

int suma_kwadratow=0;
int suma=0;

for(int i=1; i<101; i++){
    suma_kwadratow=suma_kwadratow+i*i;
    }

for(int i=1; i<101; i++){
    suma=suma+i;
    }

printf("%d", suma_kwadratow);
printf("\n%d", suma*suma);
printf("\n%d", suma*suma-suma_kwadratow);

return 0;
}