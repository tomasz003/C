#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int liczba_trojkatow(int x);

int main(){
    int max=0;
    int n=1;
/*
    while(n<15){
        if(liczba_trojkatow(n)>max)
            max=liczba_trojkatow(n);
    }
    
    printf("slay");
    printf("%d", max);
*/
    printf("%d", liczba_trojkatow(12));
    return 0;
}

int liczba_trojkatow(int x){
    int a = 1;
    int b = 1;
    float c;
    int counter=0;

    while(a<x){
    a=1;
        while (a<b)
    {
      c = x-a-b;
      if(c*c==a*a+b*b)
      {
        printf ("a = %d, b = %d, c = %.0lf\n",a,b,c);
        counter++;
      }
      a++;
    }

   b++;
  }
  printf("Liczba trojkatow dla %d to ", x);
  return counter;
}
