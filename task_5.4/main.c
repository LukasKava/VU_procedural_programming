#include <stdio.h>

#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define RED "\033[0;31m"
#define NEAUTRAL "\033[0m"

/*
Parašykite programą, kuri leidžia vesti ir įsimena vartotojo vedamus teigiamus skaičius iki tol, kol jis įveda pirmą
neteigiamą reikšmę. Programa turi atspausdinti visus įvestus pirminius skaičius, kiekvieną pirminį skaičių spausdindama
tik vieną kartą, t. y. išvedant rezultatus sykį jau atspausdinta pirminio skaičiaus reikšmė nebekartojama.
*/

//First Part of the function checks if its a prime
//Second Part of the function checks if its already in the list
//Logic used is The smallest factor of a number greater than one cannot be greater than the square root of that number
//https://www.geeksforgeeks.org/c-program-to-check-whether-a-number-is-prime-or-not/

int	isElementPrime(int j, int primes[101], int element) {

	if (element <= 1) {
        return (1);
	}

	for (int i = 2; i * i <= element; i++) {
        if (element % i == 0) {
            return (1);
		}
	}

	//Checking if it already exists in the list
	for (int i = 0; i < j; ++i) {
		if (primes[i] == element) {
			return (1);
		}
	}

	return (0);
}

int main(void) {
	printf("Please enter the ammount of elements you would like to enter to an array\n");
	printf(YELLOW"[Please follow these instructions]"NEAUTRAL" the amount can be from up too 100\n");
	printf(YELLOW"[Please follow these instructions]"NEAUTRAL" elements of an array can range from 0 up too 5000\n");
	printf(RED"[Warning]"NEAUTRAL" the first negative input if gonna be treated as an end of your desire to input\n");

	
	//Taking input
	int size = 0; //amount of elements

	printf("\nPlease enter size: ");
	int scan_return = 0;
	// Check for valid input ALSO checking if someone is putting in something that does not belong to this scanf like a letter
    while ((scan_return = scanf("%d", &size)) != 1 || (size < 0 || size > 100)) {
        printf(RED"Invalid input. Wrong input s has to be from 0 up to 100\n"NEAUTRAL"size: ");
        //Cleaning the buffer
		if (scan_return != 1) {
			int c;
			while ((c = getchar()) != '\n' && c != EOF) {}
		}
    }

	//An array of input elements
	int elements[101] = {0};
	elements[100] = -1; //Mark the end of the array

	int primes[101] = {0};
	primes[100] = -1; //Mark the end of the array

	//Taking elements
	int x = 0;
	int j = 0; //index in the prime array
	printf("\nInput your elements into an array:\n");
	for (int i = 0; i < size; i++) {
		printf("element[%d]: ", i);
		while ((scan_return = scanf("%d", &x)) != 1 || x > 5000) {
        	printf(RED"Invalid input. Wrong input element has to be from 0 up to 5000\n"NEAUTRAL"element: ");
        	//Cleaning the buffer
			if (scan_return != 1) {
				int c;
				while ((c = getchar()) != '\n' && c != EOF) {}
			}
    	}

		elements[i] = x;
		//if we encounter x < 0 break
		if (x < 0) {
			break ;
		}

		if (isElementPrime(j, primes, x)  == 0) {
			primes[j] = x;
			j++;
		}
	}

	//Printing out the list of input elements
	printf("Input elements:\n");
	for (int i = 0;  i < size; i++) {
		printf("%d; ", elements[i]);
	}

	//Printing out the primes
	printf(GREEN"\nPrimes:\n"NEAUTRAL);
	for (int i = 0;  i < j; i++) {
		printf("%d; ", primes[i]);
	}
	printf("\n");

	return (0);
}