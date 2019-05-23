#include <stdio.h>
#include <stdlib.h>

#define DIM 3

char *encode(char ma[][DIM], int mi[][DIM], int size);
void print_ma_mi(char ma[][DIM], int mi[][DIM], int size);
int get_size(int mi[][DIM], int size);

void main(){
    char ma[DIM][DIM] = {{'a', 'f', 'k'}, {'o', 'u', 'p'}, {'w', 'e', 'j'}};
    int mi[DIM][DIM] = {{3, 0, 2}, {2, 0, 1}, {0, 3, 2}};
    int size = DIM;
    
    print_ma_mi(ma, mi, size);
    
    char *s = encode(ma, mi, size);
	printf("Codifica: %s\n", s);
}

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
