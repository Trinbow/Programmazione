#include <stdio.h>
#include <stdlib.h>

#define DIM 3

//prototyping delle funzione 
char *encode(char ma[][DIM], int mi[][DIM], int size);
void print_ma_mi(char ma[][DIM], int mi[][DIM], int size);
int get_size(int mi[][DIM], int size);



//restitusci la stringa s
char *encode(char ma[][DIM], int mi[][DIM], int size) {
    char *s;
    int count = get_size(mi, size);
    int index = 0;
    
    s = (char *)malloc(sizeof(char) * (count + 1));
    
    
    for(int i=0;i<size;i++){
       for (int j=0;j<size;j++){
           for(int k=0;k<mi[i][j];k++){
                s[index]=ma[i][j];
                index++; 
           }
        } 
     }
    
    s[index]='\0';	
    return s;
}
//restitusci la dimensione della stringa 
int get_size(int mi[][DIM], int size) {
  
  int i,j;
  int count=0;
  for(i=0;i<size;i++){
       for (j=0;j<size;j++){
           count=count+mi[i][j];  
       } 
     }
  return count ;
  
  
}
//stampa le due matrici
void print_ma_mi(char ma[][DIM], int mi[][DIM], int size) {
      int i,j;

     //stampa la matrice ma 
     printf("\nMatrice ma\n");
     for(i=0;i<size;i++){
           for (j=0;j<size;j++){
               printf("%3c",ma[i][j]);        
    
           } 
           printf("\n");
     }
	
     //stampa la matrice mi
     printf("\nMatrice mi\n");
     for(i=0;i<size;i++){
           for (j=0;j<size;j++){
               printf("%3d",mi[i][j]);        
    
           } 
           printf("\n");
     }

}
