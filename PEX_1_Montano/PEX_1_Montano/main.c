// Computer Science 223 - M2
// Author: Everett Montano
// Date: 2/4/15
//
// PEX 1: Credit Card Validation System
//
// Purpose: The purpose of this program is to read file listing bank account numbers
// and the check to make sure that the account number is accurate based off a specific
// algorithm. It also checks to ensure that the account is not expired. It then exports
// the information to an output file with all the required information.
// 
// Sources:
// http://stackoverflow.com/questions/15444567/removing-spaces-and-special-characters-from-string
// This website was used to remove the characters from the card numbers. The over all format of the
// the code from the website was used with changes in variables and returns charnged to fit my needs.
//
// http://en.wikipedia.org/wiki/Damm_algorithm
// This website was used to learn how the Damm alogrithim was used. It was incredibly helpful and 
// gave me the basic idea of what I need to do to calculate the validity of the check number.
//
// http://en.wikipedia.org/wiki/Luhn_algorithm
// This website was also used to learn how the Luhn alogrithim was used. It was incredibly helpful and 
// gave me the basic idea of what I need to do to calculate the validity of the check number. There is 
// code at the bottom of the wiki but it was not used in the making of my funtion.
//
// Documentation:
// Aside from the sources and information listed above, I have not recieved any other help.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>


#define NUMLINES 100
#define PIECETYPE 20

// This is the general struct that describes
// every account. All variables are kept as char
// arrays to easy writing to a file.
struct account{
	char month[PIECETYPE];
	char year[PIECETYPE];
	char type[PIECETYPE];
	char card_num[PIECETYPE];
};

// This function removes any foreign characters from
// from the account number
char *remove_spec(char in[22]){				// The star is so that the function can return an array
	char num[22];
	int i = 0, q = 0;
	for (; i < strlen(in); i++)
	{
		//This checks to ensure that it is an alpha numeric char. I could have used isalnum but that
		// was not working for me and the source suggested this. Works fine.
		if (in[i] >= 48 && in[i] <= 57 || in[i] >= 65 && in[i] <= 90 || in[i] >= 97 && in[i] <= 122){
			num[q] = in[i];
			q++;
		}
	}
	num[q] = '\0'; //This ensures that the string cuts off and doesn't fill with characters it doesnt need.
	return num;
}

// This function perforems the Luhn Algorithim.
//
// :Inputs:
// num[20] (str) : This is the char array of the account number
//
// :Outputs:
// 1/0 : returns a good or no good on the check digit
//
// Purpose: This algorithm uses a series of multiplications
// and additions to check the last digit. Every other number
// is doubled. If the double is bigger than 9, the digits are
// added together. Then all the digits are added. If the total
// is a multiple of 10, the check digit is good.
int luhn(char num[20]){
	int *digits;
	int total = 0;

	// Allocates memore for the digits when they are
	// changed from characters to integers.
	digits = malloc((sizeof(int)*strlen(num)));

	int m, k, q;
	for (m = 0; m < strlen(num); m++)
	{
		digits[m] = (int)num[m] - 48; // The (int)num[m] turns ascii to decimal. The subtraction is to make it the original number.
	}

	// These are for the numbers that when doubled are bigger than 9.
	for (k = strlen(num) - 2; k >= 0; k -= 2)
	{
		switch (digits[k]){
		case 5:
			digits[k] = 1;
			break;
		case 6:
			digits[k] = 3;
			break;
		case 7:
			digits[k] = 5;
			break;
		case 8:
			digits[k] = 7;
			break;
		case 9:
			digits[k] = 9;
			break;
		default:
			digits[k] = (digits[k] * 2);
			break;
		}
	}
	for (q = 0; q < strlen(num); q++){
		total += digits[q];
	}

	// This is the final check of the check number. If the total returns
	// 0 when mod 10, it is good, else 0 is returned.
	if ((total % 10) == 0){
		return 1;
	}
	else
	{
		return 0;
	}
}

