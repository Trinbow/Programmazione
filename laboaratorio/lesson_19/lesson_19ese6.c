#include "6.h"

int main (){

    date data,*d=&data;	
    getDate(d);
    updateDate(d);
    printf("\nla data aggiornata e'= %d/%d/%d\n",d->day,d->mounth,d->year);     

return 0;
}

