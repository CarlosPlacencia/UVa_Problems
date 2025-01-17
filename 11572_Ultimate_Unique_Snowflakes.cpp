/*/////////////////////////////////////////////////////////////////////

Carlos Placencia : Unique Snowflakes : 11572 : Galactic_Banana

Data structure required : unordered_map

Tricks of the trade :

*/////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;


int main()
{
	// Used to read in the inputs
	int Number_Cases = 0;
	int Number_Snowflakes = 0;
	int Snowflake = 0;

	int Size_Unique_Snowflakes = 0; // Helps keep track if the insertion was a succes
	int counter = 0; // Keep track how many snowflakes you see in a row
	int index = 0; // 
	int Max = 0;

	cin >> Number_Cases >> Number_Snowflakes;

	for (int i = 0; i < Number_Cases; i++)
	{
		unordered_map<int, int> Unique_Snowflakes; // Keeps track of unique snowflake
		for (int j = 0; j < Number_Snowflakes; j++)
		{
			cin >> Snowflake;

			Size_Unique_Snowflakes = Unique_Snowflakes.size(); 
			Unique_Snowflakes.insert(pair<int, int>(Snowflake, j));// Use the value in the map to
																   // determine what to erase from the map

			if (Size_Unique_Snowflakes != Unique_Snowflakes.size()) counter++;
			else {
				
				index = Unique_Snowflakes[Snowflake]; // geting the value of the key to delete
				unordered_map<int, int>::iterator it; // Iterates through the map to erase  keys
				vector<int> ToBeErased;

				for (it = Unique_Snowflakes.begin(); it != Unique_Snowflakes.end(); it++) { // Finding the unwanted snowflakes
					if (it->second <= index)
					{
						if (it->second <= index) {
							ToBeErased.push_back(it->first);
						}
					}

					for (int z = 0; z < ToBeErased.size(); z++) Unique_Snowflakes.erase(ToBeErased[z]); // Deleting the unwanted snowflakes
					Unique_Snowflakes.insert(pair<int, int>(Snowflake, j));
					counter = Unique_Snowflakes.size();
				}

				counter = Unique_Snowflakes.size(); // Length after deletion
			}
			if (counter > Max) Max = counter;
		}

		cout << Max << "\n";
		Max = 0;
		counter = 0;

		cin >> Number_Snowflakes;
	}



    return 0;
}

