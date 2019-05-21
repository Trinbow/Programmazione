/*#include<stdio.h>
#include<stdlib.h>
struct n{
  int data;
  struct n *next;

};
typedef struct n node ;
node *root=NULL;

node *creat_list(node *temp,int val){

      temp=(node*)malloc(sizeof(node));
      temp->data=val;
      temp->next=NULL;
      if(root==NULL){root=temp;}
      else{
          node *p=root;
          while(p->next !=NULL){p=p->next;}
          p->next=temp;
      }

  return root;
}
node* stampa_list(node *temp){
       if(temp==NULL){return NULL;}
       if(temp !=NULL){
          printf("%3d",temp->data);
          temp=stampa_list(temp->next);
       }
       printf("\n");

  return temp;
}
int main() {
  int val;
  node *list;
  do{
    scanf("%d",&val);
    if(val !=-1){list=creat_list(list,val);}

  }while(val !=-1);
  list=stampa_list(root);


  return 0;
}*/
#include<stdio.h>

#include<stdlib.h>



struct n{

     int data ;

     struct n *next;
};

typedef struct n node ;

node *root=NULL;



node *creat_list(node *temp,int val){

      temp=(node *)malloc(sizeof(node));

      temp->data=val;

      temp->next=NULL;

      if(root==NULL){root=temp;}

      else{

          node *p;

          p=root;

          while(p->next !=NULL){

                p=p->next;

          }

          p->next=temp;

      }



    return root;

}

void stampa(node *temp){
    //  if(temp==NULL){printf("\nla lista e' vuota");}
      if(temp !=NULL){printf("%3d",temp->data);stampa(temp->next);}
      else{printf("\n");}
}

 node* reverse(node* temp)

    {

        if (temp == NULL)

            return NULL;

        if (temp->next == NULL) {

            root = temp;
            //printf("\nifnode=%d\n",node);
            return temp;

        }

        node* node1 = reverse(temp->next);

        node1->next = temp;

        temp->next = NULL;
        //printf("\nnode=%d\n",node);
        return temp;

}
int  countm(node* temp)

    {
         int count=0;
        if (temp == NULL)

            return count;

        if (temp != NULL) {

            if(temp->data %3==0){count++;}

        }
      count=count+countm(temp->next);
return count;
}
/*void delete(node **temp){
     node *t1=*temp,*next;
     while(t1!=NULL){
         next=t1->next;
         free(t1);
         t1=next;


     }


      *temp=NULL;
}*/
node *destroy(node *temp){
     node *current=temp,*next;
     while(current !=NULL){
         next=current->next;
         free(current);
         current=next;
     }

     temp=NULL;
return temp;
}

int lenght(node *temp){
     int count =0;
     if(temp==NULL){return 0;}
     if(temp !=NULL){count=1+lenght(temp->next);}
     /*while(temp!=NULL){
        count++;
        temp=temp->next;
    }*/
return count;
}
node * delete_node(node *temp){
     node*p=temp,*q;
     int loc,i=1;
     printf("\nenter the location:");
     scanf("%d",&loc);
     if(loc >lenght(root)){printf("\nINvalid location\n");}
     if(loc==1){temp=p->next;p->next=NULL;free(p);}
     else{
         while(i<loc-1){p=p->next;i++;}
         q=p->next;
         p->next=q->next;
         q->next=NULL;
         free(q);
     }
  return temp;
}
int main(){

      int val;

      node *list;
      do{
          scanf("%d",&val);
          if(val!=-1)
          list=creat_list(list,val);
    	}while(val !=-1);

     stampa(root);
     list=reverse(root);
     stampa(root);
     printf("\nci sono %d multipli di 3.\n",countm(root));
     root=delete_node(root);
     stampa(root);
     root=destroy(root);
     //delete(&root);
     stampa(root);
     printf("\nthe end\n");

return 0;

}
