#include <stdio.h>

int main(void) {
	//Storing the first and last name and its length
	int fullName[] = {76, 117, 107, 97, 115, 32, 75, 97, 118, 97, 108, 105, 97, 117, 115, 107, 105, 115};
	int fullNameLength = 18;

	//Task Explanation
	printf("\nParašykite kodo fragmentą, kuris atspausdina jūsų vardą į ekraną, nanudodamiesi\nvarde esančių simbolių ASCII kodais ir\
nesinaudodami pačiais simboliais ar eilutėmis tiesiogiai.\n\n");

	//Printing my full name that should be displayed
	printf("\033[0;32mPilnas vardas: \"Lukas Kavaliauskis\"\033[0m\n");
	printf("\033[0;33mPrinting numbers => to ASCII characters:\033[0m\n");

	for (int i = 0; i < fullNameLength; i++) {
		printf("%c", fullName[i]);
	}

	printf("\n");
	return (0);
}