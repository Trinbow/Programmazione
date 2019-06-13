#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

//prototipi delle funzioni 
struct node_t *crea_lista(char *s);
void  stampa_lista(struct node_t *temp);
void  sostituisci_vocali(struct node_t *temp);
bool  isvocali(char c);

struct node_t *add_list(struct node_t *temp,char *s);
struct node_t *distruggi(struct node_t*temp);


//la struttura struct node_t
struct node_t{
       char c;
       struct node_t*next;
    
};


struct node_t*root=NULL;//dechiaro una variabile globale del tipo struct node_t

//la funzione main 
int main(){
	char s[] = "la mia stringa";
        root = crea_lista(s);
	stampa_lista(root);
	
	/*struct node_t * sostituto = add_list();
	stampa_lista(sostituto);*/
	
	sostituisci_vocali(root);
	stampa_lista(root);
	
	root=distruggi(root);
        stampa_lista(root);
	return 0;
}
//creo la lista modo ricorsivo
struct node_t *crea_lista(char *s){
        if(*s){
             struct node_t*temp;
             temp=(struct node_t*)malloc(sizeof(struct node_t));
             temp->c=*s;
             temp->next=crea_lista(s+1);
             return temp;
     
        }
        else{
             return NULL;
        } 
    
}
//stampo la lista modo ricorsivo 
void  stampa_lista(struct node_t *temp){
       if(temp !=NULL){
             printf("%c",temp->c);
             stampa_lista(temp->next);
       }
       else{printf("\n");}

}
//sostituisce i nodi  della lista che contengono delle vocali con una copia della lista sostituto fornita nel main. Si suppone  che la prima lettera della lista non sia mai una vocale.



void  sostituisci_vocali(struct node_t *temp){
       
      if(temp==NULL){
               printf("\n");}
      else{
               if(isvocali(temp->c)){
                     char ch,s1[]="->";
                     ch=temp->c;
                     temp->c='<';
                     temp->next=add_list(temp->next,s1);
                     sostituisci_vocali(temp->next->next->next);
               }
               else{
                   sostituisci_vocali(temp->next);
               }
      }

 
}
//creo la lista
struct node_t *add_list(struct node_t *temp,char *s){
      if(*s){
             struct node_t*p;
             p=(struct node_t*)malloc(sizeof(struct node_t));
             p->c=*s;
             p->next=add_list(temp,s+1);
             return p;
     
        }
        else{
             return temp;
        } 

}
//distruggo la lista in modo ricorsivo 
struct node_t *distruggi(struct node_t*temp){
   
      if(temp  !=NULL){
              struct node_t*p=temp->next;
              free(temp);
              temp=p;
              return distruggi(temp->next);
                            
      }
      else{printf("\nla lista e vuota.\n");return NULL;}



}
//verifico se il valore vocali o no 
bool  isvocali(char c){
     return (c=='a' ||  c=='e' ||  c=='i' || c=='o' ||  c=='u' );

}
