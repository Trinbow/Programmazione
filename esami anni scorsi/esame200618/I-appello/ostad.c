#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node_t{
	char value;
	struct node_t * next;
};


struct node_t * crea_nodo(char v, struct node_t * next){
	struct node_t * n = (struct node_t *) malloc(sizeof(struct node_t));
	n->value = v;
	n->next = next;
	return n;
}

struct node_t * crea_lista(char * s){
	struct node_t * head  = NULL;
	struct node_t * prev  = NULL;
	while(*s){
		struct node_t * n =  crea_nodo(*s, NULL);
		if(head == NULL){
			head = n;
		}
		if(prev != NULL){
			prev->next = n;
		}
		prev = n;
		s+1;
	}
	return head;
}

bool is_vowel(char c){
	if( c=='a' || c=='e' || c=='i' || c=='o' || c=='u'){
		return true;
	}
	return false;
}

void triplica_vocali(struct node_t * n){
	if(n != NULL){
		if(is_vowel(n->value)){
			n->next = crea_nodo(n->value, crea_nodo(n->value, n->next));
			triplica_vocali(n->next->next->next);
		}
		else{
			triplica_vocali(n->next);
		}
	}
}

void stampa_lista(struct node_t * n){
	struct node_t * c = n;
	while(c != NULL){
		printf("%c", c->value);
		c = c->next;
	}
	printf("\n");
}

void distruggi(struct node_t * n){
	if(n != NULL){
		distruggi(n->next);
		free(n);
	}
}


int main(){
	char s[] = "la mia stringa";
	struct node_t * head = crea_lista(s);
	stampa_lista(head);
	triplica_vocali(head);
	stampa_lista(head);
	distruggi(head);
	return 0;
}
