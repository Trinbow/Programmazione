#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

bool max(int *a,int *b){
   /*if(*a>*b){return true;}
   return false ;*/
   return (*a >*b);
}
void sort(int  *x,int  *y,int *z){
      int temp;
      if(max(x,y)){temp=*x;*x=*y;*y=temp;}
      if(max(x,z)){temp=*x;*x=*z;*z=temp;}
      if(max(y,z)){temp=*y;*y=*z;*z=temp;}
}

int main (){

      int x,y,z;
      scanf("%d%d%d",&x,&y,&z);
      printf("\nris:%d %d %d\n",x,y,z);
      /*scanf("%lf",&x);
      scanf("%lf",&y);*/
      sort(&x,&y,&z);
      printf("\nris:%d %d %d\n",x,y,z);

return 0;
}
