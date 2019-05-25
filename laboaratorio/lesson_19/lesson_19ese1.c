#include  <stdio.h>
#include  <stdlib.h>



int main (){
   int x=6,*p1=&x;
   char a='c',*p2=&a;
   double y=12.00,*p3=&y;
   printf("\np1=%p |p2=%p |p3=%p |*p1=%d | *p2=%c | *p3=%f\n",p1,p2,p3,*p1,*p2,*p3);  
   printf("\nsize_x=%d |size_p1=%d\n",sizeof(x),sizeof(p1));
   printf("\nsize_a=%d |size_p2=%d\n",sizeof(a),sizeof(p2));
   printf("\nsize_y=%d |size_p3=%d\n",sizeof(y),sizeof(p3)); 


return 0;
}
