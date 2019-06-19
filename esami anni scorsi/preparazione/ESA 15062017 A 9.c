#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// la struttura articolo 
struct articolo{
	char tipo;
	float costo;
	
	struct articolo * prossimo;
};
// dechiaro variabili globali  
int massimo;
int ma;
char c;
int d;
struct articolo *root=NULL,*max;

//prototipi delle funzioni 
int lunghezza(struct articolo *l);
struct articolo * crea_lista(char * tipi, float * costi, int numero);
void stampa_articoli(struct articolo * magazzino);
struct articolo * piu_costoso(struct articolo * magazzino);
char piu_disponibile(struct articolo * magazzino);
float ordina(struct articolo * articoli, char * ordine, int dimensione_ordine);
struct articolo* dealloca(struct articolo *t);
int piu_disp(int y[],int i);

//creo la lista in modo ricorsivo 
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
//stampo la lista creata in modo ricorsivo
void stampa_articoli(struct articolo * magazzino){
      if(magazzino==NULL){printf("\n");}
      else{
                printf("(%c,%.2f)",magazzino->tipo,magazzino->costo);
                if(magazzino->prossimo !=NULL){printf(",");}
                stampa_articoli(magazzino->prossimo);
      }
}

// restituisco l articolo il piu costoso nella lista in modo ricorsivo 
struct articolo * piu_costoso(struct articolo * magazzino){
 
	if(magazzino !=NULL){
		struct articolo*next=piu_costoso(magazzino->prossimo);
		if(max->costo < magazzino->costo){
			max=magazzino;
		}
		return max ;
	}
	else{
		return max;
	}
	
}
//restituisco il carattere il piu disponibile nella lista in modo ricorsivo 

char piu_disponibile(struct articolo * magazzino){
	if(magazzino !=NULL){
		struct articolo *temp=magazzino->prossimo;
		int som =1;
		while(temp !=NULL){
			if(temp->tipo == magazzino->tipo){
				som++;
			}
			temp=temp->prossimo;	
		}
		if(massimo < som){
			massimo=som;
			c=magazzino->tipo;	
		}
		return piu_disponibile(magazzino->prossimo);
	}
	else{
		return c;	
	}        
}
//oridina 

float ordina(struct articolo * articoli, char * ordine, int dimensione_ordine){
	int num_articoli = lunghezza(articoli);
	bool * preso = (bool *)malloc(sizeof(bool) * num_articoli);
	int i;
	for(i=0; i<num_articoli;i++){
		preso[i] = false;
	}
	
	float costo = 0.0;
	
	for(i=0; i<dimensione_ordine; i++){
		struct articolo * c = articoli;
		int j = 0;
		while(c != NULL){
			if((c->tipo == ordine[i]) && (preso[j] == false)){
				costo += c->costo;
				preso[j] = true;
				break;
			}
			c = c->prossimo;
			j++;
		}
		if(c == NULL){
			costo = 0.0;
			break;
		}
	}
	
	return costo;
}

//la funzione main 
int main(void){
	int numero = 7;
	char tipi[7] = {'a','b','b','a','c','d','b'};
	float costi[7] = {1.20, 1.30, 0.9, 2.1, 4.5, 6.7, 0.75};
	int y[7]={1,3,2,3,4,3,6};
	
	struct articolo * articoli = crea_lista(tipi, costi, numero);
	stampa_articoli(articoli);
	max=articoli;
	struct articolo * costoso = piu_costoso(articoli);
	//STAMPA ARTICOLO PIU' COSTOSO
	printf("\nl’articolo piu’ costoso e’ (%c,%.2f)\n",costoso->tipo,costoso->costo);
	char disponibile = piu_disponibile(articoli);
	//STAMPA ARTICOLO CON PIU' DISPONIBILITA'
        printf("\nla tipologia con piu’ disponibilita’ e’ la %c\n",disponibile);
	//stampa il numero con pisu disponibilita
        int disp=piu_disp(y,7);
	printf("\nla tipologia con piu’ disponibilita’ e’ la %d\n",disp);
	char ordine_1[4] = {'a','a','b','c'};
	float costo_ordine = ordina(articoli, ordine_1, 4);
	//STAMPA COSTO TOTALE ORDINE 1, SE DISPONIBILE
	if(costo_ordine >0.0){
		printf("\nil costo totale dell’ordine e’ %.2f\n",costo_ordine);
	}
	else{
		printf("\nl’ordine non e’ diposnibile\n");
	}
	
	char ordine_2[4] = {'a','b','c','c'};
	costo_ordine = ordina(articoli, ordine_2, 4);
	//STAMPA COSTO TOTALE ORDINE 2, SE DISPONIBILE*/
	if(costo_ordine >0.0){
		printf("\nil costo totale dell’ordine e’ %.2f\n",costo_ordine);
	}
	else{
		printf("\nl’ordine non e’ diposnibile\n");
	}
	//destruggio la lista
	articoli= dealloca(articoli);
	//stampo la lista
	stampa_articoli(articoli);
	return 0;
}
//restitiusco il numero piu disponibile nell array in modo ricorsivo
int piu_disp(int y[],int i){
	if(i>0){
		int j=7-i+1;
		int som=1;
		while(j<7){
			if(*(y+i)==*(y+j)){
				som++;		
			}
			j++;	
		}
		if(ma<som){
			ma=som;
			d=*y;
		}
		return piu_disp(y+1,i-1);	
	}
	else{
		return d;	
	}
}
//restituisco la lunghezza della lista
int lunghezza(struct articolo *l){
	
	if(l != NULL){
		return 1+lunghezza(l->prossimo);
		
	}
	else{
		return 0;
	}

}
//distruggo la lista in modo ricorsivo 
struct articolo* dealloca(struct articolo*t){
	if(t !=NULL){
		struct articolo *temp=t->prossimo;
		free(t);
		t=temp;
		return dealloca(t);
	}
	else{
		printf("\nla lista e vuota .\n ");
		return NULL;	
	}

}
