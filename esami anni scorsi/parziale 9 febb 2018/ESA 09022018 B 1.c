#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>

//prototipi delle funzioni 
void invert_array(float arr[],int N);
void stampa_array(float arr[],int N,float m);
float massimo_array(float M[],int N );
float minimo_array(float M[],int N );
bool uguali(float med,float m);
bool minore(float med,float m);
bool maggiore(float med,float m);



//la funzione main 
int main (){
     float m;
     float M[10] = {0.12, 0.34, 0.56, 0.67, 0.98, 0.52, 0.56, 0.77, 0.92, 0.11};
     //richiedi input	
     do{
      printf("\ninserisci un numero positvo: \n");
      scanf("%f",&m);
    
     }while(!(m<=1.0 && m>=0.0));
     invert_array(M,10);//chiamo la funzione che inverta un array di N dimensione 
     stampa_array(M,10,m);//chiamo la funzione stampa che stampa l array
     printf("\nmassimo=%.2f\n",massimo_array(M,10));//stampo il massimo 
     if(uguali(massimo_array(M,10),m)){printf("\nil massimo  e' uguli di %.2f\n",m);}
     if(minore(massimo_array(M,10),m)){printf("\nil massimo e' minori di %.2f\n",m);}
     if(maggiore(massimo_array(M,10),m)){printf("\n il  massimo e' maggiore di %.2f\n",m);}
     //
     printf("\nminimo=%.2f\n",minimo_array(M,10));//stampo il minimo
     if(uguali(massimo_array(M,10),m)){printf("\nil massimo  e' uguli di %.2f\n",m);}
     if(minore(massimo_array(M,10),m)){printf("\nil massimo e' minori di %.2f\n",m);}
     if(maggiore(massimo_array(M,10),m)){printf("\n il  massimo e' maggiore di %.2f\n",m);}

return 0 ;
}
//creo un array di dimensione N
void invert_array(float arr[],int N){

    for(int i=0;i<N;i++){
          arr[i]=1-arr[i];

     }
   

}
//stampo l array 

void stampa_array(float arr[],int N,float m){
    int c=0,count=0;
    for(int i=0;i<N;i++){
          printf("%.2f\t",arr[i]);
          if(arr[i]<=m){c++;}
          else{count++;}
     }
    printf("\n\n");
    printf("\nci sono %d numeri minore o uguali di %.2f,e %d maggiore di %.2f\n",c,m,count,m);
}
//calcolo il massimo  
float massimo_array(float M[],int N){
     float  max=0.0;
     for(int i=0;i<N;i++){
         if(M[i]>max){max=M[i];}
     }

     return max;

}
//calcolo il minimo  
float minimo_array(float M[],int N){
     float  min=1.0;
     for(int i=0;i<N;i++){
         if(M[i]<min){min=M[i];}
     }

     return min;

}
//restiuisco vero se la media e uguali  di m,altrimenti falso 
bool uguali(float med,float m){
    /*if(med==m){return true;}
    return false;*/
    return med==m;
}
//restiuisco vero se la media e minore di m,altrimenti falso 
bool minore(float med,float m){
    /*if(med<m){return true;}
    return false;*/
    return med<m;
}
//restiuisco vero se la media e maggiore di m,altrimenti falso 
bool maggiore(float med,float m){
    /*if(med>m){return true;}
    return false;*/
    return med>m ;
}
