#include <stdio.h>
#include <string.h>

//Colors:
#define LIGHT_GRAY "\e[90m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define RED "\033[0;31m"
#define NEAUTRAL "\033[0m"
#define LIGHT_CYAN_BOLD_UNDERLINE "\e[1;4;96m"

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


int commaCounting(char *str, int len) {
	//Check if the is more than 1 comma 
	int commaCount = 0;
	for (int i = 0; str[i] != '\0' && i < len; ++i) {
		if (str[i] == ',') {
			++commaCount;
		}
	}

	if (commaCount > 1) {
		printf(RED"[ERROR]"NEAUTRAL" There should be one , char separating integer part and fractional part\n");
		return (commaCount);
	}
	return (0);
}

int main(void) {
	//Printing out explanation of the task
	printf(LIGHT_CYAN_BOLD_UNDERLINE"[TASK DESCRIPTION]\n"NEAUTRAL);
	printf(LIGHT_GRAY"Please have a file in.txt which would have a \"real number\" not smaller than 10 and not bigger than 1000\n"NEAUTRAL);
	printf(LIGHT_GRAY"The fractional part of the number should not be longer than 3 digits after the comma.\n"NEAUTRAL);
	printf(YELLOW"[WARNING]"NEAUTRAL" The integer and fractional parts should be separated by the comma.\nIf the data is incorrect the program asks for a new file name with the correct data.\n");
	printf(GREEN"[RESULT]"NEAUTRAL" The program is going to print the len of the given number\n\n");

	//Opening in.txt
	FILE	*fp;
	fp = fopen("in.txt", "r");
	if (fp == NULL) {
		printf(RED"[ERROR]"NEAUTRAL" fopen() for file in.txt has failed!\n");
		printf("Check if the file in.txt exists\n");
		printf("Exiting the program 1");
		return (1);
	}

	//int integerPart = 0;
	//int	fractionalPart = 0;
	char hello[12];
	int commaCount = 0;
	int	error = 0;
	int	nbrLen = 0;
	int c;
	int i = 0;
	while ((c = fgetc(fp)) != EOF && i < 12) {
		hello[i] = c;
		++i;
	}

	
	// This indicates that whatever is in out file does not adhiere to our input requirements
	if (i > 8) {
		printf(RED"[ERROR]"NEAUTRAL" There is garbage in the file in.txt\n");
		error = 1;
	}

	//Check if the is more than 1 comma
	if (error != 1 && (commaCount = commaCounting(hello, 12)) > 1) {
		//Error steps
		error = 1;
	}

	//The number cannot start with 0  and ,
	if (error != 1 && (hello[0] == 0 || hello[0] == ',')) {
		printf(RED"[ERROR]"NEAUTRAL" Integer number part cannot start with 0 or ,\n");
		error = 1;
	}

	//Checking if there are any garbage characters
	for (int x = 0; error != 1 && hello[x] != '\0' && x < 12; ++x) {
		if (hello[x] < '0' || hello[x] > '9') {
			if (hello[x] != ',') {
				printf(RED"[ERROR]"NEAUTRAL" There are garbage characters\n");
				error = 1;
			}
		} else {
			++nbrLen;
		}
	}
	
	//The len of the number cannot be more than 7
	if (error != 1 && nbrLen > 7) {
		printf(RED"[ERROR]"NEAUTRAL" The file input is not a number that adheres to our points\n");
		error = 1;
	}

	//Now We save the the integer and fractional parts
	char *integerPart;
	char *fractionalPart;

	char *token = strtok(hello, ",");
	if (token ==NULL) {
		//ERROR
	}

	integerPart = token;
	for (int x = 0; token != NULL; ++x) {
		printf("token: %s\n", token);
		token = strtok(NULL, ",");
		if (token != NULL) {
			fractionalPart = token;
		}
		if (x > 1) {
			printf(RED"[ERROR]"NEAUTRAL" There should not be more than 1 , signs\n");
		}
	}
	printf("FRactional part: %s integer part: %s\n", fractionalPart, integerPart);

	// fscanf(fp, "%d",  &integerPart);
	// fscanf(fp, "%s",  hello);
	//printf("Integer part: %d\n", integerPart);
	printf("Integer part: %s and i: %d\n", hello, i);
	printf("feof indicator: %d\n", feof(fp));

	fclose(fp);
	return (0);
}