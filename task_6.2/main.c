#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Colors:
#define LIGHT_GRAY "\e[90m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define RED "\033[0;31m"
#define NEAUTRAL "\033[0m"
#define LIGHT_CYAN_BOLD_UNDERLINE "\e[1;4;96m"

#define	ERROR_TAG RED"[ERROR] "NEAUTRAL
#define	SUCCESS_TAG GREEN"[SUCCESS] "NEAUTRAL

/*
This template was generated automatically by the prepare_tasks.sh
To see the file templates visit https://github.com/LukasKava/VU_procedural_programming
And see files template.c and prepare_tasks.c
This file is creted to shorten amount of time i spend on creating folders and writing boiler plate code
*/

//TASK DESCRIPTION:
/*
Parašykite programą, kuri paprašo duomenų faile „in.txt“ pateikti realų skaičių, ne mažesnį už 10 ir nedidesnį už 1000,
su ne daugiau kaip 3 skaičiais po kablelio. Laikykite, kad įvestyje trupmeninę dalį nuo sveikosios skiria kablelis. Programa
turi atspausdinti įvesto skaičiaus ilgį. Jei duomenys pateikti nekorektiškai, programa turi prašyti įvesti (tikėtina, kito)
duomenų failo vardą, su galimai jau korektiškais duomenimis.
*/


int	errorG = 0;

int commaCounting(char *str, int len) {
	//Check if the is more than 1 comma 
	int commaCount = 0;
	for (int i = 0; str[i] != '\0' && i < len; ++i) {
		if (str[i] == ',') {
			++commaCount;
		}
	}

	if (commaCount > 1) {
		printf(ERROR_TAG"There should be one , char separating integer part and fractional part\n");
		return (commaCount);
	}
	return (0);
}

//On success return 0 if it fails return 1
int	openTheFile(FILE **fp, char *name, char *mode) {
	printf(RED"Opening filename: %s\n"NEAUTRAL, name);

	*fp = fopen(name, mode);
	if (*fp == NULL) {
		printf(ERROR_TAG"fopen() for file in.txt has failed!\n");
		printf("Check if the file in.txt exists\n");
		return (1);
	} else {
		printf(SUCCESS_TAG"File %s was opened succesfully error: %d\n", name, errorG);
	}
	return (0);
}

//On success returns the lenght of how much it did read on ERROR it will return -1
int	readNumberInFile(FILE **fp, char *str, int maxLen) {
	int c;
	int i = 0;
	while ((c = fgetc(*fp)) != EOF && i < maxLen) {
		str[i] = c;
		++i;
	}

	fclose(*fp);
	return (i);
}

int	checkingFirstLevelErrorCases(int i, char *str) {
	int commaCount = 0;

	// This indicates that whatever is in out file does not adhiere to our input requirements
	if (i > 8) {
		printf(ERROR_TAG"There is garbage in the file in.txt\n");
		return(1);
	}

	//Check if the is more than 1 comma
	if ((commaCount = commaCounting(str, 12)) > 1) {
		return (1);
	}

	//The number cannot start with 0  and ,
	if (str[0] == 0 || str[0] == ',') {
		printf(ERROR_TAG"Integer number part cannot start with 0 or ,\n");
		return (1);
	}
	return (0);
}


int	checkingSecondLevelErrorCases(char *str) {
	int	nbrLen = 0;

	//Checking if there are any garbage characters
	for (int x = 0; str[x] != '\0' && x < 12; ++x) {
		if (str[x] < '0' || str[x] > '9') {
			if (str[x] != ',') {
				printf(ERROR_TAG"There are garbage characters\n");
				return (-1);
			}
		} else {
			++nbrLen;
		}
	}

	//The len of the number cannot be more than 7
	if (nbrLen > 7) {
		printf(ERROR_TAG"The file input is not a number that adheres to our points\n");
		return (-1);
	}

	return (nbrLen);
}

