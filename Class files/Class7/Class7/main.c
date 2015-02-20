#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int day;
	char month[4];
	int year;
} Date;

typedef struct cadet {
	char name[50];
	char phone_number[13];
} Cadet;

void printDate(){
	Date d;
	printf("Welcome to birthday writer.\nWhat day were your born?\n");
	scanf_s("%d", &d.day);
	printf("What month were your born? (MMM) \n");
	fflush(stdin);
	gets_s(d.month, 4);
	fflush(stdin);
	printf("What year were your born? (YYYY) \n");
	scanf_s("%d", &d.year);
	printf("\nDid you know that today is ");
	printf("%s %d, %d", d.month, d.day, d.year + 20);
	printf("? Happy Birthday!\n");
}

void phones(){
	int list_length;
	char select[50];
	char choice[2];

	printf("How many numbers would you like to add? ");
	scanf_s("%d", &list_length);

	Cadet *wing;
	wing = malloc(sizeof(Cadet)*list_length);

	for (int i = 0; i < list_length; i++){
		printf("\nWho is the person? ");
		fflush(stdin);
		gets_s(wing[i].name, 50);
		fflush(stdin);
		printf("\nWhat is his or her number (xxx-xxx-xxxx)? ");
		fflush(stdin);
		gets_s(wing[i].phone_number, 13);
		fflush(stdin);
	}

	while(1){
		printf("\nDo you want to look up someone (y/n)?");
		gets_s(choice, 2);
		if (strcmp(choice, "n") != 0)
		{
			printf("Who?\n");
			fflush(stdin);
			gets_s(select, 50);
			fflush(stdin);
			for (int i = 0; i < list_length; i++){
				if (strcmp(select, wing[i].name) == 0){
					printf("\nYou found %s.\nHis or her number is %s.\n", wing[i].name, wing[i].phone_number);
				}
				if (strcmp(select, wing[i].name) != 0 && i == (list_length-1))
				{
					printf("I am sorry, we couldn't find %s. This is who we have in our system:\n\n", select);
					for (int i = 0; i < list_length; i++){
						printf("%s\n", wing[i].name);
					}
				}
			}
		}
		else{
			exit(0);
		}
	}

}
void main(){
	//printDate();
	phones();

}