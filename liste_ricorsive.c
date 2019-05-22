#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
//lista
struct n{
   int data;
   struct n *next;

};

typedef struct n node ;
node *root=NULL;
//crea una nuova lista
node *add_list(node *temp,int v){
       temp=(node*)malloc(sizeof(node));
       temp->data=v;
       temp->next=NULL;
       if(root==NULL){root=temp;}
       else{
           node *p=root;
           while(p->next !=NULL){p=p->next;}
           p->next=temp;

       }
return root;
}
//stampa la lista creata
void printlist(node *temp){
      //base case
      if(temp ==NULL){printf("\n");}
      else{printf("%3d",temp->data);printlist(temp->next);}
}
//cancella tutti gli elementi della lista con ricirsive
node*destroy(node *temp){
     //base case
     if(temp==NULL){return NULL;}
     node*p=temp->next;
     free(temp);
     temp=p;
     return destroy(temp->next);
}
int main(){
    int v;
    node *list;
    do{
       scanf("%d",&v);
       if(v!=-1)
         list=add_list(list,v);
    }while(v !=-1);

    printlist(root);
    root=destroy(root);
    printlist(root);
    printf("\nthe end\n");





  return 0   ;
}
