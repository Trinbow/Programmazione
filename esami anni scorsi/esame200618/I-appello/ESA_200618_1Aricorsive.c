#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

//prototipi delle funzioni 
struct node_t *crea_lista(char *s);
void  stampa_lista(struct node_t *temp);
void  triplica_vocali(struct node_t *temp);
bool  isvocal(char c);
struct node_t  *add_list(struct node_t  *temp,char v,int n);
struct node_t  *distruggi(struct node_t  *temp);
//il nodo 
struct node_t{
	char value;
	struct node_t * next;
};
struct node_t *root=NULL;  //dechiaro una variabile globale del tipo nodo 



//la funzione main 
int main(){
	char s[] = "la mia stringa";
        int l=strlen(s);
        printf("\n%s |l=%d\n",s,l);
	root = crea_lista(s);
	stampa_lista(root);
	triplica_vocali(root);
	stampa_lista(root);
        root=distruggi(root);
        stampa_lista(root);
	return 0;
}

//creo la lista di carratteri modo ricorsivo  
struct node_t *crea_lista(char *s){

     /*if(*s){
        struct node_t *temp;
        temp=(struct node_t *)malloc(sizeof(struct node_t));
        temp->value=*s;
        temp->next=NULL;
        if(root==NULL){root=temp;}
        else{
             struct node_t *p=root;
             while(p->next!=NULL){p=p->next;}
             p->next=temp;
        }
        return crea_lista(s+1);    
     }
     else{return root;}*/

        if(*s){
             struct node_t *temp;
             temp=(struct node_t *)malloc(sizeof(struct node_t));
             temp->value=*s;
             temp->next=crea_lista(s+1);
             return temp;
            
        }
        else{return NULL;}

}




//stampo la lista modo ricorsivo 
void  stampa_lista(struct node_t *temp){
     if(temp !=NULL){
          printf("%2c",temp->value);
          stampa_lista(temp->next);
     }
     else{printf("\n\n");}

}
//la funzione triplica vocali riceve in input una lista (il puntatore al primo nodo) e triplica i nodi della  lista che contengono delle vocali. La funzione deve essere preferibilmente ricorsiva.

void  triplica_vocali(struct node_t *temp){
       if(temp !=NULL){
             if(isvocal(temp->value)){
                  temp->next=add_list(temp->next,temp->value,0);
                  triplica_vocali(temp->next->next->next);
             }
             else{
                  triplica_vocali(temp->next);
             }
       }
       else{
         printf("\n\n");
       }



}

//restituisco vero se il valore c vocali altrimente falso 

bool  isvocal(char c){

    return (c=='a' || c =='e' || c =='i' || c =='o' || c =='u' );

}
//la funzione add list che crea una nuova lista di due nodi che contiene il vocali al posizione i della lista originali modo ricorsivo
struct node_t  *add_list(struct node_t  *temp,char v,int n){
        if(n<2){
             struct node_t *p;
             p=(struct node_t *)malloc(sizeof(struct node_t));
             p->value=v;
             p->next=temp;
             return add_list(p,v,n+1);
           
        }
        else{
             
             return temp;
        }

}
//distruggio la lista creata in modo ricosivo 
struct node_t  *distruggi(struct node_t  *temp){
     
      /*  if(temp !=NULL){
               struct node_t *p=temp->next;
               free(temp);
               temp=p;
               distruggi(temp);  
        }
        else{
              printf("\nla lista e vuota .\n");
        }
      */
     //base case
     if(temp==NULL){printf("\nla lista e vuota .\n");return NULL;}
     struct node_t *p=temp->next;
     free(temp);
     temp=p;
     return distruggi(temp->next);

}
