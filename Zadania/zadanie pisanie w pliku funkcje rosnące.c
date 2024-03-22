#include <stdio.h>
#include <stdlib.h>

float f(float x){
    return x*x;
}

float g(float x){
    return 2*x+1;
}

int main(){
    float a1=1, b1=12.5;
    int liczba_pkt=200;
    float delta_x=(b1-a1)/liczba_pkt;

    FILE *plik_f = fopen("plik_do_pisania_f.txt", "w");
    if(!plik_f) exit(1);

    for (int i = 0; i < liczba_pkt+1; i++)
    {
        fprintf(plik_f, "a_%d, %.2f\n", i, f(a1+i*delta_x));
    }
    fclose(plik_f);

    FILE *plik_g = fopen("plik_do_pisania_g.txt", "w");
    if(!plik_g) exit(1);

    for (int i = 0; i < liczba_pkt+1; i++)
    {
        fprintf(plik_g, "a_%d, %.2f\n", i, g(a1+i*delta_x));
    }
    fclose(plik_g);

return 0;
}