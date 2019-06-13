#include <stdio.h>
#include <stdlib.h>

#define DIM 3
#define ASCII_A 65
#define BLANK ' '	

struct cell_t{
	int value;
	char name;
};

/*
 * Crea una nuova cella con nome e valore specificato
 */
struct cell_t * new_cell(char name, int value){
	struct cell_t *cell = (struct cell_t *) malloc(sizeof(struct cell_t));
	cell->name = name;
	cell->value = value;
	return cell;
}

/*
 * Crea una matrice della dimensione specificata. Le celle assumono per righe i nomi 'A', 'B',...
 * e il valore specificato
 */
void init_matrix(struct cell_t* matrix[DIM][DIM], int size, int value){
	for(int i = 0; i < size; i++) {
		for(int j = 0; j < size; j++) {
			int index = i*DIM + j;
			char name = ASCII_A + index;
			matrix[i][j] = new_cell(name, value);
		}		
	}
}

/*
 * Stampa la matrice specificata coi nomi delle celle se il corrispondente valore è diverso da 0 altrimenti stampa uno spazio
 */
void print_matrix(struct cell_t* matrix[DIM][DIM], int size){
	for(int i = 0; i < size; i++) {
		for(int j = 0; j < size; j++) {
			//char c = (matrix[i][j]->value == 0) ? BLANK : matrix[i][j]->name;
			char c ;
                        if(matrix[i][j]->value == 0){c=BLANK;}
                        else{c=matrix[i][j]->name;}
                      
                        printf("%2c ", c);
		}		
		printf("\n");
	}
	printf("\n");
}

/*
 * Scambia i nomi e i valori delle celle di nome name1 e name2.
 * Se tali celle non sono presenti nella matrice specificata non fa nulla.
 */
void swap_cells(struct cell_t *matrix[DIM][DIM], int size, char name1, char name2) {
	int row1 = -1, col1 = -1, row2 = -1, col2 = -1;

	for(int i = 0; i < size; i++) {
		for(int j = 0; j < size; j++) {
			if(matrix[i][j]->name == name1) {
				row1 = i;
				col1 = j;
			}
			if(matrix[i][j]->name == name2) {
				row2 = i;
				col2 = j;
			}
		}		
	}

	if (row1 != -1 && row2 != -1) {
		struct cell_t *temp = matrix[row1][col1];
		matrix[row1][col1] = matrix[row2][col2];
		matrix[row2][col2] = temp;
	}
}

/*
 * Libera la memoria riservata alle celle della matrice specificata
 */
void free_matrix(struct cell_t *matrix[DIM][DIM], int size) {
	if(matrix != NULL) {
		for(int i = 0; i < size; i++) {
			for(int j = 0; j < size; j++) {
				free(matrix[i][j]);
			}		
		}
	}
}

/*
 * Program entry point
 */
int main(){
	struct cell_t *matrix[DIM][DIM];

	init_matrix(matrix, DIM, 1);
	print_matrix(matrix, DIM);
	swap_cells(matrix, DIM, 'B', 'F');
	print_matrix(matrix, DIM);
	free_matrix(matrix, DIM);
	return 0;
}
