#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void vowel_cons(char words[50])
{
	int vowel = 0;
	int cons = 0;

	for (int i=0; i < (strlen(words)); i++)
	{
		if (words[i] == 'A' || words[i] == 'a' || words[i] == 'e' || words[i] == 'E' || words[i] == 'I' || words[i] == 'i' || words[i] == 'O' || words[i] == 'o' || words[i] == 'U' || words[i] == 'u')
		{
			vowel++;
		}
		else if (words[i] == ' ')
		{
		}
		else
		{
			cons++;
		}
	}
	printf("The number of vowels is %d\nThe number of consonants is %d\n", vowel, cons);
}

void convert(char words[50])
{
	for (int i = 0; i < (strlen(words)); i++)
	{
		if (islower(words[i]))
		{
			words[i] = toupper(words[i]);
		}

	}
	printf("You string in uppercase is: %s\n", words, 50);
	for (int i = 0; i < (strlen(words)); i++)
	{
		if (isupper(words[i]))
		{
			words[i] = tolower(words[i]);
		}

	}
	printf("You string in lowercase is: %s\n", words, 50);
}

void compare(char words[50])
{	
	char number_2[50];
	printf("Input another string: ");
	gets_s(number_2, 50);
	//printf("string 1 is %s\nstring 2 is %s\n Their compare is %d", words, number_2, strcmp(words, number_2));
	if (strcmp(words, number_2)==0)
	{
		printf("Congrats, you can type the exact same thing twice!\n\n");
	}
	else
	{
		printf("You fail.\n\n");
	}
}

void main()
{
	char string[50];
	
	printf("What string would you like to look at? ");
	gets_s(string, 50);
	printf("\n--------------Vowel/Cons------------\n");
	vowel_cons(string);
	printf("\n---------------Convert--------------\n");
	convert(string);
	printf("\n---------------Compare--------------\n");
	compare(string);
}