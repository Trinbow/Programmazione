#include<stdio.h>
#include<stdlib.h>

struct node{
     int data ;
     struct node *next;



};

struct node *root=NULL;

struct node *creat_list(struct node *temp,int val){
      temp=(struct  node *)malloc(sizeof(struct node));
      temp->data=val;
      temp->next=NULL;
      if(root==NULL){root=temp;}
      else{
          struct node *p;
          p=root;
          while(p->next !=NULL){
                p=p->next;
          }
          p->next=temp;
      }

    return root;  
}
void stampa_list(struct node *temp){

      temp=root;
      if(temp==NULL){printf("\nla lista e' vuota.\n");}
      else{

          while(temp !=NULL){printf("%3d",temp->data);temp=temp->next;}
          printf("\n\n");

      }

}
 struct node* reverse(struct node* node) 
    { 
        if (node == NULL) 
            return NULL; 
        if (node->next == NULL) { 
            root = node; 
            return node; 
        } 
        struct node* node1 = reverse(node->next); 
        node1->next = node; 
        node->next = NULL; 
        return node; 
    } 

int main(){

      int val;
      struct node *list;
      do{
          scanf("%d",&val);
          if(val!=-1)
           
           list=creat_list(list,val);  

   	}while(val !=-1);



     stampa_list(list);
     list=reverse(list);
     stampa_list(list);



return 0;
}
