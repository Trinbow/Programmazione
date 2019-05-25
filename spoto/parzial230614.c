#include  "yardi.h"


int main(){
    node *list;
    int x;
    scanf("%d",&x);
    list=creat_list(list,x);
    stampalist(root);
    printf("\nres=%d\n",sempre_diversi(root));

  return 0 ;
}
