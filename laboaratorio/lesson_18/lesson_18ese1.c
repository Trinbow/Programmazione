#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isVocal(char c){
    
       static char aeiou[]="aAeEiIoOuU";
       int j;
       for(j=0;j<10;j++){
              if(c==aeiou[j]){return true;}
          
       }
       return false ;


}


bool isAlphabetical(char c){

      return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));


}


void printstring(char word[]){
     int i=0;
     while(word[i]){printf("%2c",word[i]);i++;}printf("\n");

}
void checkstring(char word[]){
     int c_v=0;//contatore dei vocali nella stringa  
     int c_con=0; // contatori dei constanti nella stringa
     int  i=0;
       while (word[i]!='\0') {
		if (isVocal(word[i]))
			c_v++;
		else if(isAlphabetical(word[i]))
			c_con++;
		i++;
	 }
  
         printf("\nvocali= %d | coatanti =%d | lunghezza=%d\n",c_v,c_con,strlen(word));



}
int main () {
   char word[81]; 



       printf("Enter a string : ");
       scanf("%80s",word);
       printstring(word);
       checkstring(word);


   return(0);
}
