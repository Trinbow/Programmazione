#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define DIM 3
#define ASCII 65
#define BLANK ' '

//prototipi delle funzioni
struct cell_t*new_cell(char nome,int valore);
void init_matrix(struct cell_t *matrix[DIM][DIM], int size, int n);
void print_matrix(struct cell_t*matrix[DIM][DIM],int size);
void swap_cells(struct cell_t*matrix[DIM][DIM], int size, char name1, char name2);
void free_matrix(struct cell_t*matrix[DIM][DIM],int  size);
//la cella che contienne il nome e il valore 
struct cell_t{

    int valore;
    char nome ; 

};

//crea una nuova cella con nome e valore specificato 
struct cell_t*new_cell(char nome,int valore){
      struct cell_t *temp=(struct cell_t*)malloc(sizeof(struct cell_t));
      temp->valore=valore;
      temp->nome=nome;
return temp ;
}

/*
 * Program entry point
 */
int main(){
	struct cell_t *matrix[DIM][DIM];

	init_matrix(matrix, DIM, 1);
	print_matrix(matrix, DIM);
	swap_cells(matrix, DIM, 'A', 'F');
	print_matrix(matrix, DIM);
	free_matrix(matrix, DIM);
	return 0;
}
//crea una matrice della dimensione specificata. Le celle assumono per righe i nomi ’A’, ’B’,...e il valore specificato

void init_matrix(struct cell_t *matrix[DIM][DIM], int size, int n){
     int i,j;
     for(i=0;i<size;i++){
          for(j=0;j<size;j++){
             int index=i*DIM+j;
             char name=ASCII+index;
             matrix[i][j]=new_cell(name,n);
          }
     }

}
//stampo la matrice 
void print_matrix(struct cell_t*matrix[DIM][DIM],int size){

     int i,j;
     for(i=0;i<size;i++){
          for(j=0;j<size;j++){
              char c ;
              if(matrix[i][j]->valore==0){c=BLANK;}
              else{c=matrix[i][j]->nome;}
              printf("%2c",c);
          }
          printf("\n");
     }
     printf("\n");
     
}
//
void swap_cells(struct cell_t*matrix[DIM][DIM], int size, char name1, char name2){
     int i,j;
     int row1=-1,row2=-1,colon1=-1,colon2=-1;

     for(i=0;i<size;i++){
          for(j=0;j<size;j++){
              
              if(matrix[i][j]->nome==name1){
                      row1=i;colon1=j;
              }
              if(matrix[i][j]->nome==name2){
                      row2=i;colon2=j;
              }
          }
     }
     if(row1!=-1 && row2!=-1){
          struct cell_t *temp;
          temp=matrix[row1][colon1];
          matrix[row1][colon1]=matrix[row2][colon2];
          matrix[row2][colon2]=temp;
     }
     printf("\n");

}
//
void free_matrix(struct cell_t*matrix[DIM][DIM],int  size){
     for(int i=0;i<size;i++){
         for(int j=0;j<size;j++){
                  free(matrix[i][j]);            
         }
     }  
    
}
