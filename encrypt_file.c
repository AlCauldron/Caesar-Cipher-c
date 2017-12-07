#include <stdio.h>
#include <string.h>
#include<conio.h>

void encrypt(char *decrypted, int n);

int main()
{//Variable initialization
	char message[280]; //The length of a tweet on Twitter!
    char fileName[50];
	int shiftAmount;
    FILE* fileInput;
	FILE* fileOutput;

	//Get name of file
	printf("\nEnter filename: ");
	scanf("%s",&fileName);
    fileInput = fopen(fileName,"r");

    if (!fileInput)
    {//Checks if the fileInput exists. If not, ends program with error.
        printf("Error, please provide a valid file name. \nPress any key to exit.");
		getch();
		return 1;
    }
	else
	{//Scans the input file and puts it into a string.
		fgets(message, 280, fileInput);
		fclose(fileInput);
	}
	
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

	//Appends '.enc' to the output file name and writes it.
	strcat(fileName,".enc");
	fileOutput = fopen(fileName,"w");
	fprintf(fileOutput, "%s", message);
	fclose(fileOutput);

	//Prints the encrypted message.
	printf("\nEncrypted message: %s",message);
	printf("\nOutputted file to %s! \nPress any key to exit.",fileName);

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