// This function perforems the Damm Algorithim.
//
// :Inputs:
// num[20] (str) : This is the char array of the account number
//
// :Outputs:
// 1/0 : returns a good or no good on the check digit
//
// Purpose: This algorithm uses a table to check if the digits
// work together. It starts by initializing the interim digit as 0.
// Then using a table like the one below. The number that itersects
// account number and interim is the new interim. When it reaches the
// last of the digits, if the column and row are equal, it will land
// on a 0 and be good, else it is a negative.
int damm(char num[20]){

	// The chart is 10 by 10. It can be changed according to 
	// the person that is using the chart. This is the one given 
	// to us initially.
	int checker[10][10] = {
		{ 0, 3, 1, 7, 5, 9, 8, 6, 4, 2 },
		{ 7, 0, 9, 2, 1, 5, 4, 8, 6, 3 },
		{ 4, 2, 0, 6, 8, 7, 1, 3, 5, 9 },
		{ 1, 7, 5, 0, 9, 8, 3, 4, 2, 6 },
		{ 6, 1, 2, 3, 0, 4, 5, 9, 7, 8 },
		{ 3, 6, 7, 4, 2, 0, 9, 5, 8, 1 },
		{ 5, 8, 6, 9, 7, 2, 0, 1, 3, 4 },
		{ 8, 9, 4, 5, 3, 6, 2, 0, 1, 7 },
		{ 9, 4, 3, 8, 6, 1, 7, 2, 0, 5 },
		{ 2, 5, 8, 1, 4, 3, 6, 7, 9, 0 }
	};
	int prev = 0;
	int check; // The digit of the account number being checked
	int *digits;

	// Allocates memore for the digits when they are
	// changed from characters to integers.
	digits = malloc((sizeof(int)*strlen(num)));

	int m, k;
	for (m = 0; m < strlen(num); m++)
	{
		digits[m] = (int)num[m] - 48; // Same as above.
	}

	// This uses the interim and the selected account number
	// as the index for the 2D array. It then replaces the interim
	// number with whatever is in that spot in the array.
	for (k = 0; k < strlen(num); k++){
		check = digits[k];
		prev = checker[prev][check];
	}

	// This is the final check of the check number. If the number
	// that is the next interim is 0, it returns 1, else it returns 0.
	if (prev == 0){
		return 1;
	}
	else{
		return 0;
	}
}

