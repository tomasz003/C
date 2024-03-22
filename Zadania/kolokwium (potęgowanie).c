#include <stdio.h>
#include <stdlib.h>

int main(){
    double k,n;

    printf("Podaj liczbe calkowita (n): \n");
    scanf("%lf", &n);
    printf("Podaj liczbe calkowita (k): \n");
    scanf("%lf", &k);


    if(k==0 && n==0){
        printf("Nie da sie");
        return -1;
    }

    if(k==0){
        printf("Wynik potegowania: 1");
        return 0;
    }

    if(n==0){
        printf("Wynik potegowania: 0");
        return 0;
    }

    if(k<0){
        //printf("%lf  <-n", n);
        double odwrotnosc=1/n;
        k=-k;
        double wartosc_odwrotnosci=odwrotnosc;
        printf("%lf, %lf\n", odwrotnosc, wartosc_odwrotnosci);
        for (int i = 1; i < k; i++){

            odwrotnosc=odwrotnosc*wartosc_odwrotnosci;
            printf("%lf \n", odwrotnosc);
        }
        printf("Wynik potegowania: %lf", odwrotnosc);
        return 0;
    }
    else{
    double wartosc_n=n;
    for(int i=1; i<k; i++){
        n=n*wartosc_n;
    }
    printf("%lf", n);
    return 0;
    }
}
