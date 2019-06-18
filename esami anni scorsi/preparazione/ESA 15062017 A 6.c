#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int globalChk;// dechiaro un valore globale che verifica se il valore nell array e primo o no 
//il nodo che contiene un valore del tipo int e un puntatore al prossimo nodo 
struct prime_t {
    int n;
    struct prime_t *next;
};
//prototipi delle funzioni 
int is_prime(int n);
struct prime_t *prime_list(int numbers[], int size);
void print_list(struct prime_t *list);
// la funzione main 
void main(){
    int numbers[] = {7, 9, 4, 11, 17, 21, 83};
    int size = 7;
    struct prime_t *list;
    
    
    list = prime_list(numbers, size);
    print_list(list);//sTampo la lista in modo ricorsivo 
}
// creo una lista solo dei numeri primi in modo ricorsivo
struct prime_t *prime_list(int numbers[], int size) {
	if(size>0){
		struct prime_t*temp;
		globalChk=*numbers/2;//il vriabile globale che prende la meta del numero esiste nella posizion i nell array 
                if(is_prime(*numbers)){
			temp=(struct prime_t*)malloc(sizeof(struct prime_t));
 			temp->n=*numbers;
			temp->next=prime_list(numbers+1,size-1);
			return temp;
		}
		else{
			return prime_list(numbers+1,size-1);	
		}
	}
	else{
            return NULL;
	}
}
//stampo la lista dei numeri primi in modo ricorsivo 

void print_list(struct prime_t *list) {
	if(list ==NULL){
		printf("\n");	
	}
	else{
		printf("%d",list->n);
		if(list->next !=NULL){
			printf("-> ");
		}
		print_list(list->next);	
	}
}

// ritorna 0 (falso) se l'argomento non e' primo
// ritorna un valore positivo (vero) se l'argomento è primo in modo ricorsivo 

int  is_prime(int n) {
	if(globalChk==1){
    		return 1;
  	}
	else{
    		if(n % globalChk==0) {
      			return 0;
    		} 
		else {
      			globalChk = globalChk-1;
    			is_prime(n);
    		}
  	}
}
