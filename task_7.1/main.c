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
Apibrėžkite funkciją, kuri patikrina, ar duotas skaičius papuola į nustatytą intervalą.
Funkcijos prototipas: int isInRange(int number, int low, int high)
Aprašymas: funkcija turi grąžinti true, jei skaičius number priklauso intervalui [low; high] (su sąlyga, kad low neviršija
high), kitaip ji turi grąžinti false
*/

int	isInRange(int number, int low, int high) {
	if (low <= high) {
		if (number >= low && number <= high) {
			return (1);
		}
	}
	return (0);
}

int main(void) {
	printf(LIGHT_CYAN_BOLD_UNDERLINE"[TASK DESCRIPTION]\n"NEAUTRAL);
	printf(LIGHT_GRAY"Read the main.c in folder task_7.1\n"NEAUTRAL);

	int number;
	int low;
	int high;

	//Ouside the interval
	number = 0;
	low = -5;
	high = -2;

	printf("number: %d low: %d high: %d answer: %s\n", number, low, high, isInRange(number, low, high) == 0 ? "false" : "true");

	//Inside
	number = 10;
	low = 0;
	high = 10;

	printf("number: %d low: %d high: %d answer: %s\n", number, low, high, isInRange(number, low, high) == 0 ? "false" : "true");

	//Low is bigger than high
	number = 10;
	low = 11;
	high = 10;

	printf("number: %d low: %d high: %d answer: %s\n", number, low, high, isInRange(number, low, high) == 0 ? "false" : "true");

	return (0);
}