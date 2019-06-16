#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


//il nodo 
struct nodo_t{
	char valore;
	struct nodo_t * next;
};
//prototipi delle funzioni
char * leggi();
struct nodo_t * crea_lista(char * s);
void stampa(struct nodo_t * nodo);
bool isnumber(char c);

void main(){
	printf("Inserire una stringa:\n");
	char * s = leggi();
	
	struct nodo_t * testa = crea_lista(s);
	printf("La lista e':\n");
	stampa(testa);
}
//leggo la stringa
char * leggi(){
	char * s = (char*)malloc(256 * sizeof(char));
	scanf("%256s", s);
	return s;
}
//creo la stringa in modo ricorsivo 
struct nodo_t *crea_lista(char *s){
        if(*s){
             
             if(!(isnumber(*s))){
                  struct nodo_t* temp;
                  temp=(struct nodo_t* ) malloc(sizeof(struct nodo_t));
                  temp->valore=*s;
                  temp->next=crea_lista(s+1);
             }
             else{
                   struct nodo_t* temp;
                   temp->next=crea_lista(s+1);}
             return temp;
     
        }
        else{
             return NULL;
        } 
    
}
//stampo la lista in modo ricorsivo
void stampa(struct nodo_t * temp){
       if(temp==NULL){printf("\n");}
       else{
             printf("%c",temp->valore);
             printf("->");
             stampa(temp->next);
     
       }
}
bool isnumber(char c){

return (c <='9' && c>='0');
}
