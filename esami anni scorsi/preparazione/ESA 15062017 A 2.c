#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//il nodo 
struct point_t {
    double x;
    double y;
    struct point_t *next;
};

struct point_t*head=NULL;//dechiaro un variabile globale del tipo point_t che punta alla testa della lista

//prototipi delle funzioni 

struct point_t *create_points(double a_x[], double a_y[], int size);
int count_points(struct point_t *points);
void stampa_lista(struct point_t*temp);

void main(){
    double a_x[] = {6, -0.4, -4.5, 9.3};
    double a_y[] = {0, 0.4, 1, 4};
    int size = 4;
    
    // completare
    head=create_points(a_x,a_y,4);
    stampa_lista(head);//stampo la lista
    printf("\nNumero di punti nel primo quadrante: %d\n",count_points(head));
    
    
}

//creo la lista
struct point_t *create_points(double *a_x, double *a_y, int size) {
	struct point_t *temp;
	if(size>0){
		temp=(struct point_t *)malloc(sizeof(struct point_t));
           	temp->x=*a_x;
		temp->y=*a_y;
      		temp->next=create_points(a_x+1,a_y+1,size-1);
             	return temp;
        }
 	else{
  		return NULL;
        }    	      
} 
//restituisco quanti il numero di punti presenti nel primo quadrante dopo aver stampato le loro coordinate.in modo ricorsivo
int count_points(struct point_t *points) {
	int count=0;
      	if(points !=NULL){
		if((points->x) >=0 && (points->y) >=0){
                        int i=count_points(points->next);
                        printf("%d:(%.2lf,%.2lf)\n",points->x,points->y,i+1);
			return 1+i;
		}
		else{
                    return count_points(points->next);
		}
	
	}
	else{
		return count ;
	}

}
//creo la lista in modo ricorsivo 
void stampa_lista(struct point_t*temp){
	if(temp !=NULL){
		printf("(%.2lf,%.2lf)",temp->x,temp->y);
  		if(temp->next !=NULL){
			printf(",");
		}
		stampa_lista(temp->next);	
	}
	else{
		printf("\n");
	}
}
