//2.a
//a) Binary to Decimal

//11011 => 27 (2^0 + 2^1 + 2^3 + 2^4)
//10010100 => 148 (2^2 + 2^4 + 2^7)
//11001011010101 => 13013 (2^0 + 2^2 + 2^4 + 2^6 + 2^7 + 2^9 + 2^12 + 2^13)

//b) Decimal to Binary

// IDEA: was to devide by 2 until I come to 0 and on each division step see if there is any remainder if there is mark it as 1 else 0 and then write everything from bottom to top
//37 => 100101
//241 => 11110001
//2487 => 100110110111

//c) Hexadecimal to decimal (Hexadecimal  0123456789 10 = A 11 = B 12 = C 13 = D 14 = E 15 = F)

// IDEA: take the positional number and multiple it by 16 ^ position and add all the numbers
// 6E2 => 6 * 16 ^ 2 + 14 * 16 ^ 1 + 2 * 16 ^ 0 = 1762
// ED33 => 60723
// 123456 => 1193046

//d) Decimal to Hexadecimal

// IDEA: Do the same as binary just divide by 16 but take the remainder and multiple it by 16 to get the Hexadecimal equivalent and write it from bottom to top
// 243 => F3
// 2483 => 9B3
// 4612 => 1204


//Task 2.b

#include <stdio.h>

void	printBinaryToDecimal(char *binaryString) {

	//Check the len of the string by looping through it
	int i = 0;
	while (binaryString[i] != '\0') {
		i++;
	}
	i--; // So that we would not start going backwards from the end of the string '\0'

	int decimalValue = 0;
	int numberPosition = 0;
	while (i >= 0) {
		decimalValue += (binaryString[i--] - '0') << numberPosition; // a * 2 ^ numberPosition
		numberPosition++;
	}

	printf("Binary: %s => Decimal: %d\n", binaryString, decimalValue);
}

void	printDecimalToBinary(int decimalNumber) {
	//Recursive way to adjust that we need to print it out from the other end
	if (decimalNumber > 1) {
		printDecimalToBinary(decimalNumber / 2);
	}
	printf("%d", decimalNumber % 2);
}

void	printHexaToDecimal(char *hexa) {
	int i = 0;
	while (hexa[i] != '\0') {
		i++;
	}
	i--;

	int numberPosition = 0;
	int decimalValue = 0;
	while(i >= 0) {
		if (hexa[i] >= '0' && hexa[i] <= '9') {
			decimalValue += (hexa[i] - '0') << (numberPosition * 4);
		} else if (hexa[i] >= 'A' && hexa[i] <= 'F') {
			decimalValue += (hexa[i] - 'A' + 10) << (numberPosition * 4);
		}

		numberPosition++;
		i--;
	}
	printf("Hexadecimal: %s => Decimal: %d\n", hexa, decimalValue);
}

void	printDecimalToHexadecimal(int decimalNumber) {
		char	*hexadecimals = "0123456789ABCDEF";
		if (decimalNumber > 16) {
			printDecimalToHexadecimal(decimalNumber / 16);
		}
		printf("%c", hexadecimals[decimalNumber % 16]);
}

int main(void) {

//A) Binary to Decimal
	char *binaryString1 = "11011";
	char *binaryString2 = "10010100";
	char *binaryString3 = "11001011010101";

	printBinaryToDecimal(binaryString1);
	printBinaryToDecimal(binaryString2);
	printBinaryToDecimal(binaryString3);
	
	printf("\n\n");

//B) Decimal to Binary
	int decimalOne = 37;
	int decimalTwo = 241;
	int	decimalThree = 2487;

	printf("Decimal: %d => Binary: ", decimalOne);
	printDecimalToBinary(decimalOne);
	printf("\nDecimal: %d => Binary: ", decimalTwo);
	printDecimalToBinary(decimalTwo);
	printf("\nDecimal: %d => Binary: ", decimalThree);
	printDecimalToBinary(decimalThree);

	printf("\n\n\n");

//C) Hexadecimal to decimal
	char *hexaString1 = "6E2";
	char *hexaString2 = "ED33";
	char *hexaString3 = "123456";

	int hexOne = 0x6E2;
	int hexTwo = 0xED33;
	int hexThree = 0x123456;
	
	printHexaToDecimal(hexaString1);
	printHexaToDecimal(hexaString2);
	printHexaToDecimal(hexaString3);

	printf("\n\033[0;32mCHECKING: Hexadecimal to decimal only using printf()\033[0m\n");

	printf("Hexadecimal: %X => Decimal: %d\n", hexOne, hexOne);
	printf("Hexadecimal: %X => Decimal: %d\n", hexTwo, hexTwo);
	printf("Hexadecimal: %X => Decimal: %d\n", hexThree, hexThree);

	printf("\n\n");

//D) Decimal to Hexadecimal
	decimalOne = 243;
	decimalTwo = 2483;
	decimalThree = 4612;

	printf("Decimal: %d => Hexadecimal: ", decimalOne);
	printDecimalToHexadecimal(decimalOne);
	printf("\nDecimal: %d => Hexadecimal: ", decimalTwo);
	printDecimalToHexadecimal(decimalTwo);
	printf("\nDecimal: %d => Hexadecimal: ", decimalThree);
	printDecimalToHexadecimal(decimalThree);

	printf("\n\n\033[0;32mCHECKING: Decimal to hexadecimal only using printf()\033[0m\n");

	printf("Decimal: %d => Hexadecimal: %X\n", decimalOne, decimalOne);
	printf("Decimal: %d => Hexadecimal: %X\n", decimalTwo, decimalTwo);
	printf("Decimal: %d => Hexadecimal: %X\n", decimalThree, decimalThree);

	printf("\n\n");

	return (0);

}