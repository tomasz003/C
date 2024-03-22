#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int monogramy(char *tab1, char *tab2);

int main(){
        FILE *slownik=fopen("slownik.txt", "r");
    if(!slownik)
      exit(1);
    
    FILE *plik=fopen("pisan.txt", "w");
    if(!plik)
      exit(1);

    char slowo1[31];
    char slowo2[31];

    while(fscanf(slownik, "%d", &slowo1)*(fscanf(slownik, "%d", &slowo2)==1)){
        if(monogramy(slowo1, slowo2)==1)
            fprintf(plik, "%d, %d\n", slowo1, slowo2);
    }
    return 0;
}

int monogramy(char *tab1, char *tab2){
    if(strlen(tab1)!=strlen(tab2)) return 0;
    int roznice=0;
    for(int i=0; i<strlen(tab2); i++){
        if(tab1[i]!=tab2[i]) roznice++;
    }
    
    if(roznice==1) return 1;
    else return 0;
}
