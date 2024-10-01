#include <stdio.h>

#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define RED "\033[0;31m"
#define NEAUTRAL "\033[0m"

//Vartotojas įveda skaičių n, o po to – n realiųjų skaičių.
//Programa turi suskaičiuoti šių skaičių sumą ir vidurkį,
//o taip pat mažiausią (minimumą) ir didžiausią (maksimumą) reikšmes.

int main(void) {
	//Variables
	int		n = 0;
	double	sum = 0;
	double	average = 0;
	double	min = 0, max = 0;
	double	nbr = 0;


	printf(YELLOW"TASK DESCRIPTION:\n"NEAUTRAL);
	printf("Vartotojas įveda skaičių n, o po to – n realiųjų skaičių.\nPrograma turi suskaičiuoti šių skaičių sumą ir vidurkį,\no taip pat mažiausią (minimumą) ir didžiausią (maksimumą) reikšmes.\n\n");

	//Taking input
	//number of the elements n
	printf("Please enter n > 0:\n");
	do {
		printf("n: ");
		scanf("%d", &n);
	} while (n <= 0);

	//We take in first number to initialize the min and max correctly
	printf("Please enter your input numbers:\n");
	scanf("%lf", &nbr);
	min = max = nbr;
	sum += nbr;

	for (int i = 1; i < n; i++) {
		printf("\n%d elements left\n", n - i);
		scanf("%lf", &nbr);
		sum += nbr;

		if (nbr > max) {
			max = nbr;
		} else if (nbr < min) {
			min = nbr;
		}
	}

	//Calculating average
	average = sum / n;

	//Output
	printf(GREEN"Sum: %.3lf\nAverage: %.3lf\nMin: %.3lf\nMax: %.3lf\n"NEAUTRAL, sum, average, min, max);


	return (0);
}