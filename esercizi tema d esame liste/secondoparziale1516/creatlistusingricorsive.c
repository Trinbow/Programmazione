#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct n{
     int data ;
     struct n *next;
};
typedef struct n node ;
node *root=NULL;

//crear una lista using array
node *creat_list(node *temp,int i ){
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
                  return creat_list(temp,i);

       }
       else{return root;}

}
//stampa lista
void stampalist(node *temp){
      if(temp==NULL){printf("\n");}
      else{printf("%3d",temp->data);stampalist(temp->next);}
}

int main(){
    node *list;
    int x;
    scanf("%d",&x);
    list=creat_list(list,x);
    stampalist(root);




  return 0 ;
}
