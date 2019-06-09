#include <stdio.h>
#include <stdbool.h>

//prototipi delle funzioni
double e(int n);

int fact(int n );
int main(){


    printf("Valore di e: %lf\n", e(10));



return 0;
}
//restituisco la cifra massima del numero n 
double  e(int n){
    double som=0;
    for(int i =0;i< n;i++){
        som=som+(double)1/fact(i);
    }

    return som;
}
//restituisci vero se unita >max,altrmenti falso 
int fact(int n){
    int f=1;
    //if(n==0){return 1;}
    for(int i =1;i<= n;i++){
        f=f*i;
    }
    return f; 
}

