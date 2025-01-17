/*/////////////////////////////////////////////////////////////////////

Carlos Placencia :Goldbach's Conjecture : 543 : Galactic_Banana

Data structure required : vectors

Tricks of the trade : 

*/////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); //Speed!!
	cin.tie(nullptr);

	int Number = 0;
	int Max_Number = 999999;

	vector<bool> PN(Max_Number + 1, 1);

	//Sieve
	for (int p = 2; p*p <= Max_Number; p++)
	{
		if (PN[p] == true) // If p stays true then it's a prime
		{
			for (int i = p * 2; i <= Max_Number; i += p) // Updating multiples of p
				PN[i] = false;
		}
	}

	cin >> Number;

	while (Number != 0)
	{

		for (int p = 2; p <= Number; p++) {
			if (PN[p]) {
				int X = Number - p;
				if (PN[X]) { // If the Result (X) of Number - p is a prime we found the answer
					cout << Number << " = " << p << " + " << X << "\n";
					break;
				}
			}
		}
		cin >> Number;
	}

    return 0;
}
