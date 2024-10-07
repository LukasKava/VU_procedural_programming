#include <stdio.h>
#include <math.h>

#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define RED "\033[0;31m"
#define NEAUTRAL "\033[0m"


#define	EPSILON 1e-7

//TASK DESCRIPTION
//Vartotojas įveda teigiamų skaičių seką, kurios pabaigą žymi pirma įvesta neteigiama reikšmė.
//Programa turi rasti, kuris skaičius tarp įvestųjų turi daugiausiai skaitmenų.

int	countFractionalPartDigits(double fractional) {
	int fractionalDigits  = 0;
	int	integerPart = 0;

	//Max for fractional digits i will take as 10 nbr
	while (fractionalDigits < 3) {
		fractional *= 10;
		integerPart = (int)fractional;
		if (integerPart == 0 && (fractional - integerPart) < EPSILON) {
			break;
		}
		fractionalDigits++;
		fractional -= integerPart;
	}
	return (fractionalDigits);
} 

int main(void) {
	double nbr = 0;
	int	amountOfDigits = 0;
	double	maxDigitsNbr = 0;
	double	digits;

	printf(YELLOW"TASK DESCRIPTION\n"NEAUTRAL);
	printf("Vartotojas įveda teigiamų skaičių seką,\nkurios pabaigą žymi pirma įvesta neteigiama reikšmė.\nPrograma turi rasti, kuris skaičius tarp įvestųjų turi daugiausiai skaitmenų.\n\n");

	printf("\nPlease enter the numbers. Once you want to stop enter a negative number\n");
	printf(RED"For the fractional part only 3 digits will be considered\n\n"NEAUTRAL);
	while (nbr >= 0) {
		int answer = scanf("%lf", &nbr);
		//The stop negative number
		double positive = fabs(nbr);

		long int	integerPart = (long int)positive;

		digits = log10(integerPart) + 1 + countFractionalPartDigits(positive - integerPart);
		if(digits > amountOfDigits) {
			amountOfDigits = digits;
			maxDigitsNbr = nbr;
		}
	}

	printf(GREEN"The number that has the most digits is: %lf amount of digits: %d\n"NEAUTRAL, maxDigitsNbr, amountOfDigits);

	return (0);
}