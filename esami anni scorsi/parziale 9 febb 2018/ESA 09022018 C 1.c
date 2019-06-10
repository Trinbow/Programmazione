#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#define N 8

//prototipi delle funzioni
void  generi_array(int a[N],int m);
void  stampa(int a[],int l);
int   occurenze(int a[N],int f,int i);
int   cheeck(int a[N],int f,int i);

//la funzione main 
int main(void) {
    srand(time(NULL));
    int m;
    int a[N];
    float freq; 
    do{
        printf("\ninserisci un numero maggiore di zero:\n");
        scanf("%d",&m);
    }while(m<=0);
    generi_array(a,m);//creare una array 
    stampa(a,N);
    int b[N],k=0,tot=0;
    float max=0.0,ftot=0.0;
    for(int i=0;i<N;i++){
   
        if(cheeck(a,a[i],i)){
             b[k]=occurenze(a,a[i],i);
             tot=tot+b[k];
             k++;
        }
        
    }
    stampa(b,k);//stampo l array delle freq
    printf("\ntotale=%d\n",tot); 
    //calcolo la frequenza di ogni possibile numero estratto all’interno dell’array e la si stampi;
    for(int i=0;i<k;i++){
        printf("\nfreq=%.2f\n",(float)b[i]/tot);
        if((float)b[i]/tot>max){max=(float)b[i]/tot;}
        ftot=ftot+(float)b[i]/tot;
    }
    
    printf("\nk=%d\n",k);
    printf("\nftot=%.2f\n",ftot);
    printf("\nil numero con la frequenza massima e'=%.2f\n",max);
    printf("\nla media delle frequenze  e'=%.2f\n",(float)ftot/k);
    
    return 0;
}


//generi dei numeri casulai 
void  generi_array(int a[N],int m){
    
    int i;
    for(i=0;i<N;i++){
        a[i]=m+rand()%(m+10);
    }
    printf("\n\n");  
} 

//

void  stampa(int a[],int l){

    int i;
    for(i=0;i<l;i++){
        printf("%3d",a[i]);         
    }
    printf("\n\n"); 

}
//calcola quanti volte occure il numero  

int occurenze(int a[N],int f,int i){

    int j,count=0;      
    for(j=i;i<N;i++){
        if(a[i]==f){count++;}
    }

    return count;
}
//verifica se il numero in posizione i si repite o no 

int   cheeck(int a[N],int f,int i){
    int j;
    if(i==0){return 1;}
    for(j=0;j<i;j++){
        if(a[j]==f){return 0;}
    }
    return 1;

}
