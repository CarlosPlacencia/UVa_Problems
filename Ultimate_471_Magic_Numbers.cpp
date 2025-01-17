#include "stdafx.h"
#include <iostream>
#include <bitset>

using namespace std;

bool IsUnique(long long X); //Check if S1 has repeating digits

int main()
{
	int Num_Cases = 0;
	long long S1 = 0;
	long long S2 = 1;
	long long N = 0;

	cin >> Num_Cases;

	for (int i = 0; i < Num_Cases; i++)
	{
		cin >> N; // Number given
		S1 = N * S2;

		while (S1 <= 9876543210LL)
		{
			if (IsUnique(S1) && IsUnique(S2)) {
				printf("%lld / %lld = %lld\n", S1, S2, N);
			}

			S2++;
			S1 = N * S2;
		}

		 if (i != (Num_Cases - 1)) cout << "\n"; // Make sure you don't print extra white line
		S2 = 1;
	}

	return 0;
}


bool IsUnique(long long X) {

	bitset<10> Unique; //Keeps track if the digit has been seen
	int digit = 0;

	while (X != 0)
	{
		digit = X % 10; // gets the last digit

		if (Unique[digit] == 1) return false; // if the digit has been seen then
		else Unique[digit] = 1;				 // the number isn't unique

		X = X / 10;
	}
	return true;
}