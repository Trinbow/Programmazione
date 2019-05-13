#include<stdio.h>
#include<stdlib.h>

struct elemnt_t{
     int data;
     struct elemnt_t *link;

};
struct elemnt_t *root=NULL;
void print_list(struct elemnt_t *temp){
  temp=root;
  while(temp !=NULL){printf("%3d",temp->data);temp=temp->link;}printf("\n\n");
}
int isdispari(int a){
  if(a%2 !=0){return 1;}
  return 0;
}
struct elemnt_t *creat_odd_list(int arr[],int size){
        int i;
        struct elemnt_t *temp;
        for(i=0;i<size;i++){
            if(isdispari(arr[i])){
                temp=(struct elemnt_t *)malloc(sizeof(struct elemnt_t));
                temp->data=arr[i];
                temp->link=NULL;
                if(root==NULL){root=temp;}
                else{
                    struct elemnt_t *p=root;
                    while(p->link !=NULL){p=p->link;}
                    p->link=temp;
                }

            }
        }

  return root;
}
void stampaArray(int arr[],int size){
       int i;
       for(i=0;i<size;i++){
           printf("%3d",arr[i]);
       }
       printf("\n\n");
}
int main() {
  int size=8;
  int arr[]={8,3,1,3,9,4,6,5};

  struct elemnt_t *lista=creat_odd_list(arr,size);
  stampaArray(arr,size);





  print_list(lista);

  return 0;
}
