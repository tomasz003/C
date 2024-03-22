#include <stdio.h>
#include <stdlib.h>

int NWD(int a, int b);

int main(){
    int *tab;
    int n;
    printf("Kochany widzu podaj integer: ");
    scanf("%d", &n);

    //dynamiczne allocowanie tablicy n-elementowej
    tab=(int*)malloc(n*sizeof(int));
    for(int i=0; i<n; i++){
        printf("Podaj element nr %d: ", i+1);
        scanf("%d", &tab[i]);
    }
    //NWD
    int nwd=tab[0];
    for(int i=0; i<n; i++){
        nwd=NWD(nwd, tab[i]);
    }
    printf("NWD wyrazow ciagu: %d", nwd);
    return 0;
}

int NWD(int a, int b){
    if(a>b){
        int x;
        x=a;
        a=b;
        b=x;
    }
    
    int NWD=1;
    for(int i=2; i<a+1; i++){
        if(b%i==0 && a%i==0) NWD=i;
    }
    return NWD;
}