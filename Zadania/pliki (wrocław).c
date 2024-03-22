#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int test_wroclawski(char *tab);
int main(){
    FILE *slownik=fopen("slownik.txt", "r");
    if(!slownik)
        exit(1);

    FILE *wroclaw=fopen("wroclaw.txt", "w");
    if(!wroclaw)
        exit(1); 

    char slowo[31];

    while(fscanf(slownik, "%s", &slowo)==1){
        if(test_wroclawski(slowo)==1){
            fprintf(wroclaw, "%s\n", slowo);
        }
    }
return 0;
}

int test_wroclawski(char *tab){
    if(tab[0]==tab[strlen(tab)-1]) return 1;
    else return 0;
}