#include <stdio.h>

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
Parašykite programą, kuri paprašo įvesti vieną teigiamą skaičių, ir suskaičiuoja jo faktorialą, kurį atspausinda ekrane ir
taip pat įrašo į rezultatų failą „out.txt“.
*/

int main(void) {
	//Printing out explanation of the task
	printf(LIGHT_CYAN_BOLD_UNDERLINE"[TASK DESCRIPTION]\n"NEAUTRAL);
	printf(LIGHT_GRAY"The program that asks to enter one positive integer, and it calculates its factorial.\nThen it gets printed out to the screen and it also gets written to the file out.txt\n"NEAUTRAL);
	printf(YELLOW"[WARNING]"NEAUTRAL" The program does not calculate factorial anything bigger than 14.\nThat is because the numbers become unreasonable and that is not the point of the task.\n"YELLOW"THE POINT OF THE TASK IS OPENING AND WRITING TO THE FILE\n\n"NEAUTRAL);


	//Initializing the variables
	int				nbr = 0;
	int				scan_return = 0;
	long long int	factorial = 1;

	printf("Please enter the positive int between 1 and 14\nnbr: ");

	// Check for valid input ALSO checking if someone is putting in something that does not belong to this scanf like a letter
    while ((scan_return = scanf("%d", &nbr)) != 1 || (nbr < 1 || nbr > 14)) {
        printf(RED"Invalid input. Wrong input number has to be from 1 up to 14\n"NEAUTRAL"nbr: ");

        //Cleaning the buffer
		if (scan_return != 1) {
			int c;
			while ((c = getchar()) != '\n' && c != EOF) {}
		}
    }

	//Assuming nbr is the correct input
	for (int i = nbr; i > 1; --i) {
		factorial *= i;
	}

	//printing the answer to the screen
	printf(GREEN"Factorial of nbr %d is: %lld\n"NEAUTRAL, nbr, factorial);

	FILE	*fp;
	fp = fopen("out.txt", "w");
	if (fp == NULL) {
		printf(RED"[ERROR]"NEAUTRAL" fopen() for file out.txt has failed!\n");
		printf("Exiting the program 1");
		return (1);
	}

	//Assuming opening file worked
	fprintf(fp, "Factorial of nbr %d is: %lld\n", nbr, factorial);
	fclose(fp);

	return (0);
}