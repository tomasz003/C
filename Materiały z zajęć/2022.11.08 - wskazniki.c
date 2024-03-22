#include <stdio.h>
#include <stdlib.h> // void* malloc(size_t)  void free(void*)

void zmien( char literka ){
   printf("%c\n", literka);
   literka='K';
   printf("%c\n", literka);
}

void zmien_v2( char *literka ){
   printf("%c\n", *literka);
   *literka='K';
   printf("%c\n", *literka);
}

void zamiana( double *a, double *b){
   double bufor= *a;
   *a= *b;
   *b= bufor;
}

int main(){
   int rozm;
   printf("Podaj ilosc elementow: ");
   scanf("%d", &rozm);
   char *T= NULL;
   size_t ile_bajtow= sizeof(char)*rozm;
   T= (char*)malloc(ile_bajtow);
   if( T == NULL ){
      // nie uda³o siê
   }
   T[0]='P';
   *(T+1)='a';
   T[2]= '\0';
   printf("%s", T);
   free(T);
   T=NULL;

//   float tab[10];
//   tab[0]= 3.24;
//   printf("%f\n",tab[0]);
//   *(tab+1)= 4.5;
//   printf("%f %f\n",tab[0],tab[1]);
////   tab[2] <=>  *(tab+2) <=> *(2+tab) <=> 2[tab]
//   2[tab]= 3.3333;
//   printf("%f %f %f\n",tab[0],tab[1],tab[2]);
////   &tab[i] <=> tab+i

//   double x=2.3, z= 3.1415;
//   printf("%f, %f\n", x, z);
//   double bufor= x;
//   x= z;
//   z= bufor;
//   printf("%f, %f\n", x, z);
//   zamiana( &z, &x );
//   printf("%f, %f\n", x, z);

//   char znak='G';
//   printf("%c\n", znak);
//   zmien_v2( &znak );
//   printf("%c\n", znak);

//   int a=2, b=4;
//   int *ws_int;
//   ws_int= &a;
//   printf("%d, %d\n", a, b);
//   b= *ws_int;
//   *ws_int+=13;
//   ws_int= &b;
//   *ws_int+=13;
//   printf("%d, %d\n", a, b);
}
