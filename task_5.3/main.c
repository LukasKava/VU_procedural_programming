#include <stdio.h>

#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define RED "\033[0;31m"
#define NEAUTRAL "\033[0m"

#define S_MAX 214748364

/*
Parašykite programą, kuri paprašo vartotojo įvesti du skaičius (s ir n), o po to nuskaito lygiai n teigiamų būsimo masyvo x
elementų reikšmių. Jei reikšmė neteigiama – prašykite kartoti to reikšmės įvedimą. Programa turi atspausdinti visas
masyve esančių skaičių poras (xi, xj) tokias kad xi ir xj sandauga yra lygi s.
*/

int main(void) {
	int n = 0;
	long int s = 0;

	printf("The program will print all of the array element pairs xi xj so that xi * xj = s\n");
	printf(GREEN"Please enter two numbers s and n:\n"NEAUTRAL);
	printf("Number n is the amount of elements in the array\n");
	printf(YELLOW"[Please follow these instructions]"NEAUTRAL" n has to be a non negative number from 0 till 1000\n\n");
	printf(YELLOW"[Please follow these instructions]"NEAUTRAL" Number s has to be positive long int 0, 214748364\n\n");
	printf(YELLOW"[Please follow these instructions]"NEAUTRAL" Elements of the array must be positive integers between 0 and 2000\n\n");


	printf("Please enter n: ");
	scanf("%d", &n);

	while (n < 0 || n > 999) {
		printf(RED"Wrong input n should be between 0 and 999\n"NEAUTRAL);
		printf("n: ");
		scanf("%d", &n);
	}

	printf("\nPlease enter s: ");
	int scan_return = 0;
	// Check for valid input ALSO checking if someone is putting in something that does not belong to this scanf like a letter
    while ((scan_return = scanf("%ld", &s)) != 1 || (s < 0 || s > S_MAX)) {
        printf(RED"Invalid input. Wrong input s has to be positive long int 0, 214748364\n"NEAUTRAL" s: ");
        //Cleaning the buffer
		if (scan_return != 1) {
			int c;
			while ((c = getchar()) != '\n' && c != EOF) {}
		}
    }

	//Initializing the array We only take 1000 elements and we mark last element as an ending with -1
	int	elements[1001] = {0};
	elements[1000] = -1;
	
	int x = 0;

	//Filling the array with elements
	for (int i = 0; i < n; ++i) {
		printf("\nPlease enter element[%d]:\n", i);
		scanf("%d", &x);

		while (x < 0 || x > 2000) {
			printf(RED"Wrong input x should be between 0 and 2000\n"NEAUTRAL);
			printf("element[%d]: ", i);
			scanf("%d", &x);
		}
		elements[i] = x;
	}

	int pairCount = 0;
	//Printing the numbers xi * xj == s
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			if (elements[i] * elements[j]  == s) {
				printf(GREEN"Element"NEAUTRAL" pair x%d = %d * x%d = %d is equal to %d == s = %ld\n", i, elements[i], j, elements[j], elements[i] * elements[j], s);
				pairCount++;
			}
		} 
	}

	printf(YELLOW"\nTotal pair count: %d\n"NEAUTRAL, pairCount);

	return (0);
}