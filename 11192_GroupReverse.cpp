/*/////////////////////////////////////////////////////////////////////

Carlos Placencia : Group Reverse : 11192 : Galactic_Banana

Data structure required : Strings

Tricks of the trade : Read in the string of characters and then determined
					  how many groups the string had to be split into. Loaded the 
					  desired string into OutpuLine character by character.

*/////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;


int main()
{
	string InputLine = "";
	//string OutputLine = "";
	int GroupSize = 0;
	int NumberofGroups = 0;
	int TempNumGrp = 0; // Used to index through (InputLine)
	int length = 0;
	int counter = 0; //Keeps track as to when you are finished with one group
	int index = 2; //helps increment the TempNumGrp indexing

	cin >> GroupSize;
	//cout << GroupSize << endl;

	while (GroupSize != 0)
	{
		cin >> InputLine;
		length = InputLine.size();
		NumberofGroups = length / GroupSize;
		TempNumGrp = NumberofGroups;
		//OutputLine.resize(length);

		for (int  i = 0; i < length; i++)
		{
			//OutputLine[i] = InputLine[TempNumGrp - 1];
			cout << InputLine[TempNumGrp - 1];
			TempNumGrp--;
			counter++;

			if (NumberofGroups == counter) { //	increments the TempNumGrp when done reversing
				TempNumGrp = NumberofGroups; //	a group.
				TempNumGrp = (TempNumGrp * index);
				index++;
				counter = 0;
			}
		}

		cin >> GroupSize;
		TempNumGrp = NumberofGroups;//	Reseting for the next string input
		InputLine.clear();
		//OutputLine.clear();
		index = 2;
		cout << endl;

	}
    return 0;
}

