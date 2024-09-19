#include <stdio.h>

void	findMax(int a, int b, int c) {
	int max;
	max = a >= b ? a : b;
	max = max >= c ? max : c;
	printf("Maximali triju skaiciu a %d, b %d, c %d reiksme: %d\n", a, b, c, max);
}

void	findMin(int a, int b, int c) {
	int min;
	min = a <= b ? a : b;
	min = min <= c ? min : c;
	printf("Minimali triju skaiciu a %d, b %d, c %d reiksme: %d\n", a, b, c, min);
}

int main(void) {
	int a, b, c;

	//Taking in the Users 3 numbers
	// printf("Pirmas sveikasis skaicius: ");
	// scanf("%d", &a);
	// printf("Antras sveikasis skaicius: ");
	// scanf("%d", &b);
	// printf("Trecias sveikasis skaicius: ");
	// scanf("%d", &c);

	//Max tests
	printf("\033[0;32mTESTING 6 cases of Max number out of 3 numbers\033[0m\n\n");
	a = 10, b = 1, c = 20;
	findMax(a, b, c);

	a = -10, b = 0, c = -300;
	findMax(a, b, c);

	a = -10, b = 1000, c = -300;
	findMax(a, b, c);

	a = -10, b = 2, c = 999;
	findMax(a, b, c);

	a = 0, b = 0, c = 0;
	findMax(a, b, c);
		
	a = 7, b = 6, c = 8;
	findMax(a, b, c);

	printf("\n\033[0;31mTESTING 6 cases of Min number out of 3 numbers\033[0m\n\n");
	//Min tests
	a = 5, b = 1, c = 19;
	findMin(a, b, c);

	a = -101, b = 0, c = -320;
	findMin(a, b, c);

	a = -50, b = 6, c = -32;
	findMin(a, b, c);

	a = -10, b = 2, c = 12983;
	findMin(a, b, c);

	a = 0, b = 0, c = 0;
	findMin(a, b, c);
		
	a = 999, b = 998, c = 997;
	findMin(a, b, c);

	printf("\n\033[0;33mTESTING 1 case of Min and Max number out of 3 numbers\033[0m\n\n");
	a = 87, b = 234, c = -2384;
	findMin(a, b, c);
	findMax(a, b, c);

	printf("\n\n");

	return (0);
}