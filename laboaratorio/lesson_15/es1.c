#include <stdio.h>
#include <string.h> 
# include <stdbool.h>  
/* Function to print reverse of the passed string */
void stampa(char *s) 
{ 
   if (*s=='\0') 
   {   
       printf("\n");
   } 
    else{
            printf("%c", *s);
            stampa(s+1);
    }
} 


//
void leggi(char *s){
       
       printf("\ninserisci una stringa:\n");
       scanf("%s",s);
   
}
//
bool palindroma(char *s,int i,int e){
     /* if(e==0){return false;}
  
      else if(i==e){return true ;}
           else if(s[i]==s[e]){
                  return palindroma(s,i++,e--);
                }
                else{return false;}
     */
   return !(e==0) || (i==e) || (s[i]==s[e] int r= palindroma(s,++i,--e)) ;
}
  
  
/* Driver program to test above function */
int main() 
{ 
   char a[80];
   leggi(a); 
   int l=strlen(a);
   printf("\nsize=%d\n",l);
   stampa(a);
   printf("\n");
   if(palindroma(a,0,l-1)){
       printf("\nla stringa %s e' palindroma.\n",a);
   }
   else{
       printf("\nla stringa %s non e' palindroma.\n",a);
   }
   return 0; 
} 
