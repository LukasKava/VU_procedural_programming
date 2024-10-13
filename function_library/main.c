#include	<stdio.h>

//Colors:
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define RED "\033[0;31m"
#define NEAUTRAL "\033[0m"
#define LIGHT_CYAN_BOLD_UNDERLINE="\e[1;4;96m"

//IMPROVE THIS FUNCTION Its used to take in input
void	takingInput() { 
	printf("Please enter the positive int between 1 and 14\nnbr: ");

	int				nbr = 0;
	int				scan_return = 0;
	// Check for valid input ALSO checking if someone is putting in something that does not belong to this scanf like a letter
	while ((scan_return = scanf("%d", &nbr)) != 1 || (nbr < 1 || nbr > 14)) {
		printf(RED"Invalid input. Wrong input number has to be from 1 up to 14\n"NEAUTRAL"nbr: ");

		//Cleaning the buffer
		if (scan_return != 1) {
			int c;
			while ((c = getchar()) != '\n' && c != EOF) {}
		}
	}
}

//IMPROVE THIS FUNCTION Its used to open the file
int	openFile() {
	FILE	*fp;
	fp = fopen("out.txt", "w");
	if (fp == NULL) {
		printf(RED"[ERROR]"NEAUTRAL" fopen() for file out.txt has failed!\n");
		printf("Exiting the program 1");
		return (1);
	}
	return (0);
}



int main(void) {

	return (0);
}