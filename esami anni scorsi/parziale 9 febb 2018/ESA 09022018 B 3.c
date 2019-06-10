#include <stdio.h>
#include <stdbool.h> 
#include <stdlib.h>       /* printf, NULL */



//prototipi delle funzioni 
int f(int n);
double cosh1(int n);

//la funzione main 
int main() {
    printf("Valore di cosh1: %lf\n", cosh1(10));
    return 0;
}

//restituisce il fattoriale di un numero n calcolato in modo iterativo

int f(int n){
    int f=1;
    for(int i=1;i<=n;i++){
         f=f*i;
    }

    return f;
}


//restituisce la somma di n termini della serie:

double cosh1(int n){
      double som=0;
      int i;
      for(i=0;i< n;i++){
           som +=(double)1/f(2 * i);
       }

      return som;
}
