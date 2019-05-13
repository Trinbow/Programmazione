#include<stdio.h>
#include<stdlib.h>
#define N 10
void senza_dup(char c[N]){
   int i,j;
  printf("\n output: ");
  for(i=0 ;i<N;i++){
      for(j=0;j<i;j++){
        if(c[i]==c[j])
              break;
      }
   if(i==j){printf("%3c",c[i]);}
  }

   printf("\n");
}
int main(){
   int i,j;
   char c[N],d;
   for(int i=0;i<N;i++){
     printf("\ninserire il carattere %2d:", i+1);
     scanf(" %c",&c[i]);
   }
   printf("\ninput : ");
   for(i=0;i<N;i++){
     printf("%3c",c[i]);
   }
   printf("\n");
   senza_dup(c);
return 0;
}
