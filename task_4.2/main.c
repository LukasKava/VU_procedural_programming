#include <stdio.h>

#define GREEN "\033[0;32m"
#define RED "\033[0;33m"
#define YELLOW "\033[0;31m"
#define NEAUTRAL "\033[0m"

int main(void) {
	int a = 0, b = 0, c = 0;

	printf("This is a program that takes in 3 integers a: lower bound b: upper bound and c: divider\n");
	printf("It checks the range from (a, b] for the numbers that divide by c and leaves remainder 1\n\n");

	//Take user input
	printf("a: ");
	scanf("%d", &a);
	printf("b: ");
	scanf("%d", &b);
	printf("c: ");
	scanf("%d", &c);
	printf("\nResult: ");

	for (int i = a + 1; i <= b; ++i) {
		if (i > 0 && i % c == 1) {
			printf("%d ", i);
		}
	}
	printf("\n");

	return (0);
}