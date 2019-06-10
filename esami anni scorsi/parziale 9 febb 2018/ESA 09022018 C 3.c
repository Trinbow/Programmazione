#include <stdio.h>
#include <stdbool.h> 
#include <stdlib.h>       /* printf, NULL */



//prototipi delle funzioni 
int f(int n);
double sinh1(int n);

//la funzione main 
int main() {
    printf("Valore di cosh1: %lf\n", sinh1(10));
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

double sinh1(int n){
      double som=0;
      int i;
      for(i=0;i< n;i++){
           som +=(double)1/f(2 * i+1);
       }

      return som;
}
