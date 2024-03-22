#include <stdio.h>
#include <stdlib.h>

int *rozklad(int n, int *rozmiar);

int main(){
    int n, m;
    printf("Podaj liczby do rozkladu: \n");
    scanf("%d", &n);
    scanf("%d", &m);
    printf("Wybrane liczby: %d, %d.\n",n,m);

    int r1;                                         //rozmiar tablicy nr 1
    int *czynniki1 = rozklad(n, &r1);
    int r2;                                         //rozmiar tablicy nr 2
    int *czynniki2 = rozklad(m, &r2);

        printf("%d=",n);
    for (int i = 0; i <r1-1; ++i){
        printf("%d*", czynniki1[i]);
    }
        printf("%d", czynniki1[r1-1]);

    printf("\n%d=",m);
    for (int i = 0; i <r2-1; ++i){
        printf("%d*", czynniki2[i]);
    }
        printf("%d", czynniki2[r2-1]);

    //NWD
    int NWD=1;
    for (int j = 0; j < r1; j++)
    {
        for (int i = 0+j; i < r2; i++)
        {
            if (czynniki1[i]==czynniki2[j]){
                NWD=NWD*czynniki1[i];
                break;
            }
        }
        
    }
    printf("\nNWD tych liczb to %d.", NWD);
    
    //NWW
    int NWW=m*n/NWD;
    printf("\nNWW tych liczb to %d.", NWW);

    return 0;   
}

int *rozklad(int n, int *rozmiar){                   //funkcja
    int roz=0;
    int *czynniki = (int*)malloc(sizeof(int)*roz);
    int *pomoc = NULL;

    int k=2;
    while(k<=n){
        if(n%k==0){
            ++roz;
            pomoc = (int*)realloc(czynniki, sizeof(int)*roz);
            if(pomoc==NULL){
                printf("Problemy przy rozszerzaniu tablicy czynników");
                exit(1);
            }
            czynniki = pomoc;
            czynniki[roz-1]=k;
            n/=k;
        }
        else
            ++k;
        
    }
    pomoc=NULL;

    *rozmiar=roz;
    return czynniki;

   
}