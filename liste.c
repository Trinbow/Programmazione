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

return 0;

}
