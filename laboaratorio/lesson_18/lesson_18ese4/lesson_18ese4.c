#include "Myfunctions.h"  


int main(){
    char s1[80],s2[80];
    leggi(s1,s2);
    int l1=strlen(s1),l2=strlen(s2);
    stampa(s1,s2);
    if(equals_ignore_cases(s1,s2)){printf("\nle stringhe sono uguali,a prescindere da caratteri minuscoli/maiuscoli.\n");}
    else{printf("\nle stringhe sono diversi .\n");}

return 0;
}
