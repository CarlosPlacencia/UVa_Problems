// 10082_Wertyu.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	string InputLine = "";
	string OutputLine;
	string Input_Characters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890-=[]\\;',./ ";
	string Output_Characters = " VXSWDFGUHJKNBIO EARYCQZT `1234567890-P[]L;M,. ";

	int String_Size = 0;
	int Character_Index = 0;

	while (getline(cin, InputLine))
	{
		String_Size = InputLine.size();
		OutputLine.resize(String_Size); //Gives the string the necessary size

		for (int i = 0; i < String_Size; i++)
		{
			Character_Index = Input_Characters.find(InputLine[i]);
			//cout << "Index Number of " << InputLine[i] << " is " << Character_Index << endl;
			OutputLine[i] = Output_Characters[Character_Index];
		}

		cout << OutputLine << endl;

		InputLine.clear();
		OutputLine.clear();
	}
    return 0;
}


