#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct n{
     int data ;
     struct n *next;
};
typedef struct n node ;
node *root=NULL;
//is dispari
bool isdispari(int a){
      if(a%2!=0){return true;}
      return false ;
}
//crear una lista using array
int i=8;
node *creat_list(node *temp,int arr[],int n){
       if (n!=0){
            if(isdispari(arr[i-n])){
                  temp=(node*)malloc(sizeof(node));
                  temp->data=arr[i-n];
                  temp->next=NULL;
                  if(root==NULL){root=temp;}
                  else{
                      node *p=root;
                      while(p->next !=NULL){p=p->next;}
                      p->next=temp;
                    }
            }
            return creat_list(temp,arr,n-1);

       }
       else{return root;}
    /*   for(i=0;i<8;i++){
            if(isdispari(arr[i])){
                  temp=(node*)malloc(sizeof(node));
                  temp->data=arr[i];
                  temp->next=NULL;
                  if(root==NULL){root=temp;}
                  else{
                      node *p=root;
                      while(p->next !=NULL){p=p->next;}
                      p->next=temp;
                }
            }
       }
return root ;*/
}
//stampa lista
void stampalist(node *temp){
      if(temp==NULL){printf("\n");}
      else{printf("%3d",temp->data);stampalist(temp->next);}
}
//stam>pa l array con using ricorsive
void stampaArray(int arr[],int n ){

      if(n!=0){printf("%3d", arr[i-n]);stampaArray(arr,n-1);}
      else{printf("\n");}
}
int main(){
    node *list;
    int arr[]={8,3,1,3,9,4,6,5};
    stampaArray(arr,8);
    printf("\n");
    list=creat_list(list,arr,8);
    stampalist(root);




  return 0 ;
}
