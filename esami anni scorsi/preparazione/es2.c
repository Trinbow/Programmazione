#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct articolo{
	char tipo;
	float costo;
	
	struct articolo * prossimo;
};

struct articolo *root=NULL;
struct articolo * crea_lista(char * tipi, float * costi, int numero){
       struct articolo * temp;
       if(numero>0){
            temp=(struct articolo *)malloc(sizeof(struct articolo ));
            temp->tipo=*tipi;
            temp->costo=*costi;
            temp->prossimo=crea_lista(tipi+1,costi+1,numero-1);
            return temp;
       }
       else{return NULL;}        
}

void stampa_articoli(struct articolo * magazzino){
      if(magazzino==NULL){printf("\n");}
      else{
                printf("(%c,%.2f)",magazzino->tipo,magazzino->costo);
                if(magazzino->prossimo !=NULL){printf(",");}
                stampa_articoli(magazzino->prossimo);
      }
}


struct articolo * piu_costoso(struct articolo * magazzino){
 
       struct articolo*max=magazzino;
       while(magazzino !=NULL){
                 if(max->costo< magazzino->costo){
                 	max=magazzino;
          
                 }
       magazzino=magazzino->prossimo;
      }
      return max;
       
}

char piu_disponibile(struct articolo * magazzino){
        
}

float ordina(struct articolo * magazzino, char * ordine, int dimensione_ordine){
}


int main(void){
	int numero = 7;
	char tipi[7] = {'a','b','b','a','c','d','b'};
	float costi[7] = {1.20, 1.30, 0.9, 2.1, 4.5, 6.7, 0.75};
	
	struct articolo * articoli = crea_lista(tipi, costi, numero);
	stampa_articoli(articoli);
	
	struct articolo * costoso = piu_costoso(articoli);
	//STAMPA ARTICOLO PIU' COSTOSO
	printf("\nl’articolo piu’ costoso e’ (%c,%.2f)\n",costoso->tipo,costoso->costo);
	char disponibile = piu_disponibile(articoli);
	//STAMPA ARTICOLO CON PIU' DISPONIBILITA'
        printf("\nla tipologia con piu’ disponibilita’ e’ la %c\n",disponibile);
	
	char ordine_1[4] = {'a','a','b','c'};
	float costo_ordine = ordina(articoli, ordine_1, 4);
	//STAMPA COSTO TOTALE ORDINE 1, SE DISPONIBILE
	
	char ordine_2[4] = {'a','b','c','c'};
	costo_ordine = ordina(articoli, ordine_2, 4);
	//STAMPA COSTO TOTALE ORDINE 2, SE DISPONIBILE*/
	
	return 0;
}