void main(int argc, char *argv[]){

	// Sets up the files and the user input for the main program. 
	// The user MUST specify a file that is in the same file as the 
	// main program. If not, the user must provide the FULL address
	// of the file.
	
	// File checker
	char file[50];
	strcpy(file, argv[1]);
	FILE *initial;
	errno_t error = fopen_s(&initial, file, "r");
	if (error != 0){
		printf("We have encountered a problem with your file. Please check that you\nhave entered the correct file name. You may have to enter the full path.\n");
		exit(0);
	}
	
	FILE *reader;
	FILE *writer;
	struct account persons[NUMLINES];

	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	int current_mon = tm.tm_mon + 1;
	int current_yr = tm.tm_year % 100;
	
	int i, z;
	int check;
	int done = 0;

	char string_manip[6] = ""; // This is for checking stuff

	reader = fopen(file, "r");
	writer = fopen("output.txt", "w");
	i = 0;

	// This portion of the program goes through a series of checks in a specific order.
	// If a set of information does not meet the specifics set, it will return an invalid.
	// The program checks in the following order:
	//
	//		1. Expiration Date
	//		2. Prefix
	//		3. Account Length
	//		4. Damm's Algorithm
	//		5. Luhn's Algorithm
	// 
	// If an error is experience, please check the output file to see which test is failed.
	// The main window does not specify where there is failures, just that all the accounts
	// have been checked.
	while (!feof(reader))
	{
		done = 0; // Resets the validity after every time.

		// This reads in the file and places the necessary information into the a structure.
		// For ease, here are the 4 parts and their types:
		//
		//		1. Month (char array)
		//		2. year (char array)
		//		3. type (char array)
		//		4. card number (char array)
		//
		// **IMPORTANT FILE INFORMATION**
		// In order to ensure that the program reads the program correctly, please write your input 
		// file in the follwoing format:
		//
		//								 MM YY CARD_TYPE CARD_NUMBER
		//							example: 11 15 VISA 4198743758376447
		//
		// NOTE: Account number may include hyphens and card type can have any format of capitalization.
		//
		fscanf(reader, "%s %s %s %s", persons[i].month, persons[i].year, persons[i].type, persons[i].card_num);

		printf("Checking: %s %s %s %s...\n", persons[i].month, persons[i].year, persons[i].type, persons[i].card_num);

		strcpy(persons[i].card_num, remove_spec(persons[i].card_num)); //This is to remove and strange characters in the account number.

		// This turns the account type into all capital letters.
		z = 0;
		for (; z < strlen(persons[i].type); z++){
			if (islower(persons[i].type[z])){
				persons[i].type[z] = toupper(persons[i].type[z]);
			}
		}


		// Sequential Checker

		// Takes a portion of the account number for checking (first 4)
		for (int p = 0; p < 4; p++){
			string_manip[p] = persons[i].card_num[p];
		}

		// 1. Expiration (Year then Month
		if (atoi(persons[i].year) < current_yr){
			fprintf(writer, "%s/%s %s %s INVALID EXPIRED DATE\n", persons[i].month, persons[i].year, persons[i].type, persons[i].card_num);
		}
		else if (atoi(persons[i].month) < current_mon){
			fprintf(writer, "%s/%s %s %s INVALID EXPIRED DATE\n", persons[i].month, persons[i].year, persons[i].type, persons[i].card_num);
		}


		// 2-3 Prefix and Length
		// Utilizing the 4 digits alloted above and the length of the car_num
		// this checks to see if they are both vaild. This portion separates it
		// all by the card type. Alothough some have similar parameters, there
		// are no two that are the exact same so this is the easiest way to
		// separate them.
		if (strcmp(persons[i].type, "MASTERCARD") == 0){
			if (string_manip[0] != '5' ||
				string_manip[1] != '1' ||
				string_manip[1] != '2' ||
				string_manip[1] != '3' ||
				string_manip[1] != '4' ||
				string_manip[1] != '5'){
				fprintf(writer, "%s/%s %s %s INVALID ACCOUNT PREFIX\n", persons[i].month, persons[i].year, persons[i].type, persons[i].card_num);
				done = 1;
			}
			if (strlen(persons[i].card_num) != 16)
			{
				fprintf(writer, "%s/%s %s %s INVALID ACCOUNT LENGTH\n", persons[i].month, persons[i].year, persons[i].type, persons[i].card_num);
				done = 1;
			}
		}

		if (strcmp(persons[i].type, "VISA") == 0){
			if (string_manip[0] != '4'){
				fprintf(writer, "%s/%s %s %s INVALID ACCOUNT PREFIX\n", persons[i].month, persons[i].year, persons[i].type, persons[i].card_num);
				done = 1;
			}
			if (strlen(persons[i].card_num) != 15)
			{
				fprintf(writer, "%s/%s %s %s INVALID ACCOUNT LENGTH\n", persons[i].month, persons[i].year, persons[i].type, persons[i].card_num);
				done = 1;
			}
		}

		if (strcmp(persons[i].type, "AMEX") == 0)
		{
			if (string_manip[0] != '3' ||
				string_manip[1] != '4' ||
				string_manip[1] != '7'){
				fprintf(writer, "%s/%s %s %s INVALID ACCOUNT PREFIX\n", persons[i].month, persons[i].year, persons[i].type, persons[i].card_num);
				done = 1;
			}
			if (strlen(persons[i].card_num) == 13 || strlen(persons[i].card_num) == 16)
			{
			}
			else
			{
				fprintf(writer, "%s/%s %s %s INVALID ACCOUNT LENGTH\n", persons[i].month, persons[i].year, persons[i].type, persons[i].card_num);
				done = 1;
			}

		}
		if (strcmp(persons[i].type, "DISCOVER") == 0){
			if (strcmp(string_manip, "6011") != 0){
				fprintf(writer, "%s/%s %s %s INVALID ACCOUNT PREFIX\n", persons[i].month, persons[i].year, persons[i].type, persons[i].card_num);
				done = 1;
			}
			if (strlen(persons[i].card_num) != 16)
			{
				fprintf(writer, "%s/%s %s %s INVALID ACCOUNT LENGTH\n", persons[i].month, persons[i].year, persons[i].type, persons[i].card_num);
				done = 1;
			}
		}
		if (strcmp(persons[i].type, "JCB") == 0){
			if (strcmp(string_manip, "2131") == 0 || strcmp(string_manip, "1800") == 0){
			} else
			{
				fprintf(writer, "%s/%s %s %s INVALID ACCOUNT PREFIX\n", persons[i].month, persons[i].year, persons[i].type, persons[i].card_num);
				done = 1;
			}
			if (strlen(persons[i].card_num) != 15)
			{
				fprintf(writer, "%s/%s %s %s INVALID ACCOUNT LENGTH\n", persons[i].month, persons[i].year, persons[i].type, persons[i].card_num);
				done = 1;
			}
		}

		// 4-5. Algorithm Check
		// This section references back to the functions in the beginning of the program.
		// According to the directions, only accounts of type JCB must be done with the Damm
		// algorithm. As seen it just references it there. 
		//
		// The done integer tells us if there has been a break in validity. If there has been other
		// pieces that were invalid, even if the check number is good, the card is invalid. But, if
		// the check number is invalid, it is added to the list of invalid things.
		if (strcmp(persons[i].type, "JCB") != 0)
			{
				check = luhn(persons[i].card_num);
				if (check == 1 && done == 0)
				{
					fprintf(writer, "%s/%s %s %s VALID\n", persons[i].month, persons[i].year, persons[i].type, persons[i].card_num);
				}
				else
				{
					fprintf(writer, "%s/%s %s %s INVALID CHECK DIGIT\n", persons[i].month, persons[i].year, persons[i].type, persons[i].card_num);
				}
			}
		if (strcmp(persons[i].type, "JCB") == 0)
			{
				check = damm(persons[i].card_num);
				if (check == 1 && done == 0)
				{
					fprintf(writer, "%s/%s %s %s VALID\n", persons[i].month, persons[i].year, persons[i].type, persons[i].card_num);
				}
				else
				{
					fprintf(writer, "%s/%s %s %s INVALID CHECK DIGIT\n", persons[i].month, persons[i].year, persons[i].type, persons[i].card_num);
				}
			}
		printf("Done...\n");
		i++;
	}

	// Close both files at the end so that they are not left open when the program closes
	fclose(reader);
	fclose(writer);

	// Final mesage
	printf("All done! Please check the output file!\n");
}







