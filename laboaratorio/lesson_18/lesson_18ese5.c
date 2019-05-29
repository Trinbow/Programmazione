#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#define N 80
//prototipi delle funzioni leggi e stampa,palindroma
void leggi(char s[]);
void stampa(char s[]);
bool palindroma(char s[],int size);
bool palindrom(char s[],int i,int j);//versione ricorsiva

int main(){
    char s[N];
    leggi(s);
    int l=strlen(s);
    stampa(s);
    if(palindroma(s,l)){printf("\npalindrom\n");}
    else{printf("\nnot palindrom\n");}
    //chiama ricorsiva
    if(palindrom(s,0,l-1)){printf("\npalindrom\n");}
    else{printf("\nnot palindrom\n");}

return 0;
}
//la funzione leggi che leggi una stringa di al massimo 80 caratteri
void leggi(char s[]){

     printf("\ninserire una stringa di al massimo 80 caratteri :");
     scanf("%80s",s);
}
//la funzione leggi che leggi una stringa di al massimo 80 caratteri
void stampa(char s[]){
     int i=0;
     while(s[i]!='\0'){
          printf("%2c",s[i]);
          i++;
     }
     printf("\n");
}
//Verifica se la stringa inserita e palindroma
bool  palindroma(char s[],int size){
    int i=0,j=size-1;
    for (i = 0; i < (size/2); i++){
        if (s[i] != s[j]){
            return false;
        }
        j--;
     }


 return true ;
}
//verifica se la stringa data e palindroma o no versione ricorsiva 
bool  palindrom(char s[],int i,int j){
        if(i>=j){return true;}
        if (s[i] != s[j]){
            return false;
        }
        else{
            return palindrom(s,i+1,j-1);//chiama ricorsiva
        }

}
