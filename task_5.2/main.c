#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define RED "\033[0;31m"
#define NEAUTRAL "\033[0m"

/*
Parašykite programą, kurios viduje apibrėžiamas masyvas, galintis sutalpinti 1000 elementų. Ši programa turi paprašyti
vartotojo įvesti tris skaičius (a, b, c), į masyvą įrašyti c atsitiktinai sugeneruotų reikšmių, kurių kiekviena priklauso
intervalui [a; b], ir atspausdinti masyvo turinį (tas c reikšmių) į ekraną.
• Kad gautumėte atsitiktinį skaičių, pasinaudokite rand() funkcija iš <stdlib.h>, kuri leidžia gauti atsitiktinį skaičių iš
intervalo [0; RAND_MAX]
• Sugeneruotą reikšmę reikės transformuoti taip, kad ji papultų į nurodytą intervalą, aritmetinių operacijų pagalba
• Kad keletą kartų paleidus programą gautumėte vis kitus skaičius, pasinaudokite funkcija srand() iš <stdlib.h>,
kuriai paduokite kaskart kitokį skaičių. Vienas iš sprendimų – pasinaudoti funkcija time(NULL) iš <time.h>, kad
atsitiktinių skaičių generatorius būtų inicializuojamas priklausomai nuo nuolat kintančio programos paleidimo
laiko momento.
*/

int main(void) {
	int	element_holder[1000] = {0};
	int	c = 0;
	int a = 0, b = 0;

	printf(GREEN"Please enter 3 numbers a, b, c:\n"NEAUTRAL);
	printf("number c is gonna be used to determine how many elements gonna be filled in the array\n");
	printf(YELLOW"[Please follow these instructions]"NEAUTRAL" c has to be from 0 up to 1000\n");
	printf("numbers [a, b] are gonna be used to generate the numbers in between these numbers:\na being a lower bound and b being upper bound\n");
	printf(YELLOW"[Please follow these instructions]"NEAUTRAL" a < b  and they have to be between 0 and 10000\n\n");

	//Taking input c
	printf("Please enter c: ");
	scanf("%d", &c);

	while (c < 0 || c > 999) {
		printf(RED"Wrong input should be between 0 and 999\n"NEAUTRAL);
		printf("c: ");
		scanf("%d", &c);
	}

	//Taking input a
	printf("\nPlease enter a: ");
	scanf("%d", &a);

	while (a < 0 || a > 10000) {
		printf(RED"Wrong input should be between 0 and 10000\n"NEAUTRAL);
		printf("a: ");
		scanf("%d", &a);
	}

	//Taking input b
	printf("\nPlease enter b: ");
	scanf("%d", &b);

	while ((b < 0 || b > 10000) || a > b) {
		printf(RED"Wrong input should be between 0 and 10000\n"NEAUTRAL);
		printf("b: ");
		scanf("%d", &b);
	}

	//USING rand()
	
	//To generate the pseudo random numbers we use a seed
	// If we want different sequence each time we can generate using srand(time(NULL));
	srand(time(NULL));

	for (int i = 0; i <= c; ++i) {
		//Generating random number between [a;b]
		element_holder[i] = a + rand() % (b - a + 1);
	}

	//Print out random numbers in the array
	for (int i = 0; i <= c; ++i) {
		printf("element[%d]: %d\n", i, element_holder[i]);
	}

	printf("\n");
	return (0);
}