#include <stdio.h>

void foo1(int xval) {
	int x;
	x = xval;
	printf("valore: %i\n", x);
	printf("indirizzo: %p\n", &x);
}

void foo2(int dummy) {
	int y;
	printf("valore: %i\n", y);
	printf("indirizzo: %p\n", &y);
}

int main() {
	foo1(7);
	foo2(11);
	return 0;
}
