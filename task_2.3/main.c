//Parašykite kodo fragmentą, kuris nuskaito vartotojo įvestą sveiką skaičių
//ir atspausdina, ar jis lyginis ar ne.
//!Svarbu:! sąlygos sakinių (if) naudoti negalima ir spausdinant atsakymą
//žodį „printf“ galima rašyti tik vieną kartą.

#include <stdio.h>

int main(void) {
	int userInputNumber = 11;

	//Taking in the users input of a number
	//printf("Iveskite sveikaji skaiciu: ");
	//scanf("%d", &userInputNumber);

	printf("\nAtsakymas ar skaicius %d yra lyginis ar ne?\n%s\n", userInputNumber, (userInputNumber % 2) == 0 ? "\033[0;32mSkaicius yra Lyginis\033[0m" : "\033[0;31mSkaicius yra nelyginis\033[0m");
	return (0);
}