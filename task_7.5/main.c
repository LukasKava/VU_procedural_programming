#include <stdio.h>

//Colors:
#define LIGHT_GRAY "\e[90m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define RED "\033[0;31m"
#define NEAUTRAL "\033[0m"
#define LIGHT_CYAN_BOLD_UNDERLINE "\e[1;4;96m"

//Informational tags
#define	ERROR_TAG RED"[ERROR] "NEAUTRAL
#define	SUCCESS_TAG GREEN"[SUCCESS] "NEAUTRAL
#define	WARNING_TAG YELLOW"[WARNING] "NEAUTRAL

/*
This template was generated automatically by the prepare_tasks.sh
To see the file templates visit https://github.com/LukasKava/VU_procedural_programming
And see files template.c and prepare_tasks.c
This file is creted to shorten amount of time i spend on creating folders and writing boiler plate code
*/

//TASK DESCRIPTION:
/*
Apibrėžkite funkciją, kuri grąžina failo dydį baitais.
Funkcijos prototipas: long getFileSize(char *fileName)
Aprašymas: funkcija gauna failo vardą kaip parametrą, bando jį atidaryti (skaitymui binariniu režimu), ir peršokus į failo
pabaigą (fseek) sužinoti (ftell) kiek baitų jis užima; tą baitų skaičių funkcija ir grąžina (patikrinkite su OS rodomomis
reikšmėmis), o jei kažkas nepavyko (pvz. tokio failo nėra) – funkcija grąžina reikšmę -1.
*/

 long getFileSize(char *fileName) {
	FILE *fp = fopen(fileName, "rb");
	if (fp == NULL) {
		printf(ERROR_TAG"Cannot open %s check if it exists or if it has correct permissions\n", fileName);
		return (-1);
	}

	if (fseek(fp, 0, SEEK_END) != 0) {
		printf(ERROR_TAG"fseek() has failed\n");
		return (-1);
	}

	long fileSize = ftell(fp);
	fclose(fp);
	if (fileSize == -1L) {
		printf(ERROR_TAG"ftell() has failed\n");
		return (-1);
	}
	return (fileSize);
 }


int main(void) {
	printf(LIGHT_CYAN_BOLD_UNDERLINE"[TASK DESCRIPTION]\n"NEAUTRAL);
	printf(LIGHT_GRAY"Read the main.c in folder task_7.5\n\n"NEAUTRAL);

	long int fileSize = 0;

	//Test if file does not exist
	fileSize = getFileSize("banana.txt");
	printf("Testing with file that does not exist %ld\n\n", fileSize);

	//Test if file does exist
	fileSize = getFileSize("hello.txt");
	printf("Testing with file that does exist %ld\n", fileSize);


	return (0);
}