#include<stdio.h>
#include<stdlib.h>


void sum(double *s,double x,double y){
      
      *s=x+y;

}

int main (){

      double x=1.00,y=2.00,z;
      /*scanf("%lf",&x);
      scanf("%lf",&y);*/
      sum(&z,x,y);
      printf("\nla somma e :%lf\n",z);

return 0;
}
