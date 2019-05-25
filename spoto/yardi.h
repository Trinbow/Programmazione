#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct n{
     int data ;
     struct n *next;
};
typedef struct n node ;
node *root=NULL;


//prototipi delle funzioni 
node *creat_list(node *temp,int i );
void stampalist(node *temp);
bool sempre_diversi(node *this);
bool uguali(int a,int b);
//creare una lista versione ricorsiva
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
//stampa lista versione ricorsiva
void stampalist(node *temp){
      if(temp==NULL){printf("\n");}
      else{printf("%3d",temp->data);stampalist(temp->next);}
}
//ristituisce se le numeri sono 

bool sempre_diversi(node *this){
   /* //node *p=this->next;
    if(this->next==NULL){return true;}
    if(uguali(this->data,this->next->data)){return false;}
    return sempre_diversi(this->next);*/
 return !this || !this->next || (uguali(this->data , this->next->data)  && sempre_diversi(this->next));
}
//restit
bool uguali(int a,int b){

    /*if(a==b){return true;}
    return false;*/
    return ! (a==b);
}



