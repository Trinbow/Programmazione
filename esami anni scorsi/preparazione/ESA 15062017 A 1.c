#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct nodo_t{
	char valore;
	struct nodo_t * next;
};

struct nodo_t * crea(char valore, struct nodo_t * next){
	struct nodo_t * n = (struct nodo_t *)malloc(sizeof(struct nodo_t));
	n->valore = valore;
	n->next = next;
	return n;
}
//prototipi delle funzioni 

void stampa_lista(struct nodo_t * nodo);
char * crea_stringa(struct nodo_t * lista);
void stampa_stringa(char * s);
bool isnumber(char c);

// la funzione main 

void main(){
	struct nodo_t * testa = 
	crea('c',crea('0',crea('a',crea('0',crea('9',crea('s',crea('e',crea('3',crea('t',crea('3',crea('6',crea('7',crea('t',crea('8',crea('a',NULL)))))))))))))));
	
	printf("La lista di caratteri e':\n");
	stampa_lista(testa);
	
	char * s = crea_stringa(testa);
	printf("La stringa e':\n");
	stampa_stringa(s);
}
//stampo la lista in modo ricorsivo di caratteri ponendo il simbolo (’-’) tra gli elementi.

void stampa_lista(struct nodo_t * nodo){
      	if(nodo !=NULL){
                printf("%c",nodo->valore);
                if(nodo->next !=NULL){
                    	 printf("-");
                }
  		stampa_lista(nodo->next);
        }
        else{
           	printf("\n");
        }

}

//creo la stringa in modo normale 
char * crea_stringa(struct nodo_t * lista){
       	char * s = (char*)malloc(256 * sizeof(char));
        struct nodo_t * temp=lista;
        int i=0;
        while(temp !=NULL){//faccio un giro nella lista 
		if(isnumber(temp->valore)){//verifico se il carattere e un numero 
    			temp=temp->next;
                }
                else{
 			*(s+i)=temp->valore;
                         i++;
                         temp=temp->next;
                }
        }
        
	return s;//ristituisco l indirizzio della stringa creata 
        
}

//restituisco vero se il carattere e un numero altrimenti falso 
bool isnumber(char c){

return (c <='9' && c>='0');
}
//stampo la stringa
void stampa_stringa(char * s){
	if(*s){
      		printf("%c",*s);
                if(*(s+1)!='\0'){printf("+");}//se il carattere successivo non uguali a '\o' stampa "+"
 		stampa_stringa(s+1);
        }
        else{
        	printf("\n");        
        }
}
