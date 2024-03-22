#include <stdio.h>
#define MAX 100

void wczytaj(double T[], int n);  //deklaracja funkcji
//void wczytaj(double *T)

double euklidesowa( double x[], double y[], int n);

int main(){
   double x[MAX], y[MAX];
   int wymiar;
   printf("Podaj ilosc wymiarow (1-%d): ", MAX);
   scanf("%d", &wymiar);

   wczytaj(x, wymiar );

}

void wczytaj(double T[], int n){ //definicja funkcji
   for(int i=0; i<n ; ++i){
      printf("Wsp. nr %d: ", i+1);
      scanf("%lf", &T[i]);
//      scanf("%lf", T+i); // *(i+T) <=> i[T]
   }
}

double euklidesowa( double x[], double y[], int n){

   // Oblicz odleg³oœæ w metryce euklidesowej podanych punktów x, y
}
