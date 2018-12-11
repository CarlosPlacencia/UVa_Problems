/*/////////////////////////////////////////////////////////////////////

Carlos Placencia : Rails : 355 The Bases Are Loaded : Galactic_Banana

Data structure required : 

Tricks of the trade :  Convert the Number to Decimal and then convert it to the desired base

*/////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

void Convert(bool flag, int Decimal, int base, int ConvertTo,   // Function to print out and convert Decimal to any base
	int BaseofNumber, char Number[]);

int main() {
	int BaseofNumber = 0;
	int ConvertTo = 0;
	char Number[20];

	while (cin >> BaseofNumber >> ConvertTo >> Number) {
		bool flag = false;
		long long Decimal = 0, base = 1;

		for (int  i = 0; Number[i]; i++) // Looping through the array
		{									// Converting to decimal
			Decimal *= BaseofNumber;
			if (Number[i] >= '0' && Number[i] <= '9')
			{
				if (Number[i] - '0' >= BaseofNumber)flag = true; // Checking to see if the number is an
				else Decimal += Number[i] - '0';				// illegal base
			}
			else {
				if (Number[i] - 'A' + 10 >= BaseofNumber) flag = true; // Checking for A-F
			}
		}

		Convert(flag, Decimal, base, ConvertTo, BaseofNumber, Number); // Converting to the desired base

	}
	return 0;
}

void Convert(bool flag, int Decimal, int base, int ConvertTo, 
	int BaseofNumber, char Number[]) {
	if(flag) printf("%s is an illegal base %d number\n", Number, BaseofNumber);
	else {
		long long  New_Number[50] = {};
		long long counter = -1;

		while (Decimal)
		{
			New_Number[++counter] = Decimal % ConvertTo; // converting the decimal to the new base (new_number)
			Decimal /= ConvertTo;
		}

		if (counter < 0) counter = 0;
		printf("%s base %d = ", Number, BaseofNumber);
		while (counter >= 0)
		{										// Checking for A-F so we can display them
			printf("%c", New_Number[counter] <= 9 ? New_Number[counter] + '0' : New_Number[counter] - 10 + 'A');
			counter--;
		}
		printf(" base %d\n", ConvertTo);
	}
}

