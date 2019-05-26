#include "5.h"

int main (){

    time tempo,*t=&tempo;	
    long int sec;
    printf("\ninserisci il tempo in secondi:");
    scanf("%ld",&sec);
    split_time(sec,t);
    printf("\nil tempo aggiornato e'= %d:%d:%d\n",t->ore,t->minuti,t->secondi);     

return 0;
}

