#include <stdio.h>
#include <stdlib.h>

void number_looker_upper(){
	int numbers[3];
	int select;

	for (int i = 0; i < 3; i++){
		printf("What is your number %d choice? ", i + 1);
		scanf_s("%d", &numbers[i]);
		printf("\n");
	}

	printf("What index do you want to see (0,1,2 or 3 to exit)? ");
	scanf_s("%d", &select);
	while (select == 0|| select == 1 || select == 2){
		printf("The number you wrote was: %d\n", numbers[select]);
		printf("Go to : ");
		scanf_s("%d", &select);
	}
	if (select == 3){
		printf("Bye! \n");
	}
	else{
		printf("That's not an index silly!\n");
	}
}

void array_thing(){
	int thing[5][6] = { {1, 2, 3, 4, 5, 0}, { 2, 4, 6, 7, 10}, { 20, 10, 5, 3, 1}, { 3, 6, 9, 12, 15}};

	//Put the numbers on the right
	for (int j = 0; j < 4; j++)
	{
		int total = 0;
		for (int i = 0; i < 5; i++)
		{
			total += thing[j][i];
		}
		thing[j][5] = total;
	}

	//Put the numbers on the bottom
	for (int j = 0; j < 5; j++)
	{
		int total = 0;
		for (int i = 0; i < 4; i++)
		{
			total += thing[i][j];
		}
		thing[4][j] = total;
	}

	//Puts the total in the corner. Adds up
	//the bottom numbers.
	int total = 0;
	for (int j = 0; j < 5; j++)
	{
		total += thing[4][j];
	}

	thing[4][5] = total;

	for (int i = 0; i <= 4; i++) {
		for (int j = 0; j <= 5; j++) {
			printf("%d\t", thing[i][j]);
		}
		printf("\n\n");
	}
	
}

void main(){
	//number_looker_upper();
	array_thing();
}