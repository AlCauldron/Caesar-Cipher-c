#include <stdio.h>
#include <string.h>
#include <conio.h>

void encrypt(char *decrypted, int n);

int main()
{
	//Variable initialization
	char message[280]; //The length of a tweet on Twitter!
	int shiftAmount;

	//Get user input
	printf("Enter message to be encrypted: ");
	scanf("%[^\n]s",&message);
	printf("\nEnter shift amount (1-25): ");
	scanf("%i",&shiftAmount);

	if (shiftAmount < 1 | shiftAmount > 25) 
	{//Checks if n is a valid shift value. If not, ends program with error.
		printf("Error, please make sure n is between 1 and 25. \nPress any key to exit.");
		getch();
		return 1;
	}

	//Calls a void method to encrypt the message array.
	encrypt(message, shiftAmount);

	//Prints the encrypted message.
	printf("\nEncrypted message: %s \nPress any key to exit.",message);

	//Stops the program from quitting before the user provides an input.
	getch();
	return 0;
}

void encrypt(char *decrypted, int n) 
{
	char current;
	int i;

	for (i = 0; i < strlen(decrypted); i++) 
	{//Scans each letter of the message.
		current = decrypted[i];
		if (current >= 'A' && current <= 'Z')
		{//Shifts all capital letters.
			current = ((current-'A')+n)%26+'A';
			decrypted[i] = current;
		}
		if (current >= 'a' && current <= 'z')
		{//Shifts all lowercase letters.
			current = ((current-'a')+n)%26+'a';
			decrypted[i] = current;
		}
	}
}