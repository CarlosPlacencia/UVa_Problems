/*/////////////////////////////////////////////////////////////////////

Carlos Placencia : Horror Dash : 11799 : Galactic_Banana

Data structure required : Vectors

Tricks of the trade : 

*/////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include <iostream>;
#include <vector>;
#include <algorithm>;

using namespace std;


int main()
{
	int NumLines = 0;
	int NumCreatures = 0;
	int Creatures = 0;
	int Creature = 0;
	int MinimumSpeed = 0;
	int index = 1; // Keeps track of the cases 

	/*
	Use to test the output of the Vector
	for (int j = 0; j < NumCreatures; j++)
	{
	cout << creatures[j] << endl;
	}
	*/

	cin >> NumLines;

	for (int i = 0; i < NumLines; i++)
	{
		cin >> NumCreatures;
		vector<int> creatures(NumCreatures);

		for (int j = 0; j < NumCreatures; j++)
		{
			cin >> creatures[j];
		}

		sort(creatures.begin(), creatures.end());
		MinimumSpeed = creatures[NumCreatures - 1];

		cout << "Case " << index << ": " << MinimumSpeed << endl;

		index++;
	}

    return 0;
}

