#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

//prototipi delle funzioni leggi e stampa,palindroma
void leggi(char this[],char that []);
void cpoy_to_lower_cases(char this[],char that []);
bool equals_ignore_cases(char this[],char that []);
int compareTo(char this[],char that );


//la funzione leggi che leggi una stringa di al massimo 80 caratteri
void leggi(char this[],char that[]){

     printf("\ninserire una stringa di al massimo 80 caratteri :");
     scanf("%80s",this);

     printf("\ninserire una stringa di al massimo 80 caratteri :");
     scanf("%80s",that);
}
//la funzione leggi che leggi una stringa di al massimo 80 caratteri
void stampa(char this[],char that []){
     int i=0;
     printf("\nla stringa this :");
     while(this[i]!='\0'){
          printf("%2c",this[i]);
          i++;
     }
     printf("\n");
     i=0;
     printf("\nla stringa that :");
     while(this[i]!='\0'){
          printf("%2c",that[i]);
          i++;
     }
     printf("\n");
}
//verifica se le due stringhe sono uguali o no 
bool equals_ignore_cases(char this[],char that []){
      int i=0;
      while(this[i]!='\0'){
      
           if(this[i]!=that[i]){return false;}
           i++;
     }
     return true ;


}


