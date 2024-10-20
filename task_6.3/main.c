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
Parašykite programą, kuri paprašo įvesti tris skaičius vienoje eilutėje, be tarpų, teigiamus arba neigiamus, kuriuos vieną
nuo kito skiria kabliataškiai, ir raskite vidurinį (pagal reikšmę) skaičių. Jei įvestis korektiška, rezultatą (reikšmę) programa
turi atspausdinti rezultatų faile, kurio vardas įvedamas ir privalo baigtis simboliais „.txt“ (jei taip nėra, prašoma failo vardą
įvesti iš naujo).
*/

int findMiddleNumber(int nbr1, int nbr2, int nbr3) {
	if ((nbr1 >= nbr2 && nbr1 <= nbr3) || (nbr1 >= nbr3 && nbr1 <= nbr2)) {
		return (nbr1);
	} else if ((nbr2 >= nbr1 && nbr2 <= nbr3) || (nbr2 >= nbr3 && nbr2 <= nbr1)) {
		return (nbr2);
	}
	return (nbr3);
}

int filenameCheck(char *filename) {
	//go till the end of the string
	int i;
	for (i = 0; filename[i] != '\0'; ++i) {

	}

	--i;
	char *textFileEnding = ".txt";
	for (int x = 3; x >= 0 && i >= 0; --x, --i) {
		printf("check=: [%c] [%c]\n", textFileEnding[x], filename[i]);
		if (textFileEnding[x] != filename[i]) {
			printf(ERROR_TAG"Wrong text file ending filename: %s should end in .txt\n", filename);
			return (1);
		}
	}
	return (0);
}

void	askingForFileName(char *filename) {
	printf("Please enter the filename in which you would like to store the number\nfilename: ");
	int		scan_return = 0;

	memset(filename, 0, 15);  // Clear the filename buffer
	// Check for valid input ALSO checking if someone is putting in something that does not belong to this scanf like a letter
	while ((scan_return = scanf("%15s", filename)) != 1 || filenameCheck(filename) != 0) {
		printf(RED"Invalid input. Please put in the filename.\n"NEAUTRAL"filename: ");
		//Cleaning the buffer
		memset(filename, 0, 15);  // Clear the filename buffer
		if (scan_return != 1) {
			int c;
			while ((c = getchar()) != '\n' && c != EOF) {}
		}
	}
}


int main(void) {
	//Printing out explanation of the task
	printf(LIGHT_CYAN_BOLD_UNDERLINE"[TASK DESCRIPTION]\n"NEAUTRAL);
	printf(LIGHT_GRAY"Please enter 3 numbers without gaps separated by ; positive or negative are okay.\nThe program is gonna find a middle number between them.\n"NEAUTRAL);
	printf(LIGHT_GRAY"Then it will ask to enter a filename where it should store the middle number.\n"NEAUTRAL);
	printf(YELLOW"[WARNING]"NEAUTRAL" The file name must end in .txt\n");
	printf(YELLOW"[WARNING]"NEAUTRAL" The numbers should ne put in like 1;2;3;any number as the inicator for the finish. Only 3 first numbers will be considered\n");
	printf(YELLOW"[WARNING]"NEAUTRAL" If the number is more than INT_MAX or less than INT_MIN it will work but the answer might surprise you!\n\n");


	int nbr1 = 0, nbr2 = 0, nbr3 = 0, nbrEnd = 0;
	int middleNbr = 0;


	printf("Please enter 3 numbers and end number\nnumbers: ");
	int		scan_return = 0;
	// Check for valid input ALSO checking if someone is putting in something that does not belong to this scanf like a letter
	while ((scan_return = scanf("%d;%d;%d;%d", &nbr1, &nbr2, &nbr3, &nbrEnd)) != 4) {
		printf(RED"Invalid input. Please three numbers\n"NEAUTRAL"numbers: ");
		//Cleaning the buffer
		if (scan_return != 4) {
			int c;
			while ((c = getchar()) != '\n' && c != EOF) {}
		}
	}
	int c;
	while ((c = getchar()) != '\n' && c != EOF) {}

	//Find middle number
	middleNbr = findMiddleNumber(nbr1, nbr2, nbr3);
	printf(GREEN"numbers: %d; %d; %d middle number:  %d\n"NEAUTRAL, nbr1, nbr2, nbr3, middleNbr);
	char	filename[15] = {0};
	//The len of the textfilename should not be longer than 15characters and end .txt
	askingForFileName(filename);
	printf(SUCCESS_TAG"File name %s will be created shortly\n", filename);

	FILE	*fp;
	fp = fopen(filename, "w");
	if (fp == NULL) {
		printf(RED"[ERROR]"NEAUTRAL" fopen() for file out.txt has failed!\n");
		printf("Exiting the program 1");
		return (1);
	}
	
	//Assuming opening file worked
	fprintf(fp, "Numbers: %d; %d; %d middle number:  %d\n", nbr1, nbr2, nbr3, middleNbr);

	fclose(fp);
	return (0);
}