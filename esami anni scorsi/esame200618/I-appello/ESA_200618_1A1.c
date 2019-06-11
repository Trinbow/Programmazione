#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdbool.h>


//prottotipi delle funzioni 
struct node_t* crea_lista(char *s);
void stampa_lista(struct node_t*temp);
void  triplica_vocali(struct node_t*temp);
struct node_t* distruggi(struct node_t*temp);
bool isvocal(char c);
struct node_t * crea_mlista(char v, struct node_t * next);



//crea il nodo 
struct node_t{
	char value;
	struct node_t * next;
};
struct node_t* root=NULL;//dechiaro un puntatore che punata ala testa della lista come un variabile globale 

//la funzione main 
int main(){
	char s[] = "la mia stringa";
	root = crea_lista(s);
	stampa_lista(root);
	triplica_vocali(root);
	stampa_lista(root);
        stampa_lista(root);
	return 0;
}


//creo una lista da una stringa 
struct node_t* crea_lista(char *s){

     struct node_t *temp;
     int size=strlen(s);printf("\nsize=%d\n",size);    
     int i;
     for(i=0;i<size;i++){
            temp=(struct node_t *)malloc(sizeof(struct node_t));
            temp->value=s[i];
            temp->next=NULL;
            if(root==NULL){root=temp;}
            else{
                struct node_t *p=root;
                while(p->next !=NULL){p=p->next;}
                    p->next=temp;
                }

     }
      


return root;

}
//stampo la lista
void stampa_lista(struct node_t*temp){
       if(temp==NULL){
           printf("\nla lista e vuota .\n");
       }
       else{
           while(temp !=NULL){
                printf("%2c",temp->value);
                temp=temp->next;
            }
            printf("\n\n");
      }
}

//la funzione che triplica i vocali in modo ricorsivo 
void  triplica_vocali(struct node_t*temp){
    
    if(temp !=NULL){
         if(isvocal(temp->value)){
              temp->next = crea_mlista(temp->value,temp->next);
	      triplica_vocali(temp->next->next->next);
              
         }
         else{
              triplica_vocali(temp->next);
         }         

    }
    else{printf("\n\n");}
}


//verifica se il valore e un vocali o no 
bool isvocal(char c){

return (c=='a' ||c=='u' ||c=='e' ||c=='i' ||c=='o' );
}

struct node_t * crea_mlista(char v, struct node_t * next){
     struct node_t *head=NULL;
     int i;
     for(i=0;i<2;i++){
            struct node_t *temp;
            temp=(struct node_t *)malloc(sizeof(struct node_t));
            temp->value=v;
            temp->next=NULL;
            if(head==NULL){head=temp;}
            else{
                struct node_t *p=head;
                while(p->next !=NULL){p=p->next;}
                    p->next=temp;
                }
                if(i==1){temp->next=next;}

     }
      


return head;
}
