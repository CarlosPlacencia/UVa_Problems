// OneTwoThree.cpp : #Of Problem GalacticBanana
//


#include "stdafx.h";
#include <string>;
#include <iostream>;

using namespace std;


int main()
{
	string one = "one";
	int NumberofLines = 0;
	int word_length = 0;
	int counter = 0;
	string word = "";

	cin >> NumberofLines;
	for (int i = 0; i < NumberofLines; i++)
	{
		cin >> word;
		if (word.length() == 5)
		{
			cout << "3" << endl;

		}
		else 
		{
			for  (int i = 0; i < word.length();  i++)
			{
				if (one[i] == word[i])
				{
					counter++;
				}
			}
			if (counter == 2)
			{
				cout << "1" << endl;
			}
			else
			{
				cout << "2" << endl;
			}
			counter = 0;
		}
	}

	//Reading lines from a file without knowing how many their are
	//while (getline(cin, word))
	//{
	//	cout << word << endl;
	//}


    return 0;
}

