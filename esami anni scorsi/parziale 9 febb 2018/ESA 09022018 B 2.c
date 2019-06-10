#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//prototipi delle funzioni
float mediaCifre(int n);



//la funzione main 
int main(void) {
    int n1 = 12345;
    int n2 = 86662;
    int n3 = 13543;
    int n4 = 97578;
    int n5 = 0;    

    printf("La media delle cifre di %i e': %g\n", n1, mediaCifre(n1));
    printf("La media delle cifre di %i e': %g\n", n2, mediaCifre(n2));
    printf("La media delle cifre di %i e': %g\n", n3, mediaCifre(n3));
    printf("La media delle cifre di %i e': %g\n", n4, mediaCifre(n4));
    printf("La media delle cifre di %i e': %g\n", n5, mediaCifre(n5));
    
    return 0;
}


//la funzione che ristituisce la media delle cifre che compaino nel numero intero n 
float mediaCifre(int n){
     int som=0;
     int cifra,count=0;
     if(n==0){return 0.0;}
     while(n>0){
       
         cifra=n%10;
         printf("\ncifra=%d\n",cifra);
         count++;
         som=som+cifra;
         n=n/10; 


    }
    return  (float)som/count;
}
