#include<stdio.h>
#include<stdlib.h>

struct node{
  int data;
  struct node* link ;
};
struct node * root=NULL;
int len;
void display(void){
     struct node* temp ;
     temp=root;
     if(temp==NULL){printf("\nthe lis is empty");}
     else{
         while(temp !=NULL){
             printf("%3d",temp->data);
             temp=temp->link;
         }
         printf("\n\n");
     }
}
void appned(void){
  struct node* temp ;
  temp=(struct node*)malloc(sizeof(struct node));
  printf("\nenter data :");
  scanf("%d",&temp->data);
  temp->link=NULL;
  if(root==NULL){root=temp;}
  else{
    struct node*p;
    p=root;
    while(p->link !=NULL){
        p=p->link;
    }
    p->link=temp;
  }
}
int lenght(void){
      int count=0;
      struct node* temp;
      temp=root;

      while(temp!=NULL){
        count++;
        temp=temp->link;
      }

return count;
}
int main(){
  int ch;
  while(1){
    printf("\nprogramme hamouda :\n");
    printf("\n1.appned\n\n2.addatbgin\n\n3.Lenght\n\n4.Delet\n\n5.display\n\n6.exit\n");

    printf("\nenter your choice :");
    scanf("%d",&ch);

    switch(ch){
        case 1:  appned();
                    break;
        //case 2:  addatbgin();
            //      break;
        case 3:  len=lenght();
                 printf("len=%d\n",len);
                  break;
        //case 4:  delet();
          //       break;
        case 5:  display();
                   break;
        case 6:    exit(1);
                   break;
        default :   printf("invalid choice \n");
    }
  }




}
