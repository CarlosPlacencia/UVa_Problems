// Carlos Placencia : Cost Cutting : 11727 : Galactic_Banana
// Data structures required:
// Tricks of the trade:  

#include "stdafx.h"
#include <iostream>;

using namespace std;

int main()
{
	int NumLines = 0;
	int Number1 = 0;
	int Number2 = 0;
	int Number3 = 0;
	int index = 1;

	cin >> NumLines;

	for (int i = 0; i < NumLines; i++)
	{

		cin >> Number1;
		cin >> Number2;
		cin >> Number3;

		if (Number1 > Number2 && Number1 < Number3 || Number1 < Number2 && Number1 > Number3)
		{
			cout << "Case " << index << ": " << Number1 << endl;
		}
		else if (Number2 > Number1 && Number2 < Number3 || Number2 < Number1 && Number2 > Number3)
		{
			cout << "Case " << index << ": " << Number2 << endl;
		}
		else
		{
			cout << "Case " << index << ": " << Number3 << endl;
		}

		index++;
	}
    return 0;
}

