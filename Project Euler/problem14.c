#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int colattz_powtorzenia(long long int n);

long long int main(){
long long int max=0;
int f_max=0;

for(long long int i=1; i<1000000; i++){
    //printf("\n\n%lli: %lli\n\n", i, colattz_powtorzenia(i));
    if(colattz_powtorzenia(i)>f_max){
      f_max=colattz_powtorzenia(i);
      max=i;
      }
}
printf("f(%lli) = %d", max, f_max);
return max;
}
int colattz_powtorzenia(long long int n){
int counter=0;

while(n>1){
    if(n%2==0){
        //printf("%d p-> ", n);
        n=n/2;
    }
    else{
        //printf("%d n-> ", n);
        n=3*n+1;
    }
    counter++;
}
return counter;
}
