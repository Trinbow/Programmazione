#include <stdio.h>
#include <stdlib.h>

#define N 5
//prototipi delle funzioni


//il nodo che contiene un array

struct node_t{
	int values[3];
	struct node_t * next;
};
struct node_t*root=NULL,*y=NULL;//dechiaro due variabili globali del tipo struct node_t

//creo un nuodo e restituisco il suo indirizzo 

struct node_t * crea_nodo(int values[3], struct node_t * next){
	struct node_t * n = (struct node_t * )malloc(sizeof(struct node_t));
	int i;
	for(i=0;i<3; i++){
		n->values[i] = values[i];
	}
	n->next = next;
	return n;
}
//la funziome crea_lista prende in input una matrice di N righe e 3 colonne, e la converte in una lista.I nodi della lista sono definiti dalla strutura struct node t e la conversione viene eseguita in modo da copiare la i-esima riga della matrice nel corrispondente array dell’i-esimo nodo.

int i=5;
struct node_t * crea_lista(int matrice[N][3],int s){
	/*struct node_t * head = crea_nodo(matrice[0], NULL);
	struct node_t * c = head;
	int i;
	for(i=1; i<N; i++){
		c->next = crea_nodo(matrice[i], NULL);
		c = c->next;
	}
	return head;*/
        if(s!=0){
            struct node_t * temp;
            temp=(struct node_t *)malloc(sizeof(struct node_t));
            temp->values[0]=matrice[i-s][0];
            temp->values[1]=matrice[i-s][1];
            temp->values[2]=matrice[i-s][2];
            temp->next=crea_lista(matrice,s-1);
            return temp;   
        }
        else{
           return NULL;
        }
}
//la funzione sfoltisci prende in input una lista costruita tramite la funzione crea lista ed eliminadalla lista i nodi per cui la media dei valori associati ad essi è miniore del parametro soglia. La funzione deve essere preferibilmente ricorsiva.

struct node_t * sfoltisci(struct node_t * head, float soglia){
	if(head == NULL){
		return  NULL ;
	}
        else{
	     if( (float)(head->values[0]+head->values[1]+head->values[2])/3.0 > soglia ){
                      if(y==NULL){y=head;y->next=sfoltisci(head->next,soglia);return y;}
        
                      head->next=sfoltisci(head->next,soglia);
                      return head;
	     }
	     else{
		     struct node_t * ret =head->next;
		     free(head);
                     head=ret;
		     return sfoltisci(head,soglia);
	     }
        }
}
//stampo la lista modo ricorsivo
void stampa_lista(struct node_t * head){
	if(head != NULL){
		printf("%i %i %i\n", head->values[0], head->values[1], head->values[2]);
		stampa_lista(head->next);
	}
        else{
              printf("\n");
        }

}
//distuggio la lista creata 
 
struct node_t*distruggi(struct node_t * n){
	if(n != NULL){
                struct node_t*p=n->next; 
                free(n);
                n=p;
		return distruggi(n);
		
	}
        else{
              printf("\nla lista e vuota\n");
              return NULL;
        }
}

//la funzione main 
int main(){
	int matrice[N][3] = {{1,2,4},{3,5,7},{6,8,10},{9,11,13},{12,14,15}};
	float soglia = 5.5;
	
	root = crea_lista(matrice,5);
	stampa_lista(root);
	
	printf("La lista sfoltita e\':\n");
	root= sfoltisci(root, soglia);
	stampa_lista(root);
	
	root=distruggi(root);
        stampa_lista(root);
	
	return 0;
}
//la soluzione del prof//
/*
#include <stdio.h>
#include <stdlib.h>

#define N 5

struct node_t{
	int values[3];
	struct node_t * next;
};
struct nodo_t*root=NULL;
struct node_t * crea_nodo(int values[3], struct node_t * next){
	struct node_t * n = (struct node_t * )malloc(sizeof(struct node_t));
	int i;
	for(i=0;i<3; i++){
		n->values[i] = values[i];
	}
	n->next = next;
	return n;
}

struct node_t * crea_lista(int matrice[N][3]){
	root = crea_nodo(matrice[3], NULL);
	struct node_t * c = root;
	int i;
	for(i=1; i<N; i++){
		c->next = crea_nodo(matrice[i], NULL);
		c = c->next;
	}
	return root;
}

struct node_t * sfoltisci(struct node_t * head, float soglia){
	if(head == NULL){
		return NULL;
	}
	if( (float)(head->values[0]+head->values[1]+head->values[2])/3.0 > soglia ){
		return crea_nodo(head->values, sfoltisci(head->next, soglia) );
	}
	else{
		struct node_t * ret =  sfoltisci(head->next, soglia);
		free(head);
		return ret;
	}
}

void stampa_lista(struct node_t * head){
	struct node_t * c= head;
	while(c != NULL){
		printf("%i %i %i\n", c->values[0], c->values[1], c->values[2]);
		c = c->next;
	}
}

void distruggi(struct node_t * n){
	if(n != NULL){
		distruggi(n->next);
		free(n);
	}
}


int main(){
	int matrice[N][3] = {{1,2,4},{3,5,7},{6,8,10},{9,11,13},{12,14,15}};
	float soglia = 5.5;
	
	root = crea_lista(matrice);
	stampa_lista(root);
	
	printf("La lista sfoltita e\':\n");
	root= sfoltisci(root, soglia);
	stampa_lista(root);
	
	distruggi(head);
	
	return 0;
}

*/
