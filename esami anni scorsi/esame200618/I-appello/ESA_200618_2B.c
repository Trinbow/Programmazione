#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define DIM 3
#define E1 'X'
#define E2 'O'
#define BLANK ' '
//prototipi delle funzioni 
struct element_t*new_elemnt(char nome ,int valore);
void init_matrix(struct element_t*matrix[DIM][DIM],int size,int value);
void print_matrix(struct element_t* matrix[DIM][DIM], int size);
void find_element(struct element_t*matrix[DIM][DIM], int size,char name, int *pos);
void free_matrix(struct element_t*matrix[DIM][DIM], int size);


//la struttura 
struct element_t{
     int valore;
     char nome ;

};

//la funzione main 

int main() {
	struct element_t *matrix[DIM][DIM];

	init_matrix(matrix, DIM, 1);
	print_matrix(matrix, DIM);
	int pos[2];
	find_element(matrix, DIM, E2, pos);
	printf("%i %i\n", pos[0], pos[1]);
	find_element(matrix, DIM, 'R', pos);
	printf("%i %i\n", pos[0], pos[1]);
	free_matrix(matrix, DIM);
        print_matrix(matrix, DIM);
	return 0;
}
//creo un nuovo elemento con nome e valore specificato
struct element_t*new_element(char nome ,int valore){
     struct element_t *temp;
     temp=(struct element_t *)malloc(sizeof(struct element_t ));
     temp->valore=valore;
     temp->nome=nome;
     return temp;
 
}
//creo la matrice Gli elementi assumono per righe alternativamente i nomi E1 e E2
void init_matrix(struct element_t*matrix[DIM][DIM],int size,int value){
     for(int i=0;i<size;i++){
          for(int j=0;j<size;j++){
                char name=(j%2==0) ? E1 : E2;
               /* if(j%2==0){name =E1;}
                else{name =E2;}*/
              
                matrix[i][j] = new_element(name,value);        
          }
     }

}

//stampo la matrice
 
void print_matrix(struct element_t* matrix[DIM][DIM], int size){
	for(int i = 0; i < size; i++) {
		for(int j = 0; j < size; j++) {
			char c;//char c = (matrix[i][j]->valore == 0) ? BLANK : matrix[i][j]->nome;
                        if(matrix[i][j]->valore == 0){c=BLANK;}
                        else{c=matrix[i][j]->nome;}
			printf("%c ", c);
		}		
		printf("\n");
	}
	printf("\n");
}
//imposta l’array di coordinate pos con le coordinate della prima occorrenza di name nella matrice specificata. Se il valore non viene trovato l’array gli elementi di pos assumono entrambi il valore-1.

void find_element(struct element_t*matrix[DIM][DIM], int size,char name, int *pos){
      pos[0]=pos[1]=-1;//se non trova il nome nella matrice
      for(int i = 0; i < size; i++) {
		for(int j = 0; j < size; j++) {
			if(matrix[i][j]->nome==name){
                                  pos[0]=i;
                                  pos[1]=j;
                                  return ;
                        }
		}		
	}
 
}
//libero la memoria riservata agli elementi della matrice specificata

void free_matrix(struct element_t*matrix[DIM][DIM], int size){
      
        for(int i = 0; i < size; i++) {
		for(int j = 0; j < size; j++) {
			free(matrix[i][j]);
		}		
	}

}



















