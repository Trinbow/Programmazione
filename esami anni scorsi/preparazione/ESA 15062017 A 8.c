#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int num;//dechiaro il numero di volte che vogio ripetere il vocali ,variabili globale
// la struttora che contiene il nodo 
struct node_t{
	char value;
	struct node_t * next;
};

//prototipi delle funzioni 
struct node_t * crea_lista(char * s);

void triplica_vocali(struct node_t * n);

void stampa_lista(struct node_t * n);

bool is_vocali(char c);

struct node_t * add_list(struct node_t *p,char v,int n);

struct node_t * distruggi(struct node_t *p);

//la funzione main 

int main(){
	char s[] = "la mia stringa";
	struct node_t * head = crea_lista(s);
	printf("\nL’output del programma é il seguente:\n");
	stampa_lista(head);
	printf("\ninserisci quanti vocali vuoi ripetere:\n");
	scanf("%d",&num);
	triplica_vocali(head);
	stampa_lista(head);
	head=distruggi(head);
	stampa_lista(head);
		
	
	return 0;
}

//creo la lista in modo ricorsivo 
struct node_t * crea_lista(char * s){
	if(*s){
		struct node_t*temp;
		temp=(struct node_t*)malloc(sizeof(struct node_t));
		temp->value=*s;
		temp->next=crea_lista(s+1);
		return temp;
	}
	else{
		return NULL;
	}
}
//stampo la lista in modo ricorsivo 
void stampa_lista(struct node_t * n){
	if(n == NULL){
		printf("\n");
	}
	else{
		printf("%c",n->value);
		stampa_lista(n->next);
	}
}
//riceve in input una lista (il puntatore al primo nodo) e triplica i nodi della lista che contengono delle vocali. La funzione deve essere preferibilmente ricorsiva.
void triplica_vocali(struct node_t * n){
	if(n  != NULL){
		
		if(is_vocali(n->value)){
			struct node_t*temp,*a=n->next;
			n->next= add_list(n->next,n->value,num-1);//creo una nuova lista
			temp=n->next; 
                  	triplica_vocali(a);
		}
		else{
			triplica_vocali(n->next);
		}
	}
	else{
		printf("\n\n");
	}

}
//verifico se il valore vocali o no 
bool is_vocali(char c){
	return (c == 'a' ||c == 'i' || c == 'e' || c == 'o' || c == 'u' );
}
//creo la nuova lista dell caratteri vocali
struct node_t * add_list(struct node_t *p,char v,int n){
	if(n>0){
		struct node_t*temp;
		temp=(struct node_t*)malloc(sizeof(struct node_t));
		temp->value=v;
		temp->next=p;
		return add_list(temp,v,n-1);
	
	}
	else{
		return p;
	}
}

//distruggo la lista in modo ricorsivo
struct node_t * distruggi(struct node_t *p){
	if(p !=NULL){
		struct node_t*temp=p->next;
		free(p);
		p=temp;
		return distruggi(p);
	}
	else{
		printf("\nla lista e vuota.\n");
		return NULL;
	}
}







