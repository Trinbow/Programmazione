#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
//la struttura date 
struct d{
    int day ;
    int mounth;
    int year;

};
typedef struct d date;
//prototipi delle funzioni updateDate ,getDate,checkDate,max_days,cifra_max 
void updateDate(date *d);
void getDate(date *d);
bool checkDate(date *d);
int max_days(date *d);
int cifra_max(int val);

//la funzione updateDate che modifica la data ricevuta aggiungendo 10 giorni  
void updateDate(date *d){
      int n=d->day+10;
      int max_d=max_days(d);
      if(n<max_d){d->day=d->day+10;}
      else{
           d->day=n-max_d;
           if(d->mounth<12){d->mounth++;}
           else{
                 d->mounth=1;
                 d->year++;
            }
      }

}
//la funzione getDate che creare una data
void getDate(date *d){
     
     int correct;
     do{

         printf("\ninserisci una data del tipo gg/mm/yy:\n");
         scanf("%d/%d/%d",&d->day,&d->mounth,&d->year);
         correct=checkDate(d);
     }while(correct ==false);


}
//la funzione checkDate che verifica se l data inserita e valida o no 
bool checkDate(date *d){
     
   if(d->day <1 || d->day >max_days(d)){return false;}
   if(d->mounth <1 || d->mounth >12){return false ;}
   if(cifra_max(d->year)==4){return true ;}
   return false ;
}
//la funzione max_days che restituisci vero se il giorno è maggiore del  massimo giorno del mese altrementi falso
int max_days(date *d){

   
    if(d->mounth ==1 || d->mounth ==3 || d->mounth ==5 || d->mounth ==7 || d->mounth ==8 || d->mounth ==10 || d->mounth ==12 ){return 31;}
    if(d->mounth ==4 || d->mounth ==6 || d->mounth == 9|| d->mounth ==11 ){return 30;}
    if(d->year %4==0 && (d->year %400==0 || d->year %100==0)){return 29;}
    else{return 28;}


}
// la funzione cifra massima che verifica se la cifra del anno e maggiore di 4 o no 
int cifra_max(int val){
      int count=0,unita;
      while(val>0){
           unita=val%10;
           count++;
           val=val/10;
     }
     printf("\ncount=%d\n",count);
     return count;

}







