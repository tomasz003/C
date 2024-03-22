#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int test_pierwszosci(int n);

int main(){
int counter=1;
int n=3;

while(counter<10001){
    if(test_pierwszosci(n)==1){
        counter++;
    }
n++;
}

printf("\nLiczba pierwsza %d dla n = %d", n-1, counter);
    return 0;
}

int test_pierwszosci(int n){

    for(int i=2; i<floor(sqrt(n))+1; i++){
        if(n%i==0) return 0;
    }

return 1;
}
