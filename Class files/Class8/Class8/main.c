#include <stdio.h>
#include <stdlib.h>

void swap(int s, int t){
	int* temp = s;
	s = t;
	t = temp;

	print("%d %d", s, t);

}

void main(){
	int* b;
	b = malloc(sizeof(int));
	int* a;
	a = malloc(sizeof(int));

	*a = 10;
	*b = 12;
	swap(a, b);
}