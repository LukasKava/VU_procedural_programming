#include <stdio.h>

#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define RED "\033[0;31m"
#define NEAUTRAL "\033[0m"

int DBD(int a, int b) {
	if (a == 0) {
		return (b);
	} else if (b == 0) {
		return (a);
	}

	if (a == b) {
		return (a);
	}

	if (a > b) {
		return (DBD(a - b, b));
	}
	return (DBD(a, b - a));
}

long int MBK(int a, int b) {
	return (((long int)a * (long int)b) / DBD(a, b));
}

int main(void) {
	int a = 0, b = 0, c = 0;
	printf("Vartotojas įveda tris natūraliuosius skaičius (a, b, c).\nPrograma turi atspausdinti du skaičius  šių trijų skaičių didžiausią bendrąjį daliklį (DBD)\nbei mažiausiąjį bendrą kartotinį (MBK).\n");

	printf(RED"Please put in input that numbers are > 0 for:\n"NEAUTRAL);

	//Taking input
	do  {
		printf("a: ");
		scanf("%d", &a);
		printf("b: ");
		scanf("%d", &b);
		printf("c: ");
		scanf("%d", &c);
	} while (a <= 0 || b <= 0 || c <= 0);

	//DBD
	printf(GREEN"DBD(a: %d b: %d c: %d): %d\n"NEAUTRAL, a, b, c, DBD(a, DBD(b, c)));


	//MBK
	printf(GREEN"MBK(a: %d b: %d c: %d): %ld\n"NEAUTRAL, a, b, b, MBK(MBK(a, b), c));

	return  (0);
}