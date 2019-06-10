#include <stdio.h>
#include <stdbool.h>


//prototipi delle funzioni 
int contaCifreUguali(int n, int c);
bool uguali(int a,int b);
int main(void) {
    int n1 = 12345;
    int n2 = 86662;
    int n3 = 13543;
    int n4 = 97578;
    int n5 = 0;    

    printf("Numero occorrenze di %i in %i: %i\n", 1, n1, contaCifreUguali(n1,1));
    printf("Numero occorrenze di %i in %i: %i\n", 6, n2, contaCifreUguali(n2,6));
    printf("Numero occorrenze di %i in %i: %i\n", 3, n3, contaCifreUguali(n3,3));
    printf("Numero occorrenze di %i in %i: %i\n", 7, n4, contaCifreUguali(n4,7));
    printf("Numero occorrenze di %i in %i: %i\n", 1, n5, contaCifreUguali(n5,1));
    printf("Numero occorrenze di %i in %i: %i\n", 0, n5, contaCifreUguali(n5,0));
    
    return 0;
}
//calcolo e ristituisco quante occurenze  ci sono del numero c in n 

int contaCifreUguali(int n, int c){
    int count=0;
    int cifra;
    if(n==0 && c ==0){return 1;}
    while(n>0){

        cifra=n%10;
        if(uguali(cifra,c)){count++;}
        n=n/10;
   }
  return count  ;
}

//ristituisco vero se la cifra uguali al numero c altrementi falso 

bool uguali(int a,int b){

return a==b;
}

