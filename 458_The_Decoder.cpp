// 458_The_Decoder.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream> 
#include <string>

using namespace std;


int main()
{
	string InputLine = "";
	//string OutputLine = "";
	int String_Size = 0;

	while (getline(cin, InputLine)) {

		String_Size = InputLine.size();
		//OutputLine.resize(String_Size);

		for (int i = 0; i < String_Size; i++)
		{
			InputLine[i] = int(InputLine[i]) - 7;
		}
		cout << InputLine << endl;
	}
    return 0;
}