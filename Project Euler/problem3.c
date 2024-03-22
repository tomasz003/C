#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){

int a=60;
int najwiekszy_pierwszy_dzielnik=1;

    while(a>1){
        for(int i=2; i<a+1; i++){
            if(a%i==0){
                a=a/i;
                najwiekszy_pierwszy_dzielnik=i;
                break;
            }
        }
    }
    printf("slay");
    return najwiekszy_pierwszy_dzielnik;
}

