
#include "filefunc.h"

void main(){
    char ma[DIM][DIM] = {{'a', 'f', 'k'}, {'o', 'u', 'p'}, {'w', 'e', 'j'}};
    int mi[DIM][DIM] = {{3, 0, 2}, {2, 0, 1}, {0, 3, 2}};
    int size = DIM;
    
    print_ma_mi(ma, mi, size);
    
    char *s = encode(ma, mi, size);
	printf("Codifica: %s\n", s);
}

