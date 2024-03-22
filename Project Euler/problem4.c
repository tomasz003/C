#include <stdio.h>
#include <stdlib.h>

int od_tylu(int x);

int main(){
    int max =0;

    for(int i=100; i<1000; i++){
        for (int j = 100; j < 1000; j++)
        {
            if(i*j==od_tylu(i*j) && i*j>max){
            max=i*j;
            }
        }
    }

    printf("%d", max);
    return 0;
}

int od_tylu(int x){
    int ski=0;

    while(x>9){
        ski=10*(ski+x%10);
        x=(x-x%10)/10;
    }

    ski=ski+x;

    return ski;
}