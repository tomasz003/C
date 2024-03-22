#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int KoniecPoczatkiem(char slowo1, char slowo2);

int main(){

    char slowo1[31];
    char slowo2[31];

    printf("Podaj slowo na max 30 liter: ");
    scanf("%s", &slowo1);
    printf("\nPodaj drugie slowo: ");
    scanf("%s", &slowo2);
    printf("\n");

    printf("%s\n", slowo1);
    printf("%s\n", slowo2);
    printf("%d", KoniecPoczatkiem(slowo1, slowo2));
    getchar();

return 0;
}

 int KoniecPoczatkiem(char slowo1, char slowo2){
        int counter=0;
        int max=0;

        for(int i=0; i<strlen(slowo1); i++){
            
            for(int j=0; j<strlen(slowo2); j++){
                if(slowo1[i+j]==slowo2[j])
                    counter++;
                else break;
            }
        if(max<counter) max=counter;
        }
        return max;
    }
