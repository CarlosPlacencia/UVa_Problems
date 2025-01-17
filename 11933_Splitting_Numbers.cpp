/*/////////////////////////////////////////////////////////////////////

Carlos Placencia : Rails : 11933 : Galactic_Banana

Data structure required : Bitsets

Tricks of the trade : Use bitsets (Number)to manipulate a binary string to get two
					  seperate binary string (a and b) based on the index where you see a 1

*/////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include <iostream>
#include <bitset>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); //Speed!!
	cin.tie(nullptr);

	int Number = 0;
	int counter = 0;

	cin >> Number;

	while (Number != 0)
	{
		int A_index = 1;
		int B_index = 1;

		bitset<32> Binary(Number);
		bitset<32> a; // Is Even
		bitset<32> b; // Is Odd

		counter = Binary.count(); // Tells me how many 1's bit-set Number has

		for (int i = 1; i < Binary.size() - 1; i++) // Splits the Binary string of (Number)
		{										
			if (Binary.test(i) == true)
			{
				if (A_index % 2 != 0) a[i] = 1;
				else b[i] = 1;
				A_index++;
				B_index++;
			}
		}

		if ((Number % 2) != 0) {
			b[0] = 1;
			cout << b.to_ullong() << " ";
			cout << a.to_ullong() << "\n";
		} 
		else
		{
			cout << a.to_ullong() << " ";
			cout << b.to_ullong() << "\n";
		}	
		cin >> Number;
	}
    return 0;
}
