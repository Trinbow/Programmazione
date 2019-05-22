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
#include<stdbool.h>



struct n{

     int data ;

     struct n *next;
};

typedef struct n node ;

node *root=NULL;


//creare una lista
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
//stampa una lista
void stampa(node *temp){
    //  if(temp==NULL){printf("\nla lista e' vuota");}
      if(temp !=NULL){printf("%3d",temp->data);stampa(temp->next);}
      else{printf("\n");}
}
//reverse of list
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
//quanti multipli di 3 ci sono nella lista
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

//come cancellare la lista con 2 puntatori
/*void delete(node **temp){
     node *t1=*temp,*next;
     while(t1!=NULL){
         next=t1->next;
         free(t1);
         t1=next;


     }


      *temp=NULL;
}*/
//come cancellare tutta la lista
/*node *destroy(node *temp){
     node *current=temp,*next;
     while(current !=NULL){
         next=current->next;
         free(current);
         current=next;
     }

     temp=NULL;
return temp;
}*/
//come cancellare la lista con ricorsiva
node*destroy(node *temp){
     //base case
     if(temp==NULL){return NULL;}
     node*p=temp->next;
     free(temp);
     temp=p;
     return destroy(temp->next);
}
//come sapere la lunghezza della lisra data
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

//come cancellare un nodo della lista
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

/*inserisce un nuovo numero in testa alla lista*/
node *inserisciIntesta(node *temp){
     int num;
     printf("\ninserisci un numero :");
     scanf("%d",&num);
     node *p;
     p=(node *)malloc(sizeof(node));
     p->data=num;
     p->next=NULL;
     if(temp==NULL){temp=p;}
     else{
        p->next=temp;
        temp=p;
     }
return temp ;
}
/*inserisce un nuovo numero nel meglio della lista*/
node *inserisci_middle(node *temp){
     int num,i=1,loc;
     printf("\ninserisci un numero :");
     scanf("%d",&num);
     node *p,*q;
     p=(node *)malloc(sizeof(node));
     p->data=num;
     p->next=NULL;
     printf("\ninserisci locale :");
     scanf("%d",&loc);
     if(loc >lenght(root)){printf("\nINvalid location\n");}
     else{
         q=temp;
         while(i<=loc-1){q=q->next;i++;}
         p->next=q->next;
         q->next=p;
     }

return temp ;
}
//find elemnt in the lista
int find(node *temp,int x){
       int flag=0;
       if(temp==NULL){return 0;}
       else{
          if(temp->data==x){flag=1;}
          else{
            flag=find(temp->next,x);}
       }

       if(flag==1){return 1;}
       return 0;
       //base case
       /*if(temp==NULL){return false;}
       //uguali al numero cercato
       if(temp->data==x){return true;}

       return find(temp->next,x);*/
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
     int x;
     printf("\ninserici il valore cercato: ");
     scanf("%d",&x);
     printf("\nrisultato=%d\n",find(root,x));
     list=reverse(root);
     stampa(root);
     printf("\nci sono %d multipli di 3.\n",countm(root));
     root=inserisci_middle(root);
     stampa(root);
     root=inserisciIntesta(root);
     stampa(root);
     root=delete_node(root);
     stampa(root);
     root=destroy(list);
     //delete(&root);
     stampa(root);
     printf("\nthe end\n");

return 0;

}
