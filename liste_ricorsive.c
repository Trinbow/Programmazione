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
node *add_list(node *temp,int i){
      /* temp=(node*)malloc(sizeof(node));
       temp->data=v;
       temp->next=NULL;
       if(root==NULL){root=temp;}
       else{
           node *p=root;
           while(p->next !=NULL){p=p->next;}
           p->next=temp;

       }
return root;*/
      if (i!=0){
            temp=(node*)malloc(sizeof(node));
            temp->data=i;
            temp->next=NULL;
            if(root==NULL){root=temp;}
            else{
                node *p=root;
                while(p->next !=NULL){p=p->next;}
                p->next=temp;
              }
              scanf("%d",&i);
              return add_list(temp,i);

      }
      else{return root;}
}
//stampa la lista creata
void printlist(node *temp){
      //base case
      if(temp ==NULL){printf("\n");}
      else{printf("%3d",temp->data);printlist(temp->next);}
}
//cancella tutti gli elementi della lista con ricorsiva
node*destroy(node *temp){
     //base case
     if(temp==NULL){return NULL;}
     node*p=temp->next;
     free(temp);
     temp=p;
     return destroy(temp->next);
}
//esiste elemento nella lista using ricorsive
bool esiste(node*temp,int x){
      //base case
      if(temp==NULL){return false;}
      if(temp->data==x){return true;}
      return esiste(temp->next,x);
}
//trova il massimo nella lista ricorsiva
int massimo(node *temp,int max){
       //base case
       if(temp==NULL){return max;}
       if(temp->data>=max){max=temp->data;}
       return massimo(temp->next,max);
}
int main(){
    int v;
    node *list;
    scanf("%d",&v);
    list=add_list(list,v);

    printlist(root);
    int x;
    printf("\ninserisci il numero :");
    scanf("%d",&x);
    printf("\nris=%d",esiste(root,x));
    printf("\nmax=%d\n",massimo(root,0));
    root=destroy(list);
    printlist(root);
    printf("\nthe end\n");
  return 0   ;
}
