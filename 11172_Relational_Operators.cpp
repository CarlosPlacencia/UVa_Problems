// Carlos Placencia : Relational Operator : 11172: Galactic_Banana
// Data structure required: 
// Tricks of the trade: Simple comparioson of two number to determine 
//						if a number is equall, greater than , or less than. 					

#include "stdafx.h";
#include <iostream>;

using namespace std;


int main()
{
	int NumLines = 0; 
	int Number1 = 0;
	int Number2 = 0;
	cin >> NumLines;
	for (int i = 0; i < NumLines; i++)
	{
		cin >> Number1;
		cin >> Number2;

		if (Number1 < Number2)
		{
			cout << "<" << endl;
		}
		else if (Number1 > Number2)
		{
			cout << ">" << endl;
		}
		else
		{
			cout << "=" << endl;
		}

	}
    return 0;
}

