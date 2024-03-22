#include <stdio.h>
#include <stdlib.h>

int liczba_dzielnikow(int n);

int main(){
    int n=1;
    while(liczba_dzielnikow((n*(n+1))/2)<501){
    n++;}

    printf("\nSzukana liczba to %d", (n*(n+1))/2);

    return 0;
}

int liczba_dzielnikow(int n){
    int counter = 2;
    
    for (int i = 2; i < n; i++)
    {
        if (n%i==0)
        {
            counter++;
        }
        
    }
    
    return counter;
}

