#include<stdio.h>
#include<stdlib.h>
#define N 10
void stampacaracter(char c[N]){
     int i;
     for(i=0;i<N;i++){

       printf("%3c",c[i]);
  }
   printf("\n\n");
}
void getcaracter(char c[N]){
     int i;
     for(i=0;i<N;i++){

       printf("\ncarattere %2d: ",i+1); 
       scanf(" %c",&c[i]);
  }

}
void   print_senza(char c[N]){


    int i ,j ; 

     for(i=0;i<N;i++){
         for(j=0;j<i;j++){
             
                   if(c[i]==c[j]){break;}          
         }


         if(i==j){ printf("%3c",c[i]);}
     }




}
int main (){
  char c[N];
  int i,j;
  getcaracter(c);
  stampacaracter(c);
  print_senza(c);
  printf("\n");
 
 


return 0;
}
