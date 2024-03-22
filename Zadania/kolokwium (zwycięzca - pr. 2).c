#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int zwyciezca(int tab[9][51], int n);
void kolejnosc(int tab[9][51], int n);
void zamien(int *a, int *b);
void sortowanie(int tab[9][2]);

int main(){
srand(time(NULL));

int n;
printf("Podaj liczbe sportow: ");
scanf("%d", &n);
printf("\n");


int tab[9][51];
tab[0][0]=0;
for(int i=1; i<9; i++){
    tab[i][0]=i;
    for(int j=1; j<n+1; j++){
        tab[0][j]=0;
        tab[i][j]=rand() %30;
    }
}

for(int i=1; i<9; i++){
    for(int j=0; j<n+1; j++){
        printf("%d, ", tab[i][j]);
    }
    printf("\n\n");
}

printf("zwyciezca: %d;\n\n", zwyciezca(tab, n));
kolejnosc(tab, n);
    return 0;
}

int zwyciezca(int tab[9][51], int n){
    int leader=0;
    int jeden_lider=1;
    int suma[9];    //suma punktow kazdej druzyny
    suma[0]=0;

//wpisujemy do tablicy "suma" sume punktow kazdej z druzyn
    for (int i = 1; i < 9; i++){
        suma[i]=0;
        for (int j = 1; j<n+1; j++){
            suma[i]+=tab[i][j];
        }
//sprawdzamy, czy i-ta druzyna powinna byc liderem i czy jest nim sama      
        if(suma[i]==suma[leader]){
            jeden_lider=0;
        }
        else if(suma[i]>suma[leader]){
            leader=i;
            jeden_lider=1;
        }
        
    }

    if(jeden_lider==1)
    return leader;
    else return 0;
}

void kolejnosc(int tab[9][51], int n){
    int sumy[9][2];
    //wypelnianie tablicy sum (element zerowy to nr druzyny)
    for (int i = 1; i < 9; i++){
        sumy[i][0]=i;
        sumy[i][1]=0;
        for (int j = 1; j < n+1; j++){
            sumy[i][1]+=tab[i][j];
        }
    }
/*      //sortowanie babelkowe
    for (int i = 1; i < 9; i++){
        for (int j = 2; j < 10-i; j++){
            if (sumy[j-1][1]<sumy[j][1]){
                zamien(&sumy[j-1][1], &sumy[j][1]);
                zamien(&sumy[j-1][0], &sumy[j][0]); 
            }
        }
    }
*/
    
    //sortowanie przez wybor
    for(int step=1; step<8; step++){
        int min=step;
        for(int j=step+1; j < 9; j++){
            if(sumy[j][1]>sumy[min][1])
                min=j;
        }
        zamien(&sumy[min][1], &sumy[step][1]);
        zamien(&sumy[min][0], &sumy[step][0]);
    }


    //drukowanie uporzadkowanej tablicy
    for (int i = 1; i < 9; i++){
    printf("%d. miejsce: %d, %d;\n", i, sumy[i][0], sumy[i][1]);
    }
    

}
void zamien(int *a, int *b){
   int pomoc=*a;
    *a=*b;
    *b=pomoc;  
}
void sortowanie(int tab[9][2]){

    for(int step=1; step<9-1; step++){
        int min=step;
        for(int j=step+1; j<9; j++){
            if(tab[j][1]>tab[min][1])
                min=j;
        }
        zamien(&tab[min][1], &tab[step][1]);
        zamien(&tab[min][0], &tab[step][0]);
    }
}