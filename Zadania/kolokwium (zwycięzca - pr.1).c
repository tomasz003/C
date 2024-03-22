#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int zwyciezca(int tab[9][51], int n);
int main(){

int tab[9][51];
srand(time(NULL));

tab[0][0]=0;
for(int i=1; i<9; i++){
    tab[i][0]=i;
    for(int j=1; j<51; j++){
        tab[0][j]=0;
        tab[i][j]=rand();
    }
}

for(int i=0; i<9; i++){
    for(int j=0; j<51; j++){
        printf("%d, ", tab[i][j]);
    }
    printf("\n\n");
}

    return 0;
}

int zwyciezca(int tab[9][51], int n){
    int leader;
    int leader_points;
    for (int i = 1; i < 9; i++){
        int suma;
        for (int j = 1; j<51; j++){
            suma+=tab[i][j];
        }
        if(suma>leader_points)
            leader_points=suma;
            leader=i;
    }

    return leader;
}
