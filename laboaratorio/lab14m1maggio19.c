#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct n{

    int data ;
    struct n *next;

};

typedef struct n node ; 
node * root=NULL;

//creare una lista versione ricorsiva 
node *creat_list(node *temp,int i){
     
      if(i !=0){
             temp=(node *)malloc(sizeof(node));
             temp->data=i;
             temp->next=NULL;
             if(root==NULL){root=temp;}
             else{
                  node *p=root;
                  while(p->next!=NULL){p=p->next;}
                  p->next=temp;
             }
             printf("\nenter a number :");scanf("%d",&i);
             return creat_list(temp,i);


      }
      else{return root;}

}

//stampa la lista data versione ricorsiva
void stampalist(node *temp){
      if(temp!=NULL){printf("%3d",temp->data);stampalist(temp->next);}
      else{printf("\n");}    
}
//restituisci vero se il valore nella lista e un multiplo di 3.altremente false
bool multipl(int a){
      if(a%3==0){return true;}
      return false;
}
//restituisci quanti multipli ci sono nella lista versione ricorsiva
int quanti_multipli(node *temp){
      int count =0;
      //case base
      if(temp==NULL){return count;}
      else{
          if(multipl(temp->data)){count++;}
      }
      return count+quanti_multipli(temp->next);

}
int main(){
   node *list;
   int val;
   printf("\ninserisci un valore :");
   scanf("%d",&val);
   list=creat_list(list,val);
   stampalist(root);
   printf("\nci sono %d multipli nella lista\n",quanti_multipli(root));

return 0;
}
