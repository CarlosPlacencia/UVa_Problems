/*/////////////////////////////////////////////////////////////////////

Carlos Placencia : Hay Points : 10295 : Galactic_Banana

Data structure required : map

Tricks of the trade :

*/////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include <iostream>
#include <map>
#include <string>

using namespace std;


int main()

{
	int Dic_words = 0;
	int Num_jobs = 0;
	int Salary = 0;
	int Total = 0;

	string Dic_Word = "";
	string Word = "";

	map<string, int> Dictionary;

	cin >> Dic_words >> Num_jobs;

	for (int j = 0; j < Dic_words; j++) // Loading the Dictionary
	{
		cin >> Dic_Word >> Salary;
		Dictionary.insert(pair<string, int>(Dic_Word, Salary));
	}

	for (int i = 0; i < Num_jobs; i++)
	{
		cin >> Word;  // Reading in the job descriptions
		
		while (Word != ".")
		{
			// Check if the word is in the map and add its value to total
			if (Dictionary[Word])
			{
				Total += Dictionary[Word];
			}
			cin >> Word;
		}
		cout << Total << "\n";
		Total = 0;
	}

	return 0;
}

/*
700150
150
0
100000
0
200000
10000000
*/