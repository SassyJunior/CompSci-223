#include <stdio.h>
#include <stdlib.h>


int less(int a, int b){
	return a < b;
}

int greater(int a, int b){
	return a > b;
}

typedef int(*compare)(int, int);

//walk through array and find biggest or smallest
int findextreme(int *arr, int count, compare f){
	int extreme = arr[0];
	int i;
	for (i = 0; i < count; i++){
		if ((*f)(arr[i], extreme)){
			extreme = arr[i];
		}
	}
	return extreme;
}

void main(){
	int arrays[10] = { 17, 24, 5, 19, 2, 88, 11, 3, 48, 19 };
	printf("The extreme is %d\n", findextreme(arrays, 10, &less));
	printf("The other extreme is %d\n", findextreme(arrays, 10, &greater));
}