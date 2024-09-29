#include <stdio.h>
#include <math.h>

//\n\033[0;32m
//\033[0m

void	calculateSolution(float a, float b, float c, int amountOfSolutions) {

	printf("Solutions to the quadratic equation are:\n");
	if (amountOfSolutions == 2) {
		//Use the formula (-b +- sqrt(b^2 -4ac)) / 2a
		//First part -b
		float partOne = -b;

		//Part two sqrt(b^2 -4ac)
		double partTwo =  sqrt((b * b) - (4 * a * c));
		printf("x1: %f x2: %f\n",  (partOne - partTwo) / (2 * a), (partOne + partTwo) / (2 * a));
	}	else {
		printf("x: %f\n", (-b) / (2 * a));
	}
}

int main(void) {
	int a = 0, b = 0, c = 0;

	printf("Please input 3 numbers a, b, c\n");
	printf("a: ");
	scanf("%d", &a);
	printf("b: ");
	scanf("%d", &b);
	printf("c: ");
	scanf("%d", &c);

	//We have to check how many solutions we will have using the formula  b^2 - 4ac
	//If this < 0  then it wont have any solutions
	//If its  = 0 than 1 solution
	//If > 0 than 2 solutions
	printf("Using formula: b^2 - 4ac to determine the amount of sulutions ...\n");
	printf("if < 0 - no solutions | if  > 0 - two solutions | if == 0 - one solutions\n\n");

	int amountOfSolutions = (b * b) - (4 * a * c);
	printf("Using formula b^2 - 4ac with your variables the answer is: %d\n", amountOfSolutions);
	if (amountOfSolutions < 0) {
		printf("It means with the variables a: %d b: %d c: %d the quadratic equation ax^2 + bx + c = 0 has \033[0;31mno solutions\033[0m\n", a, b, c);
	}	else if (amountOfSolutions > 0) {
		printf("It means with the variables a: %d b: %d c: %d the quadratic equation ax^2 + bx + c = 0 has \033[0;32m2 solutions\033[0m\n", a, b, c);
		calculateSolution(a, b, c, 2);
	}	else {
		printf("It means with the variables a: %d b: %d c: %d the quadratic equation ax^2 + bx + c = 0 has \033[0;33m1 solution\033[0m\n", a, b, c);
		calculateSolution(a, b, b, 1);
	}

	return (0);
}