#include <stdio.h>

void time(int min){
	char convert[50];
	printf("hours (h) or days (d)? ");
	scanf_s("%s", convert, 50);
	switch (convert[0]){
	case 'h':
		printf("The time in hours is %0.2d", (min / 60));
		break;
	case 'd':
		printf("The time in days is %0.2d", (min / (60*24)));
		break;
	default:
		printf("That wasn't an option yo!");
		break;
	}
}

void grade_finder(int grade){
	if (grade >= 90){
		printf("A\n");
	}
	else if (grade >= 90){
		printf("B\n");
	}
	else if (grade >= 90){
		printf("C\n");
	}
	else if (grade >= 90){
		printf("D\n");
	}
	else if (grade >= 90){
		printf("F\n");
	}
}

void GPA_comp(int GPA){	
	if (GPA >= 2.0){
		printf("You are proficient!\n");
		printf("No probation for you.\n");
	}
	else if (GPA < 1.0){
		printf("Square root club!\n");
	}
	else{
		printf("Step up your game!\n");
	}
}


void main(){

	float GPA;
	char lettergrade[50];
	int minutes;
	int cadet_grade;

	printf("Enter a time in minutes: ");
	scanf_s("%d", &minutes);
	time(minutes);

	printf("\n-------------------\n");

	print("Enter a grade: ");
	scanf_s("%d", &cadet_grade);
	grade_finder(cadet_grade);

	printf("\n-------------------\n");

	printf("Please enter your GPA: ");
	scanf_s("%f", &GPA);
	GPA_comp(GPA);
	
	printf("-------------------\n");

}