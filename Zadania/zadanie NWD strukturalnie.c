#include <stdio.h>
#include <stdlib.h>


typedef struct{
  int liczba_do_rozkladu;
  int rozmiar;
  int *tab;
} liczba;

liczba* rozklad(int n);
void wypis(liczba*L);
void zniszcz(liczba*L);
int NWDNWW(liczba*L, liczba*K);

int main()
{
    liczba pierwsza;

    int n, m;
    printf("Podaj liczby do rozkladu: \n");
    scanf("%d", &n);
    liczba *x1 = rozklad(n);

    scanf("%d", &n);
    liczba *x2 = rozklad(n);
  
    printf("\n");
  
    wypis(x1);
    wypis(x2);
  
    NWDNWW(x1,x2);
    
    zniszcz(x1);
    zniszcz(x2);
    return 0;   
}



liczba* rozklad(int n)
{        
    liczba *wynik = (liczba*)malloc(sizeof(liczba));
    if(wynik==NULL)
    {
        printf("Problemy przy tworzeniu struktury");
        exit(2);
    }
    wynik->liczba_do_rozkladu=n;

    int roz=0;
    int *czynniki = (int*)malloc(sizeof(int)*roz);
    int * pomoc = NULL;

    int k=2;
    while(k<=n){
        if(n%k==0){
            ++roz;
            pomoc = (int*)realloc(czynniki, sizeof(int)*roz);
            if(pomoc==NULL)
            {
                printf("Problemy przy rozszerzaniu tablicy czynników");
                exit(1);
            }
            czynniki = pomoc;
            czynniki[roz-1]=k;
            n/=k;
        }
        else
            ++k;
        
    }
    pomoc=NULL;

    wynik->rozmiar=roz;
    wynik->tab=czynniki;
    return wynik;

}

void wypis(liczba*L)
{
    printf("%d=",L->liczba_do_rozkladu);
        for (int i = 0; i <L->rozmiar-1; ++i)
            printf("%d*", L->tab[i]);
        printf("%d\n", L->tab[L->rozmiar-1]);

}

void zniszcz(liczba*L)
{
    free(L->tab);
    free(L);
}

int NWDNWW(liczba*L, liczba*K) //x1, x2
{
  int najw=1;
                
  int c=0;            
    for (int j = 0; j < L->rozmiar; j++)
    {
        for (int i = 0; i < (K->rozmiar); i++)
        { 
            if ((L->tab[j])==(K->tab[i+c])){
                najw=najw*(L->tab[j]);
                 c=c+1+i;  
              //c jest po to, by gdy już znajdziemy i-ty element K równy j-temu z L, to żeby poźniej L[j+1] szukać już w późniejszych elementach tablicy K, a nie zaczynać od K[0]
                
                break;
            }
        }
        
    }
    printf("\nNWD(%d, %d) jest rowne %d.", L->liczba_do_rozkladu, K->liczba_do_rozkladu, najw);
    printf("\nNWW(%d, %d) jest rowne %d.", L->liczba_do_rozkladu, K->liczba_do_rozkladu, L->liczba_do_rozkladu*K->liczba_do_rozkladu/najw);

  return 0;
}


//niesamowite 
//kocham programować
//kocham chemię 
//but "hem" is silent...

//jeny W KOŃCU działa kochanie