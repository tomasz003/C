#include <stdio.h>
#include <stdlib.h>

int main()
{int sum = 0;

for (int i=1; i<1000; i++){
    if (i%3==0)
        sum=sum+i;
    else
        if (i%5==0)
            sum=sum+i;
}
printf("%d", sum);

return 0;
}