#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void sortowanie(int tab[], int length);
int main(){

int length=15;
int tab[length];
srand(time(NULL));

for(int i=0; i<length; i++)
    tab[i]=rand();

sortowanie(tab, length);

    return 0;
}

void sortowanie(int tab[], int length){
    int i,j, step;
    for(int i=1; i<length; i++){
        step=tab[i];
        j=i-1;
        while(j>=0 && step<tab[j]){
            tab[j+1]=tab[j];
            j--;
        }
        tab[j+1]=step;
    }


    for(int i=0; i<length; i++)
        printf("%d\n", tab[i]);
}
