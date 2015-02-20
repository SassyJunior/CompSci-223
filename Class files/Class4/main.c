#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void guesser(){
	
	int answer;
	int tries = 1;
	int guess;

	srand(time(NULL));
	answer = rand()%10+1;
	
	printf("I am thinking of a number between 0 and 10. What do you guess? ");
	scanf_s("%d", &guess);
	printf("\n");

	while(guess != answer && tries < 3){
	printf("That is not right! Try again! %d left!\n", (3-tries));
	printf("Guess: ");
	scanf_s("%d", &guess);
	printf("\n");
	tries++;
	}
	
	if(guess == answer){
		printf("You did it!\n");
	}
	else
	{
	printf("The number was %d. You lose! Good day sir!\n", answer);
	}
	
}

void averager(){
	int current;
	int total = 0;

	for(int i=0; i<5; i++){
	printf("What is your number %d choice? ", i+1);
	scanf_s("%d", &current);
	printf("\n");
	total = total + current;
	}

	printf("Your average of numbers is %0.2f.\n", total/5.0);
}

void menu(){
	int selection=0;

	printf("How can I help you today?\n Make a number selection from the menu below.\n\t 1. Talk\n\t 2. Walk\n\t 3. Shop\n\t 4. Tickle\n\t 5. Quit\n");
	while (selection != 5){
		printf("Go to : ");
		scanf_s("%d", &selection);
		switch (selection){
		case 1:
			printf("You have chose to talk!\n");
			break;
		case 2:
			printf("You have chose to talk!\n");
			break;
		case 3:
			printf("You have chose to shop!\n");
			break;
		case 4:
			printf("You have chose to be tickled!\n");
			break;
		case 5:
			printf("Have a nice day!\n");
			exit(0); //This exits the program.
		default:
			printf("Thats not a choice silly goose!\n");
			break;
		}
	}

}

void main(){
	//guesser();
	//averager();
	//menu();
}