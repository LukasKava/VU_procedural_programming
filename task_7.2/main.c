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
Apibrėžkite funkciją, kuri suskaičiuoja duoto skaičiaus faktorialą.
Funkcijos prototipas: int getFactorial(int number)
Aprašymas: funkcija skaičiavimams naudojasi rekursija ir grąžina neneigiamo skaičiaus number faktorialą, o jei jo
suskaičiuoti negalima – grąžina 0.
Įdomu: apibrėžkite (kitą) funkciją, kuri duoda tą patį rezultatą, bet rekursija nesinaudoja.
*/

int getFactorial_recursive(int number) {
	if (number < 0) {
		return (0);
	}

	if (number == 0) {
		return (1);
	}

	return (number * getFactorial_recursive(number - 1));
}

int getFactorial(int number) {
	if (number < 0) {
		return (0);
	}

	int factorial = 1;
	while (number > 0) {
		factorial *= number;
		--number;
	}
	return (factorial);
}

int main(void) {
	printf(LIGHT_CYAN_BOLD_UNDERLINE"[TASK DESCRIPTION]\n"NEAUTRAL);
	printf(LIGHT_GRAY"Read the main.c in folder task_7.2\n\n"NEAUTRAL);

	//Testing recursive factorial function
	int number = 10;
	printf("Recursive factorial of number %d factorial: %d\n", number, getFactorial_recursive(number));
	printf("Factorial of number %d factorial: %d\n\n", number, getFactorial(number));

	number = -1;
	printf("Recursive factorial of number %d factorial: %d\n", number, getFactorial_recursive(number));
	printf("Factorial of number %d factorial: %d\n\n", number, getFactorial(number));

	number = 0;
	printf("Recursive factorial of number %d factorial: %d\n", number, getFactorial_recursive(number));
	printf("Factorial of number %d factorial: %d\n\n", number, getFactorial(number));

	number = 4;
	printf("Recursive factorial of number %d factorial: %d\n", number, getFactorial_recursive(number));
	printf("Factorial of number %d factorial: %d\n\n", number, getFactorial(number));


	return (0);
}