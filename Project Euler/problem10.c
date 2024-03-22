#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int test_pierwszosci(int n);

long long int main(){

long long int suma=0;

    for (int i = 2; i < 2000000; i++)
    {
        if (test_pierwszosci(i)==1)
        {
            suma+=i;
        }

    }


printf("%lli", suma);
return 0;
}

int test_pierwszosci(int n){

    for(int i=2; i<floor(sqrt(n))+1; i++){
        if(n%i==0) return 0;
    }

return 1;
}
