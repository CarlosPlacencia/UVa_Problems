
/*/////////////////////////////////////////////////////////////////////

Carlos Placencia : Andy's First Dictionary : 10815 : Galactic_Banana

Data structure required : sets

Tricks of the trade : Used a set to filter out repeated words

*/////////////////////////////////////////////////////////////////////


#include "stdafx.h"
#include <iostream>
#include <set>
#include <string>

using namespace std;

int main()
{

	ios_base::sync_with_stdio(false); //Speed!!
	cin.tie(nullptr);

	string  word = "";
	set<string> dictionary;

	while (cin >> word) {

		string temp_word = "";

		// Filter out the punctuation
		for (int i = 0; i < word.size(); i++)
		{
			if (isalpha(word[i]))
			{
				temp_word.push_back(tolower(word[i]));
			}
			else if (temp_word != "")
			{
				dictionary.insert(temp_word);
				temp_word = "";
			}
		}
		// Insert the word into the dictionary
		if(temp_word.size() != 0) dictionary.insert(temp_word);
	}

	// Print out what's in the dictionary in alphabetical order
	set<string>::iterator it;

	for (it = dictionary.begin(); it != dictionary.end(); it++)
		cout << *it << "\n";

	return 0;
}