// The next lines are the functions that I created to test all of the function above.
// Althought not a requirement, it is for my personal use in case I delete my test file.
// Thank you.
/*
int this(){
	char test[20] = "1234567812345678";
	int *digits;
	int total = 0;

	digits = malloc((sizeof(char)*strlen(test)));

	int m;
	for (m = 0; m < strlen(test); m++)
	{
		digits[m] = (int)test[m] - 48;
		printf("%d\n", (digits[m]));
	}
	for (m = strlen(test) - 1; m > 0; m -= 2)
	{
		digits[m] = (int)test[m] - 48;
		printf("The number: %d\n", digits[m]);
		switch (digits[m]){
		case 5:
			total += 1;
			break;
		case 6:
			total += 3;
			break;
		case 7:
			total += 5;
			break;
		case 8:
			total += 7;
			break;
		case 9:
			total += 9;
			break;
		default:
			total += (digits[m] * 2);
			break;
		}
	}
	return 1;
}
void main(){//char num[20]){
	int checker[10][10] = {
		{ 0, 3, 1, 7, 5, 9, 8, 6, 4, 2 },
		{ 7, 0, 9, 2, 1, 5, 4, 8, 6, 3 },
		{ 4, 2, 0, 6, 8, 7, 1, 3, 5, 9 },
		{ 1, 7, 5, 0, 9, 8, 3, 4, 2, 6 },
		{ 6, 1, 2, 3, 0, 4, 5, 9, 7, 8 },
		{ 3, 6, 7, 4, 2, 0, 9, 5, 8, 1 },
		{ 5, 8, 6, 9, 7, 2, 0, 1, 3, 4 },
		{ 8, 9, 4, 5, 3, 6, 2, 0, 1, 7 },
		{ 9, 4, 3, 8, 6, 1, 7, 2, 0, 5 },
		{ 2, 5, 8, 1, 4, 3, 6, 7, 9, 0 }
	};
	char in[22] = "1800-3422-562-1346";
	char num[22];
	int prev = 0;
	int check;
	int *digits;

	digits = malloc((sizeof(char)*strlen(in)));

	int m, k;
	int i = 0, q = 0;
	for (; i < strlen(in); i++)
	{
		if (in[i] >= 48 && in[i] <= 57 || in[i] >= 65 && in[i] <= 90 || in[i] >= 97 && in[i] <= 122){
			printf("alphaNumeric:%c\n", in[i]);
			num[q] = in[i];
			q++;
		}
		else
		{
			printf("special:%c\n", in[i]);
			//remove that
		}
	}
	num[q] = '\0';
	printf("%s", num);
	for (m = 0; m < strlen(num); m++)
	{
	digits[m] = (int)num[m] - 48;
	}

	for (k = 0; k < strlen(num); k++){
	check = digits[k];
	printf("check: %d\n", check);
	printf("prev: %d\n", prev);
	prev = checker[prev][check];
	printf("prev: %d\n", prev);
	}
	if (prev==0){
	printf("The check = %d. The prev = %d.\n", check, check);
	}
}
*/