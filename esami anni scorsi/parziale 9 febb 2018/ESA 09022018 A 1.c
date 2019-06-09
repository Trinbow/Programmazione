#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>

#define N 7
#define MAX 9
//prototipi delle funzioni 
void crea_array(int a[N],int m);
void stampa_array(int a[N]);
float media_array(int a[]);
bool uguali(float med,int m);
bool minore(float med,int m);
bool maggiore(float med,int m);
int main (){
     srand(time(NULL));
     int m;
     int a[N];
     //chiedo al programma un numero positivo intero m che sia minore o uguale a MAX
     do{
      printf("\ninserisci un numero positvo: \n");
      scanf("%d",&m);
    
     }while(m>MAX);
     crea_array(a,m);//chiamo la funzione che crea un array di N dimensione 
     stampa_array(a);//chiamo la funzione che stampa l array
     printf("\nmedia=%.2f\n",media_array(a));//stampo la media 
     if(uguali(media_array(a),m)){printf("\nla media e' uguli di %d\n",m);}
     if(minore(media_array(a),m)){printf("\nla media e' minori di %d\n",m);}
     if(maggiore(media_array(a),m)){printf("\nla media e' maggiore di %d\n",m);}

return 0 ;
}
//creo un array di dimensione N
void crea_array(int arr[N],int m){
    int c=0,count=0;
    for(int i=0;i<N;i++){
          arr[i]=rand()%MAX;
          if(arr[i]<=m){c++;}
          else{count++;}
     }
    printf("\n\n");
    printf("\nci sono %d numeri minore o uguali di %d,e %d maggiore di %d\n",c,m,count,m);

}
//stampo l array 

void stampa_array(int arr[N]){
    for(int i=0;i<N;i++){
         printf("%3d",arr[i]);
    }
    printf("\n");

}
//calcolo e restituisco la media dell array 
float media_array(int a[N]){
     float  som=0.0;
     for(int i=0;i<N;i++){
         som=som+a[i];
     }

     return som/N;

}
//restiuisco vero se la media e uguali  di m,altrimenti falso 
bool uguali(float med,int m){
    /*if(med==m){return true;}
    return false;*/
    return med==m;
}
//restiuisco vero se la media e minore di m,altrimenti falso 
bool minore(float med,int m){
    /*if(med<m){return true;}
    return false;*/
    return med<m;
}
//restiuisco vero se la media e maggiore di m,altrimenti falso 
bool maggiore(float med,int m){
    /*if(med>m){return true;}
    return false;*/
    return med>m ;
}
