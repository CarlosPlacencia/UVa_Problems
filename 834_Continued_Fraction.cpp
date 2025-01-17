/*/////////////////////////////////////////////////////////////////////

Carlos Placencia : Rails : 834 Continued Fractions : Galactic_Banana

Data structure required : 

Tricks of the trade :  

*/////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include <iostream>

using namespace std;

int main() {
	int Numerator = 0;
	int Denomenator = 0;

	while (cin>> Numerator >> Denomenator)
	{
		int Continued_Numbers[32];
		int counter = 0; // Help me print the output
		int temporary = 0;

		while (Denomenator != 0) // Looping to get bk
		{
			Continued_Numbers[counter] = Numerator / Denomenator; // Getting the bk
			temporary = Numerator; // Storing Numerator so I can mod it with Denominator
			Numerator = Denomenator; 
			Denomenator = temporary % Denomenator;
			counter++; // Keeps track of how many numbers are put in Continued_Numbers
		}

		if(counter != 1)cout << "[" << Continued_Numbers[0] << ";";
		else cout << "[" << Continued_Numbers[0]; // Checking  if their is only one number
		for (int i = 1; i < counter; i++)
		{
			if (i == (counter - 1)) cout << Continued_Numbers[i];
			else cout << Continued_Numbers[i] << ",";
		}
		cout << "]" << "\n";
	}
	return 0;
}
