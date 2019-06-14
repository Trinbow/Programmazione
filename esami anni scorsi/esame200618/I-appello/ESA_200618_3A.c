#include <stdlib.h>
#include <stdio.h>

/* ci sono diverse soluzioni al problema. Una tra queste è rappresentata dal seguente codice:
 */


struct list {
    int head;
    struct list *tail;
};

struct list *static_pointer_to_list;

struct list *genera_lista_din(int i){
    struct list *tmp = (struct list *)malloc(sizeof(struct list));
    //passo base raggiungo il 4 'elemento' ovvero NULL
    if (i==0)
	    return NULL;
    //passo ricorsivo crea un nodo con head=i, decremento i e chiamo ricorsivamente la funzione
    else{
        tmp->head=i;
        tmp->tail=genera_lista_din(i-1);
        return tmp;
    }
	
}

//stampo la lista
void stampa_lista(struct list *temp){
        if(temp !=NULL){
               printf("%3d",temp->head);
               stampa_lista(temp->tail);
        }
        else{printf("\n");}
  
}

int main(void) {
    struct list *a=genera_lista_din(3);
    static_pointer_to_list=a;
    // IN QUESTO PUNTO CI SI TROVA NELLO STATO RAPPRESENTATO NELL'IMMAGINE
    stampa_lista(a);
}
