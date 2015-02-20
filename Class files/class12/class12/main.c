#include "mylib.h"

void main(){
	int numba;
	printf("Give me a numba! ");
	scanf_s("%d", &numba);
	numba = doublenumber(numba);
	printf("Twice that is %d\n", numba);
}