void	askingForFileName(char *filename) {
	printf("Please enter the filename where we can find the number\nfilename: ");
	int		scan_return = 0;

	memset(filename, 0, 10);  // Clear the filename buffer
	// Check for valid input ALSO checking if someone is putting in something that does not belong to this scanf like a letter
	while ((scan_return = scanf("%10s", filename)) != 1) {
		printf(RED"Invalid input. Please put in the filename.\n"NEAUTRAL"filename: ");
		//Cleaning the buffer
		if (scan_return != 1) {
			int c;
			while ((c = getchar()) != '\n' && c != EOF) {}
		}
	}
}

int main(void) {
	//Printing out explanation of the task
	printf(LIGHT_CYAN_BOLD_UNDERLINE"[TASK DESCRIPTION]\n"NEAUTRAL);
	printf(LIGHT_GRAY"Please have a file in.txt which would have a \"real number\" not smaller than 10 and not bigger than 1000\n"NEAUTRAL);
	printf(LIGHT_GRAY"The fractional part of the number should not be longer than 3 digits after the comma.\n"NEAUTRAL);
	printf(YELLOW"[WARNING]"NEAUTRAL" The integer and fractional parts should be separated by the comma.\nIf the data is incorrect the program asks for a new file name with the correct data.\n");
	printf(GREEN"[RESULT]"NEAUTRAL" The program is going to print the len of the given number\n\n");



	FILE	*fp = NULL;
	int		len = 0;
	char	numberStr[12];


	int		numberLen = 0;
	char	*integerPart;
	char	*fractionalPart;
	int		integer = 0;
	int		fractional = 0;
	int		loopFirstTime = 0;
	char	filename[10] = "in.txt";


	do {
		printf(YELLOW"LOOP COUNT: %d\n"NEAUTRAL, loopFirstTime);
		errorG = 0;
		memset(numberStr, 0, 12);  // Clear the filename buffer
		numberStr[11] = '\0';

		//Dealing with the filename
		if (loopFirstTime != 0) {
			//ASK FOR FILE NAME
			askingForFileName(filename);
		}

		//Opening the file
		if (openTheFile(&fp, filename, "r") == 1) {
			errorG = 1;
		}


		if (errorG != 1 && (len = readNumberInFile(&fp, numberStr, 12)) == -1){
			errorG = 1;
		}

		if (errorG != 1 && checkingFirstLevelErrorCases(len, numberStr) == 1) {
			errorG = 1;
		}

		if (errorG != 1 && (numberLen = checkingSecondLevelErrorCases(numberStr)) == -1) {
			errorG = 1;
		}

		if (errorG != 1) {
			//Now We save the the integer and fractional parts
			char *token = strtok(numberStr, ",");

			integerPart = token;
			for (int x = 0; token != NULL; ++x) {
				printf("token: %s\n", token);
				token = strtok(NULL, ",");
				if (token != NULL) {
					fractionalPart = token;
				}
				if (x > 1) {
					printf(ERROR_TAG"There should not be more than 1 , signs\n");
					errorG = 1;
				}
			}
			printf("Fractional part: %s integer part: %s\n", fractionalPart, integerPart);
		}

		if (errorG != 1 && fractionalPart != NULL && integerPart !=NULL) {
			//Convert the both sides to numbers with atoi()
			fractional = atoi(fractionalPart);
			integer = atoi(integerPart);
		} else {
			errorG = 1;
		}

		if (errorG != 1 && (integer < 10 || integer > 1000)) {
			errorG = 1;
			printf(ERROR_TAG"The number should be between 10 and 1000\n");
		}
		
		if (errorG != 1 && (fractional > 999)) {
			errorG = 1;
			printf(ERROR_TAG"The fractional part should not be more than 3 numbers\n");
		}

		if (errorG != 1 && ((fractional > 0) && integer == 1000)) {
			errorG = 1;
			printf(ERROR_TAG"The number should be between 10 and 1000\n");
		}
	
		//break out of the loop if we found a real number that fits out points
		if (errorG == 0) {
			printf(GREEN"The lenght of the given real number %d,%d is %d\n"NEAUTRAL, integer, fractional, numberLen);
			break ;
		}
		++loopFirstTime;
		printf("\n");
	} while (errorG == 1);

	return (0);
}