#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *plik_f = fopen("plik_do_pisania_f.txt", "r");
    if(!plik_f) exit(1);

    FILE *plik_g = fopen("plik_do_pisania_g.txt", "r");
    if(!plik_g) exit(1);

    FILE *plik_h = fopen("plik_do_pisania_h.txt", "w");
    if(!plik_h) exit(1);

    char pomoc_f[11];
    char pomoc_g[11];
    float wartosc_z_f;
    float wartosc_z_g;

    fscanf(plik_f, "%s", &pomoc_f);
    fscanf(plik_f, "%f", &wartosc_z_f);
    fscanf(plik_g, "%s", &pomoc_g);
    fscanf(plik_g, "%f", &wartosc_z_g);


    int przerwij=0;

    while(przerwij==0){
        if(wartosc_z_f<=wartosc_z_g){
            przerwij++;
            fprintf(plik_h, "%.2f\n", wartosc_z_f);
            fscanf(plik_f, "%s", &pomoc_f);
            if(fscanf(plik_f, "%f", &wartosc_z_f)==1) przerwij=0;
        }
        else{
            przerwij++;
            fprintf(plik_h, "%.2f\n", wartosc_z_g);
            fscanf(plik_g, "%s", &pomoc_g);
            if(fscanf(plik_g, "%f", &wartosc_z_g)==1) przerwij=0;
        }
        }

    //skonczyly sie liczby w ktoryms pliku - sprawdzmy w ktorym

    if((fscanf(plik_f, "%s", &pomoc_f))==1){
        fclose(plik_g);
        fprintf(plik_h, "%.2f\n", wartosc_z_f);

        while ((fscanf(plik_f, "%s", &pomoc_f))== 1){
            fscanf(plik_f, "%f", &wartosc_z_f);
            fprintf(plik_h, "%.2f\n", wartosc_z_f);
        }
    }
    else{
        fclose(plik_f);
        while ((fscanf(plik_g, "%s", &pomoc_g))== 1){
            fscanf(plik_g, "%f", &wartosc_z_g);
            fprintf(plik_h, "%.2f\n", wartosc_z_g);
        }
    }
    
    fclose(plik_h);
    return 0;
}
