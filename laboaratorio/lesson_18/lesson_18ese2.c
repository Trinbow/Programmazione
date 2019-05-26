#include <stdio.h>
#include <string.h>
//prototipo della funzione 

void str_cat(char a[],char b[]);
 
int main()
{
      char a[1000], b[1000];
      
      printf("Enter the first string\n");
      scanf("%s",a);
     
      printf("Enter the second string\n");
      scanf("%s",b);
     
      //strcat(a, b);printf("String obtained on concatenation: %s\n", a);
      //il programma equivalente alla funzione strcata(a,b)
      str_cat(a,b);
      printf("String obtained on concatenation: %s\n", a);
     
      return 0;
}
void str_cat(char a[],char b[]){
      
      int i=0;
      while(a[i]!='\0'){ i++;}
      int j=i;
      int k=0;
      while(b[k]!='\0'){
              a[j]=b[k];      
              j++;
              k++;
      }
      a[j]='\0';

}
