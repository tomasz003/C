#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void sortowanie(int tab[], int length);
void zamien(int *a, int *b);

int main(){

//tworzenie tablicy
int length=20;
int tab[length];
srand(time(NULL));

for(int i=0; i<length; i++)
    tab[i]=rand();

sortowanie(tab, length);

    return 0;
}

void zamien(int *a, int *b){
    int pomoc=*a;
    *a=*b;
    *b=pomoc;
}

void sortowanie(int tab[], int length){

    for(int step=0; step<length-1; step++){
        int min=step;
        for(int j=step+1; j<length; j++){
            if(tab[j]<tab[min])
                min=j;
        }

        zamien(&tab[min], &tab[step]);
    }

//drukowanie uporz¹dkowanej tablicy
    for(int i=0; i<length; i++)
        printf("%d\n", tab[i]);
}

