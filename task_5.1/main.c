#include <stdio.h>

#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define RED "\033[0;31m"
#define NEAUTRAL "\033[0m"

/*
Parašykite programą, kuri savo viduje iš eilės vieną po kito atlieka TIKSLIAI šiuos žingsnius:
a) apibrėžia masyvą, galinti sutalpinti 10 elementų, tame pačiame sakinyje inicializuodama juos nulinėmis reikšmėmis
b) atspausdina visą masyvą į ekraną
c) pačiam pirmam, ketvirtam ir dešimtam masyvo elementams priskiria reikšmes atitinkamai 1, 2 ir 3
d) ištrina iš masyvo trečią elementą
e) įterpia į masyvą naują elementą su reikšme 4, taip, kad po įterpimo jis būtų septintas
f) atspausdina visą masyvą į ekraną
g) paprašo vartotojo įvesti du skaičius (x ir y), ir masyvo elementui su indeksu x nustato naują reikšmę, lygią y
h) paprašo vartotojo įvesti vieną skaičių (x), ir ištrina iš masyvo elementą su indeksu x
į) paprašo vartotoją įvesti du skaičius (x ir y), ir į masyvą įterpia naują elementą su reikšme y, taip, kad po įterpimo jo
indeksas būtų x
j) atspausdina visą masyvą į ekraną
*/

int main(void) {
	//a
	int	elements[10] = {0};

	//b
	for (int i = 0; i < 10; ++i) {
		printf("element [%d]: %d\n", i + 1, elements[i]);
	}

	//c
	elements[0] = 1;
	elements[3] = 2;
	elements[9] = 3;

	//d deleting the third element
	// The actual array size we could say is 9 as we have deleted one of the elements
	for(int i = 2; i < 10 - 1; i++) {
		elements[i] = elements[i + 1];
	}


	//e 7th element should be 4
	for(int i = 9; i > 6; i--) {
		elements[i] = elements[i - 1];
	}
	elements[6] = 4;

	//F print the array
	printf("\nNew array F:\n");
	for (int i = 0; i < 10; ++i) {
		printf("element [%d]: %d\n", i + 1, elements[i]);
	}

	//G
	int x = 0;
	int y = 0;
	printf("Please enter 2 numbers:\nx (the number of the element in the array. Can be between 0 and 9)\ny (the value of the element x between 0 and 100)\n");

	printf("x: ");
	scanf("%d", &x);

	while (x < 0 || x > 9) {
		printf(RED"Wrong input should be between 0 and 9\n"NEAUTRAL);
		printf("x: ");
		scanf("%d", &x);
	}

	printf("y: ");
	scanf("%d", &y);

	while (y < 0 || y > 100) {
		printf(RED"Wrong input should be between 0 and 100\n"NEAUTRAL);
		printf("y: ");
		scanf("%d", &y);
	}
	
	elements[x] = y;

	
	//h) paprašo vartotojo įvesti vieną skaičių (x), ir ištrina iš masyvo elementą su indeksu x
	printf(YELLOW"Please enter an element x to be deleted from the array between 0 and 9\n"NEAUTRAL);
	printf("x: ");
	scanf("%d", &x);

	while (x < 0 || x > 9) {
		printf(RED"Wrong input should be between 0 and 9\n"NEAUTRAL);
		printf("x: ");
		scanf("%d", &x);
	}

	//Check if its deleting the last element
	if (x == 9) {
		elements[x] = -1;
	} else {
		for(int i = x; i < 10 - 1; i++) {
			elements[i] = elements[i + 1];
		}
	}

	//i
	printf(YELLOW"Adding new element to an array\n"NEAUTRAL);
	printf("Please enter 2 numbers:\nx (the number of the element in the array. Can be between 0 and 9)\ny (the value of the element x between 0 and 100)\n");

	printf("x: ");
	scanf("%d", &x);

	while (x < 0 || x > 9) {
		printf(RED"Wrong input should be between 0 and 9\n"NEAUTRAL);
		printf("x: ");
		scanf("%d", &x);
	}

	printf("y: ");
	scanf("%d", &y);

	while (y < 0 || y > 100) {
		printf(RED"Wrong input should be between 0 and 100\n"NEAUTRAL);
		printf("y: ");
		scanf("%d", &y);
	}

	for(int i = 9; i > x; i--) {
		elements[i] = elements[i - 1];
	}
	elements[x] = y;
	
	//j
	printf("\nNew array j:\n");
	for (int i = 0; i < 10; ++i) {
		printf("element [%d]: %d\n", i, elements[i]);
	}


	return (0);
}