#include <stdio.h>
void main(){
	int num1;
	int num2;
	int sum;

	printf("What is your first number?\n");
	scanf_s("%d", &num1);
	printf("What is your second number?\n");
	scanf_s("%d", &num2);
	sum = num1 + num2;
	printf("The two numbers added is %d\n", sum);

}