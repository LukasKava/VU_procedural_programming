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

//TASK DESCRIPTION:
/*
Parašykite programą, kuri patikrina, ar eilutėje yra korektiškai įvesta data, formatu YYYY-MM-DD. Jei taip, programa turi
atspausdinti, kokia tai savaitės diena. Savaitės dienų pavadinimai turi būti skaitomi iš tekstinio failo „week.txt“, kuriame
yra iš anksto įrašytos septynios eilutės su atitinkamų dienų pavadinimais. Pakeitus pavadinimus faile (pvz. iš lietuvių
kalbos į anglų), programoje spausdinamos reikšmės irgi turi pasikeisti (automatiškai).
*/

//MONDAYPIRMADIENIS
//TUESDAYANTRADIENIS
//WENEDSDAYTRECIADIENIS
//THURSDAYKETVIRTADIENIS
//FRIDAYPENKTADIENIS
//SATURDAYSESTADIENIS
//SUNDAYSEKMADIENIS

//max 30
FILE *openingFile(char *filename, char *mode) {
	//Opening the week.txt
	FILE	*fp;
	fp = fopen(filename, mode);
	if (fp == NULL) {
		printf(ERROR_TAG"fopen() for file week.txt has failed!\n");
		printf("Exiting the program 1\n");
		return (NULL);
	}

	return (fp);
}

int	checkFileWeeksInput() {
	FILE *fp = NULL;
	
	if ((fp = openingFile("week.txt", "r")) == NULL) {
		return (1);
	}

	char	weekday[30] = {0};
	int		weekdayCount = 0;
	char	*weekdaysEnglish[] = {"MONDAY","TUESDAY","WENESDAY","THURSDAY","FRIDAY","SATURDAY","SUNDAY"};
	char	*weekdaysLithuanian[] = {"PIRMADIENIS","ANTRADIENIS","TRECIADIENIS","KETVIRTADIENIS","PENKTADIENIS","KETVIRTADIENIS","SESTADIENIS"};
	int		weekdayEMatch = 0;
	int		weekdayLMatch = 0;

	while (fgets(weekday, sizeof(weekday), fp) != NULL) {
		++weekdayCount;
		if (weekdayCount > 7) {
			printf(ERROR_TAG"File has to many lines of input\n");
			fclose(fp);
			return (1);
		}

		// Remove the newline character if present
		size_t len = strlen(weekday);
		if (len > 0 && weekday[len - 1] == '\n') {
			weekday[len - 2] = '\0';
		}

		//Wee need to check if the line contains correct Weekday
		if (strcmp(weekday, weekdaysEnglish[weekdayCount-1]) == 0) {
			++weekdayEMatch;
		}else if (strcmp(weekday, weekdaysLithuanian[weekdayCount-1]) == 0) {
			++weekdayLMatch;
		} else {
			printf(ERROR_TAG"In file line does not contain a weekday! It contains: [%s]\n", weekday);
			fclose(fp);
			return(1);
		}

		//All names should be either lithuanian or english cant have a mix
		if (weekdayEMatch != 0 && weekdayLMatch != 0) {
			printf(ERROR_TAG"Lithuanian and english weekdays are mixed. Please have either english or lithuanian at the same time\n");
			fclose(fp);
			return(1);
		}
	}

	if (weekdayCount != 7) {
		printf(ERROR_TAG"Some days are missing!\n");
		fclose(fp);
		return(1);
	}


	fclose(fp);
	if (weekdayEMatch != 0) {
		return (2);
	} else {
		return (3);
	}
}

//Zeller's congruence
int dayofweek(int d, int m, int y) 
{ 
    int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 }; 
    y -= m < 3;
	int day = ( y + y / 4 - y / 100 + y / 400 + t[m - 1] + d) % 7;
	day = (day + 6) % 7;
    return day;
}

//IMPORTANT! There is a better approach of instead of opening the text file every time and needing to keep it open
//Just read it once into the buffer and then close the file and keep on using that data of the buffer for error checking
//and other purposes. It prevents things like forgetting to fclose() and simplifies code a lot.
int main(void) {
	printf(LIGHT_CYAN_BOLD_UNDERLINE"[TASK DESCRIPTION]\n"NEAUTRAL);
	//To lazy to write everything out
	printf(LIGHT_GRAY"Read the main.c in folder task_6.4\n\n"NEAUTRAL);

	// 2 is english 3 is lithuanian
	int		englishOrLithuanian = 0;
	char	*weekdaysEnglish[] = {"MONDAY","TUESDAY","WENESDAY","THURSDAY","FRIDAY","SATURDAY","SUNDAY"};
	char	*weekdaysLithuanian[] = {"PIRMADIENIS","ANTRADIENIS","TRECIADIENIS","KETVIRTADIENIS","PENKTADIENIS","KETVIRTADIENIS","SESTADIENIS"};

	
	//Check if the file contains correct information
	if ((englishOrLithuanian = checkFileWeeksInput()) == 1) {
		return (1);
	}

	//Take the input day must be YYYY-MM-DD 
	int year;
	int month;
	int day;
	int nbrEnd;
	printf("Please enter the date YYYY-MM-DD;0 \"0\" is the ending number: ");
	int		scan_return = 0;
	// Check for valid input ALSO checking if someone is putting in something that does not belong to this scanf like a letter
	if ((scan_return = scanf("%d-%d-%d;%d", &year, &month, &day, &nbrEnd)) != 4 || nbrEnd != 0) {
		if (nbrEnd != 0) {
			printf(ERROR_TAG"The ending number should be 0\n");
		} else {
			printf(ERROR_TAG"Invalid input\n");
		}
		//Cleaning the buffer
		int c;
		while ((c = getchar()) != '\n' && c != EOF) {}
		return (1);
	}

	printf("Error checking 1: checking year: %d month: %d day: %d\n", year, month, day);

	if (year < 0 || year > 9999) {
		printf(ERROR_TAG"YEAR should be between 0 and 9999\n");
		return (1);
	}
	if (month < 0  || month > 12) {
		printf(ERROR_TAG"MONTH should be between 0 and 12\n");
		return (1);
	}
	if (day < 0 || day > 31) {
		printf(ERROR_TAG"DAY ending number should be 0\n");
		return (1);
	}

	int dayOfWeek =  dayofweek(day, month, year);
	if (englishOrLithuanian == 2) {
		printf(GREEN"ANSWER: %d-%d-%d is a weekday: %s %d\n"NEAUTRAL, year, month, day, weekdaysEnglish[dayOfWeek], dayOfWeek );
	} else {
		printf(GREEN"ANSWER: %d-%d-%d is a weekday: %s %d\n"NEAUTRAL, year, month, day, weekdaysLithuanian[dayOfWeek], dayOfWeek);
	}

	return (0);
}