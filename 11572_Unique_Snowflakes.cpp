// 11572_Unique_Snowflakes.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <map>
#include <vector>

using namespace std;


int main()
{
	ios_base::sync_with_stdio(false); //Speed!!
	cin.tie(nullptr);
	
	int TestCase_Num = 0;
	int Snowflakes_Num = 0;
	int Temp_Size = 0;
	int Max = 0;
	int X = 0; // Snowflake
	int counter = 0;
	int index = 0; 
	int key = 0; // Used to delete numbers from the map

	cin >> TestCase_Num >> Snowflakes_Num;

	for (int i = 0; i < TestCase_Num; i++)
	{
		map<int, int> Snowflakes;

		vector<int> Numbers(Snowflakes_Num);
		for (int i = 0; i < Numbers.size(); i++)
		{
			cin >> Numbers[i];

			Temp_Size = Snowflakes.size(); // Helps check if the insertion was true
			Snowflakes.insert(pair<int, int>(Numbers[i], i));

			if (Temp_Size != Snowflakes.size()) { // Snowflakes is unique
				counter++;
			}
			else
			{
				index = Snowflakes[Numbers[i]]; // Gives you the index of where the unique value was stored		
				int Vector_index = index; // Temporary to decrease
				map<int, int>::iterator it2 = Snowflakes.begin();
				vector<int> Temp;
				for (it2 = Snowflakes.begin(); it2 != Snowflakes.end(); it2++)
				{
					if (it2->second <= index) {
						Temp.push_back(it2->first);
						//Snowflakes.erase(key);
						Vector_index--;
					}
				}
				for (int z = 0; z < Temp.size(); z++) Snowflakes.erase(Temp[z]);
				Snowflakes.insert(pair<int, int>(Numbers[i], i));
				counter = Snowflakes.size();
			}
			
			if (counter > Max) Max = counter;

		}

		cout << Max << "\n";
		Max = 0;
		counter = 0;
		cin >> Snowflakes_Num;
	}

	
    return 0;
}
