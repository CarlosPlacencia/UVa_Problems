/*/////////////////////////////////////////////////////////////////////

Carlos Placencia : The Jackpot : 10684 : Galactic_Banana

Data structure required : 

Tricks of the trade : Used the algorithm found in page 104 (DYnamic Programing)

*/////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;


int main()
{
	int size = 0; // length of sequence
	
	cin >> size;

	while (size != 0)
	{
		int sum = 0;
		int ans = 0;

		vector<int> Numbers(size);
		
		/* Loading to the vector */
		for (int i = 0; i < Numbers.size(); i++) {
			cin >> Numbers[i];
		}

		for (int j = 0; j < Numbers.size(); j++) {
			sum += Numbers[j];
			if (sum > ans) ans = sum;
			if (sum < 0) sum = 0;
		}

		if (ans > 0) cout << "The maximum winning streak is " << ans << "." << "\n";
		else cout << "Losing streak." << "\n";

		cin >> size;
	}

    return 0;
}

