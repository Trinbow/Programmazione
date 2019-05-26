#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
//la struttura time 
struct t{
    int ore ;
    int minuti;
    int secondi;

};
typedef struct t time;
//prototipo della funzione split_time
void split_time(long int s,time *t);

//la funzione split_time che calcola il tempo equivalente 
void split_time(long int s,time *t){

   t->ore=s/3600;
   s=s%3600;
   t->minuti=s/60;
   s=s%60;
   t->secondi=s;

}
