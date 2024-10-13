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

int main(void) {
	int nbr1 = 0, nbr2 = 0, nbr3 = 0;
	int middleNbr = 0;


	printf("Please enter 3 numbers\nnumbers: ");
	int		scan_return = 0;

	// Check for valid input ALSO checking if someone is putting in something that does not belong to this scanf like a letter
	while ((scan_return = scanf("%d;%d;%d", &nbr1, &nbr2, &nbr3)) != 1) {
		printf(RED"Invalid input. Please three numbers\n"NEAUTRAL"numbers: ");
		//Cleaning the buffer
		if (scan_return != 1) {
			int c;
			while ((c = getchar()) != '\n' && c != EOF) {}
		}
	}

	//Find middle number
	middleNbr = findMiddleNumber(nbr1, nbr2, nbr3);
	

	return (0); 
}