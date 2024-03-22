#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    
int sukces = 0;
for (int a = 1; a < 334; a++)
{
    for (int b = a; b < 500; b++)
    {
        if (a+b+sqrt(a*a+b*b)==1000){
            printf("%d", a);
            printf("\n%d", b);
            printf("\n%.0f", sqrt(a*a+b*b));              //%f - float, 6 miejsc po przecinku
            printf("\n%.0f", a*b*sqrt(a*a+b*b));
            sukces=1;
           //goto stop;
           }
    
    }
}

if (sukces==0)
   printf("aj");
//stop: 
return 0;
}