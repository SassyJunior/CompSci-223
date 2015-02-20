#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>


union Jimmy
{
	char first_name[10];
	char last_name[10];
	int  age;
};

struct James
{
	char first_name[10];
	char last_name[10];
	int  age;
};

int numOneBits(unsigned int numba) {
	int result;
	while (numba != 0) {
		result += (numba & 1);
		numba = numba >> 1;
	}
	return result;
}
void dtob(int numba){
	int final = numba;
	float other;
	float divide;
	int count = 0;
	char binary[9]="";
	int i;
	for (i = 0; i < 8; i++)
	{
		other = pow(2, 7 - i);
		divide = numba / other;
		if ((int)divide >= 1)
		{
			binary[i] = '1';
			numba = numba - other;
			count++;
		}
		else
		{
			binary[i] = '0';
		}
	}

	printf("%d in binary is %s\nThere are %d 1s\n", final, binary, count);
}


int main()
{	
	union Jimmy timmy;
	struct James flames;
	int problem;
	printf("What problem? ");
	scanf_s("%d", &problem);

	if (problem == 1){
		printf("-----------------Problem 1----------------\n");
		printf("Memory size occupied by the union : %d\n", sizeof(timmy));
		printf("Memory size occupied by the struct: %d\n", sizeof(flames));
		return 1;
	}
	if (problem == 2){
		printf("-----------------Problem 2----------------\n");

		printf("****Struct****\n");
		printf("First: ");
		scanf_s("%s", flames.first_name, 10);
		printf("Last: ");
		scanf_s("%s", flames.last_name, 10);
		printf("Age: ");
		scanf_s("%d", &flames.age);
		printf("The three variables are: %s, %s, %d\n", flames.first_name, flames.last_name, flames.age);
		printf("****Union****\n");
		printf("First: ");
		scanf_s("%s", timmy.first_name, 10);
		printf("The three variables are: %s, %s, %d\n", timmy.first_name, timmy.last_name, timmy.age);
		printf("Last: ");
		scanf_s("%s", timmy.last_name, 10);
		printf("The three variables are: %s, %s, %d\n", timmy.first_name, timmy.last_name, timmy.age);
		printf("Age: ");
		scanf_s("%d", &timmy.age);
		printf("The three variables are: %s, %s, %d\n", timmy.first_name, timmy.last_name, timmy.age);
		return 1;
	}
	
	if (problem == 3){
		printf("-----------------Problem 3----------------\n");

		int numba;
		printf("Gimme a numba! ");
		scanf_s("%d", &numba);
		printf("(%d << 5) >> 7 = %d", numba, ((numba << 5) >> 7));
		return 1;
	}

	if (problem == 4){
		printf("-----------------Problem 4----------------\n");

		int numba1, numba2;
		printf("Gimme a numba! ");
		scanf_s("%d", &numba1);
		printf("Gimme anotha numba! ");
		scanf_s("%d", &numba2);
		printf("XOR : %d \n", numba1 ^ numba2);
		printf("AND : %d \n", numba1 & numba2);
		printf("OR : %d \n", numba1 | numba2);
		printf("compliment of numba1: %d \ncompliment of numba2: %d \n", ~numba1, ~numba2);
		return 1;
	}

	if (problem == 5){
		printf("-----------------CHALLENGE!----------------\n");

		int numba5, count=0;
		char binary[10]="";
		printf("Gimme a numba! ");
		scanf_s("%d", &numba5);
		dtob(numba5);
		return 1;
	}
}