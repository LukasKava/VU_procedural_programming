#include <stdio.h>

#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define RED "\033[0;31m"
#define NEAUTRAL "\033[0m"

int main(void) {
	unsigned int a = 0, b = 0, c = 0;

	printf("Programa turi atspausdinti c-ąjį skaičių fc, kur fc=fc-1+fc-2, o f0 = a ir f1 = b. Jei a=0 ir b=1,\nfc yra c-asis garsiosios Fibonačio sekos skaičius.\n");

	printf(RED"Please put in that a > b\n"NEAUTRAL);

	//Taking input
	do {
		printf("a: ");
		scanf("%u", &a);
		printf("b: ");
		scanf("%u", &b);
		printf("c: ");
		scanf("%u", &c);
	} while (a >= b);

	//fc = fc - 1 + fc - 2; f0 = a; f1 = b
	//F2=b+a

	if (c == 0) {
		printf(GREEN"F0 = %u\n"NEAUTRAL, a);
	} else if (c == 1) {
		printf(GREEN"F1 = %u\n"NEAUTRAL, b);
	} else {
		unsigned int f0 = a, f1 = b, sum;
		for (unsigned int i = 2; i <= c; i++) {
			sum = f0 + f1;
			f0 = f1;
			f1 = sum;
		}
		printf(GREEN"f%u = %u\n"NEAUTRAL, c, sum);
	}

	//I want to test the speed of the formula  Fc = ((((1 + sqrt(5)) ^ c) - (1 - sqrt(5)) ^ c)) / sqrt(5)) / sqrt(5)) * b + (((1 + sqrt(5)) ^ (c - 1)) - (1 - sqrt(5)) ^ (c - 1))) / sqrt(5) * a) / sqrt(5)))

	return (0);
}