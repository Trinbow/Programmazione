#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


//prototipi delle funzioni 
struct nodo * crea_lista(int   * a, int l);
void stampa_lista(struct nodo * temp);
struct nodo * riverse_list(struct nodo * list);
struct nodo*destroy(struct nodo*temp);
struct nodo{
	int  x;
	
	struct nodo * next;
};
//creo la lista in modo ricorsivo 
struct nodo * crea_lista(int   * a, int l){
	if(l>0){
		struct nodo*temp;
		temp=(struct nodo*)malloc(sizeof(struct nodo));
		temp->x=*a;
		temp->next=crea_lista(a+1,l-1);
		return temp;
	}
	else{
		return NULL;
	}

}
//stampo la lista in modo ricorsivo
void stampa_lista(struct nodo * temp){
	if(temp !=NULL){
		printf("%d",temp->x);
		if(temp->next !=NULL){
			printf("->");
		}
		stampa_lista(temp->next);	
	}
	else{
		printf("\n");
	}
}

//faccio la ricorsiva della lista
struct nodo*lista; 
struct nodo * riverse_list(struct nodo * list){

	/*if(head->next ==NULL){
			lista =head;
			return head; 	
	}
	if(head !=NULL){
		struct nodo * node1=riverse_list(head->next);
		node1->next=head;
		head->next=NULL;
		return head;	
	
	}
	else{
		return NULL;
	}*/
	struct nodo *revHead;
	if (list == NULL || list->next == NULL)
	{
        	return list;
    	}

    	revHead =riverse_list(list->next);
    	list->next->next = list;
    	list->next = NULL; 

    return revHead;
}


//la funzione main
int main(void){
	int l = 10;
	
	int y[10] = {11,1,2,3,4,15,6,10,0,8};
	
	struct nodo*root= crea_lista(y, l);
	stampa_lista(root);
	root=riverse_list(root);
	//root=lis;
	stampa_lista(root);
	root=destroy(root);
	stampa_lista(root);	
	
	return 0;
}
struct nodo*destroy(struct nodo*temp){
	if(temp !=NULL){
		struct nodo*p=temp->next;
		free(temp);
		temp=p;
		return destroy(temp->next);
	}
	else{
		printf("\nla lista e vuota .\n");
		return NULL;
	}

}
