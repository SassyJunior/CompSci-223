#include <stdio.h>
#define PI 3.141592653

void area(float radius){
	double area;
	area = 3.14*radius*radius;
	printf("6 digits: %6.1f\n", area);
	printf("No trailing zeroes: %g\n", area);
	printf("In hex: %x\n", (int)area);
}

void types(){
	printf("-------------------\n");
	printf("Size of int: %d bytes\n",sizeof(int));
	printf("Size of long: %d bytes\n", sizeof(long));
	printf("Size of char: %d bit\n", sizeof(char));
	printf("Size of float: %d bytes\n", sizeof(float));
	printf("Size of double: %d bytes\n", sizeof(double));
	printf("-------------------\n");
}

void char_math(int in){
	printf("The character you selected was %c\n", in);
	printf("The next character is %c\n", (in + 1));
	printf("Your integer in bits shifted by 1 to the left is %d\n", (in << 1));
}

void main(){
	float r;
	int input;
	printf("What is the radius? ");
	scanf_s("%f", &r);
	area(r);
	types();
	printf("What integer do you want to be changed to a character? ");
	scanf_s("%d", &input);
	char_math(input);
}
