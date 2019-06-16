#include <stdio.h>
#include <stdlib.h>

#define DIM 3

//prototipi delle funzioni 
char *encode(char ma[][DIM], int mi[][DIM], int size);
void print_ma_mi(char ma[][DIM], int mi[][DIM], int size);
int get_size(int mi[][DIM], int size);


//la funzione main 

void main(){
    	char ma[DIM][DIM] = {{'a', 'f', 'k'}, {'o', 'u', 'p'}, {'w', 'e', 'j'}};
    	int mi[DIM][DIM] = {{3, 0, 2}, {2, 0, 1}, {0, 3, 2}};
    	int size = DIM;
    
	print_ma_mi(ma, mi, size);
    
	char *s = encode(ma, mi, size);
	printf("Codifica: %s\n", s);
}

//
char *encode(char ma[][DIM], int mi[][DIM], int size) {
        int count=get_size(mi, size),d=0;
	char *s=(char *)malloc((count+1)*sizeof(char));
	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++){
				for(int k=0;k<mi[i][j];k++){
					s[d]=ma[i][j];
					d++;							
				}	
		}	
	}
        s[d]='\0';
	return s;        
}

//restituisco il size della stringa

int get_size(int mi[][DIM], int size) {
	int count =0;
	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++){
			count=count+mi[i][j];	
		}
	}
	return count ;
}

//stampo le due matrici ma mi
void print_ma_mi(char ma[][DIM], int mi[][DIM], int size) {
        //stampo la matrice ma 
	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++){
			printf("%2c",ma[i][j]);
		}
		printf("\n");
	}
	printf("\n\n");
        //stampo la matrice mi
	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++){
			printf("%2d",mi[i][j]);
		}
		printf("\n");
	}
	printf("\n\n");
}
