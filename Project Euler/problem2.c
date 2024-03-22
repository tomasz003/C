#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long long int fib(int n);

int main(){
    long long int suma=0;
    int a=1;

    while(fib(a)<4000001)
    {
        if (fib(a)%2==0){
            printf("%d. wyraz ( %lli ) jest parzysty\n", a, fib(a));
            suma=suma+fib(a);
        }
        a++;
    }
printf("suma: %lli", suma);
    return 0;
}


    long long int fib(int n){
        switch (n)
        {
        case 1:
            return 1;
        case 2:
            return 2;
        default:
            return (fib(n-1)+fib(n-2));
        }

    }
