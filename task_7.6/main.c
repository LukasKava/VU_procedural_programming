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
Apibrėžkite funkciją, skirtą vartotojo sąsajoje pateikiamam meniu spausdinti ir vartotojo pasirinkimui gauti.
Funkcijos prototipas: int showMenu(char *menuTitle, char *menuOptions[], int menuSize, char *inputMsg)
Aprašymas: funkcija turi atspausdinti meniu antraštę (parametras menuTitle), tuomet atspausdinti meniu iš menuSize
pasirinkimų, kur meniu elementų (eilučių) pavadinimai pateikiami (eilučių) masyve menuOptions. Tuomet funkcija
atspausdina tekstinę eilutę inputMsg, kurioje perduodamas vartotojui skirtas tekstas, kuriame prašoma įvesti savo
pasirinkimą, ir gavusi iš vartotojo skaičių (atitinkamo meniu punkto numerį) jį ir grąžina; jeigu vartotojo įvedimas
nekorektiškas (įvedamas ne skaičius arba tokio meniu punkto nėra), visas spausdinimo procesas (antraštė, meniu,
prašymas įvesti) kartojamas iš naujo, tol, kol įvedimas netaps korektiškas.
*/

int showMenu(char *menuTitle, char *menuOptions[], int menuSize, char *inputMsg);

int main(void) {
	printf(LIGHT_CYAN_BOLD_UNDERLINE"[TASK DESCRIPTION]\n"NEAUTRAL);
	printf(LIGHT_GRAY"Read the main.c in folder task_7.3\n\n"NEAUTRAL);

	char	*menuTitle =  "Restaurant 123 menu";
	char	*menuOptions[] = {"Cepelinai", "Pica", "Makaronai", "Fish", "Doner", "Icecream"};
	int		menuSize = 6;

	int	selectedItem = showMenu(menuTitle, menuOptions, menuSize, "Please select the menu item of your liking.\nitem: ");

	printf("Selected item [%d]: %s\n", selectedItem, menuOptions[selectedItem]);

	return (0);
}

int showMenu(char *menuTitle, char *menuOptions[], int menuSize, char *inputMsg) {

	int	choice = 0;
	char input[10];
	char extra;

	while (1) {
		printf("\n%s\n", menuTitle);
		printf(LIGHT_GRAY"============================\n"NEAUTRAL);

		//printing menu options
		for (int i = 0; i < menuSize; ++i) {
			printf("[%d] => %s\n", i, menuOptions[i]);
		}

		printf("%s", inputMsg);

		choice = 0;
		if (fgets(input, sizeof(input), stdin) != NULL) {
            if (sscanf(input, "%d%c", &choice, &extra) == 1 || extra == '\n') {
                if (choice >= 0 && choice < menuSize) {
                    return  (choice);
                }
            }
        }
		printf(ERROR_TAG"Invalid input\n");
	}
	return (-1);
}