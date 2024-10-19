#include <stdio.h>

//Colors:
#define LIGHT_GRAY "\e[90m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define RED "\033[0;31m"
#define NEAUTRAL "\033[0m"
#define LIGHT_CYAN_BOLD_UNDERLINE "\e[1;4;96m"

//Informational tags
#define	ERROR_TAG RED"[ERROR] "NEAUTRAL
#define	SUCCESS_TAG GREEN"[SUCCESS] "NEAUTRAL
#define	WARNING_TAG YELLOW"[WARNING] "NEAUTRAL

/*
This template was generated automatically by the prepare_tasks.sh
To see the file templates visit https://github.com/LukasKava/VU_procedural_programming
And see files template.c and prepare_tasks.c
This file is creted to shorten amount of time i spend on creating folders and writing boiler plate code
*/

//TASK DESCRIPTION:
/*
Apibrėžkite funkciją, kuri leidžia gauti (įvesti) vieną skaičių iš standartinio įvedimo srauto.
Funkcijos prototipas: int getPositiveNumber(char *msg)
Aprašymas: funkcija atspausdina į ekraną tekstinę eilutę msg (kurioje tikisi gauti vartotojui skirtą pranešimą apie tai, ką
reikia įvesti), ir ją (eilutę ekrane) kartoja (prašo vartotojo įvesti vėl ir vėl) tol, kol vartotojas neįveda vieno skaičiaus
eilutėje, kurį ši funkcija ir grąžina.
*/

int getPositiveNumber(char *msg) {

	int	number = 0;			
	int	scan_return = 0;

	printf("%s\n", msg);
	// Check for valid input ALSO checking if someone is putting in something that does not belong to this scanf like a letter
	while ((scan_return = scanf("%d", &number)) != 1 || number <= 0) {
		printf(ERROR_TAG"Please enter positive number: ");

		//Cleaning the buffer
		if (scan_return != 1) {
			char c;
			while ((c = getchar()) != '\n' && c != EOF) {}
		}
	}

	return (number);
}


int main(void) {
	printf(LIGHT_CYAN_BOLD_UNDERLINE"[TASK DESCRIPTION]\n"NEAUTRAL);
	printf(LIGHT_GRAY"Read the main.c in folder task_7.2\n\n"NEAUTRAL);

	int number = getPositiveNumber("Please, enter a positive number: ");
	printf("You have entered: %d\n", number);

	return (0);
}