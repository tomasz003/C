#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int test_ch(char *tab);
int test_h(char *tab);

int main(){

//otwarcie pliku do czytania i pisania
FILE *slownik=fopen("slownik.txt", "r");
if(!slownik)
    exit(1);

FILE *pisanko_ch=fopen("pisanko_ch.txt", "w");
if(!pisanko_ch)
    exit(1);

FILE *pisanko_h=fopen("pisanko_h.txt", "w");
if(!pisanko_h)
    exit(1);

//sprawdzanie, czy kazde slowo ma CH i/lub H
char slowo[31];
while(fscanf(slownik, "%s", &slowo)==1){
    if(test_ch(slowo)==1)
        fprintf(pisanko_ch, "%s\n", slowo);
    if(test_h(slowo)==1)
        fprintf(pisanko_h, "%s\n", slowo);
}

//zamkniecie plikow
fclose(slownik);
fclose(pisanko_ch);
fclose(pisanko_h);
return 0;
}

//funkcja testująca warunek CH
int test_ch(char *tab){
    for(int i=0; i<strlen(tab); i++){
        if(tab[i]=='C'&& tab[i+1]=='H')
        return 1;
    }
return 0;
}

//funkcja testująca warunek H
int test_h(char *tab){
    for(int i=0; i<strlen(tab); i++){
        if(tab[i]!='C'&& tab[i+1]=='H')
        return 1;
    }
return 0;
}

