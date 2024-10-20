#include <stdio.h>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

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
Apibrėžkite funkciją, kuri leidžia užpildyti masyvą atsitiktinėmis reikšmėmis.
Funkcijos prototipas: void generateArray(int data[], int size, int low, int high)
Aprašymas: kiekvienam iš size elementų, esančių masyve data, funkcija turi priskirti atsitiktinę reikšmę iš intervalo [low;
high]; nieko papildomai grąžinti nereikia, t.y. funkcijos rezultatas yra masyve esančios (naujos) reikšmės.
*/

void generateArray(int data[], int size, int low, int high) {

	srand(time(NULL));
	if (low >= high) {
		printf(ERROR_TAG"lower bound cannot be >= higher_bound\n");
		return ;
	}

	//Hope that size is not > than the actual data[]

	for (int i = 0; i < size; ++i) {
		data[i] = rand() % (high - low + 1) + low;
	}
}

int main(void) {
	printf(LIGHT_CYAN_BOLD_UNDERLINE"[TASK DESCRIPTION]\n"NEAUTRAL);
	printf(LIGHT_GRAY"Read the main.c in folder task_7.4\n\n"NEAUTRAL);

	int	data[20] = {0};

	//Testing if low >= high
	generateArray(data, 20, 10, 2);
	printf("Testing if low >= high Array1:\n");
	for(int i = 0; i < 20; ++i) {
		printf("%d ", data[i]);
	}
	printf("\n\n");


	//Testing with low 3 and high 101
	generateArray(data, 18, 3, 101);
	printf("Testing with low 3 and high 101 Array1:\n");
	for(int i = 0; i < 20; ++i) {
		printf("%d ", data[i]);
	}
	printf("\n");


	return (0);
}