#include <stdio.h>
#include <stdbool.h>

//prototipi delle funzioni
int cifraMassima(int n);
bool massimo(int unita,int max);
int main(void) {
    int n1 = 12345;
    int n2 = 86662;
    int n3 = 13543;
    int n4 = 97578;
    int n5 = 0;    

    printf("La cifra piu' grande di %i e': %i\n", n1, cifraMassima(n1));
    printf("La cifra piu' grande di %i e': %i\n", n2, cifraMassima(n2));
    printf("La cifra piu' grande di %i e': %i\n", n3, cifraMassima(n3));
    printf("La cifra piu' grande di %i e': %i\n", n4, cifraMassima(n4));
    printf("La cifra piu' grande di %i e': %i\n", n5, cifraMassima(n5));
    
    return 0;
}
//restituisco la cifra massima del numero n 
int cifraMassima(int n){

     int max=0;
     int unita;
     while(n>0){
  
         unita=n%10;
         if(massimo(unita,max)){max=unita;}
         n=n/10;
    }

    return max;
}
//restituisci vero se unita >max,altrmenti falso 
bool massimo(int unita,int max){

    return unita>max; 
}

