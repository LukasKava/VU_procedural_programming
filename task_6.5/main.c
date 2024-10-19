#include <stdio.h>
#include <string.h>

//Colors:
#define LIGHT_GRAY "\e[90m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define RED "\033[0;31m"
#define NEAUTRAL "\033[0m"
#define LIGHT_CYAN_BOLD_UNDERLINE "\e[1;4;96m"

#define	ERROR_TAG RED"[ERROR] "NEAUTRAL
#define	SUCCESS_TAG GREEN"[SUCCESS] "NEAUTRAL
#define	WARNING_TAG YELLOW"[WARNING] "NEAUTRAL

/*
This template was generated automatically by the prepare_tasks.sh
To see the file templates visit https://github.com/LukasKava/VU_procedural_programming
And see files template.c and prepare_tasks.c
This file is creted to shorten amount of time i spend on creating folders and writing boiler plate code
*/

//Task Description
/*
Parašykite programą, kuri patikrina, ar eilutėje yra korektiškai įvestas el.pašto adresas. Laikykite, kad jis korektiškas, jei
eilutėje yra vienas simbolis @ ir (po jo) bent vienas taškas, o prieš @, po taško ir tarp šių dviejų simbolių – ne mažiau nei
vienas kitoks simbolis. Jei įvestis korektiška, programa turi atspausdinti domeną, t.y. el.pašto dalį po simbolio @. Visi kada
nors pateikti korektiški elektroninio pašto adresai turi būti kaupiami (append) tekstiniame faile “emails.txt”.
*/

int	isEmailAddressWrong(const char *email) {

	//Check for @
	const char	*atSign_ptr = strchr(email, '@');

	if (atSign_ptr == NULL) {
		printf(ERROR_TAG"@ sign was not found in the email\n");
		return (1);
	} else if ( atSign_ptr != strchr(email, '@')) {
		printf(ERROR_TAG"There are more than 1 @ signs\n");
		return (1);
	}

	//Check that there is more than one simbol before @
	if (atSign_ptr == email) {
		printf(ERROR_TAG"There should be at least 1 sign before @\n");
		return (1);
	}


	const char	*dotSign_ptr = strchr(atSign_ptr, '.');

	if (dotSign_ptr == atSign_ptr + 1) {
		printf(ERROR_TAG"\".\" Cannot go immediately after @ sign\n");
		return (1);
	}

	if (*(dotSign_ptr + 1) == '\0') {
		printf(ERROR_TAG"There should be at least 1 more character after .\n");
		return (1);
	}
	return (0);
}

int	savingEmail(char *email) {
	//Opening the emails.txt
	FILE	*fp = fopen("emails.txt", "a");

	if (fp == NULL) {
		printf(ERROR_TAG"fopen() for file email.txt has failed!\n");
		printf("Exiting the program 1\n");
		return (1);
	} else {
		fprintf(fp, "%s\n", email);
        fclose(fp);
		printf(SUCCESS_TAG"Email has been saved to email.txt\n");
	}

	return (0);
}

int main(void) {
	printf(LIGHT_CYAN_BOLD_UNDERLINE"[TASK DESCRIPTION]\n"NEAUTRAL);
	//To lazy to write everything out
	printf(LIGHT_GRAY"Read the main.c in folder task_6.5\n"NEAUTRAL);
	printf(WARNING_TAG"Email should not be longer than 20 characters\n\n");

	char	email[21];


	//taking input
	printf("Please enter your email: ");
    if (fgets(email, sizeof(email), stdin) == NULL) {
        printf(ERROR_TAG"Invalid input\n");
        return (1);
    }

	if (email[strlen(email) - 1] != '\n') {
        printf(ERROR_TAG"Input too long\n");
        // Išvalome buferį
        int c;
        while ((c = getchar()) != '\n' && c != EOF) {}
        return (1);
    }

	email[strcspn(email, "\n")] = '\0';


	//Checking email


	if (isEmailAddressWrong(email) == 1) {
		return (1);
	}

	//Printing out the domain
	printf(SUCCESS_TAG"Correct email the domain is: %s\n", strchr(email, '@') + 1);

	//Saving email
	if (savingEmail(email) == 1) {
		return (1);
	}


	return (0);
}