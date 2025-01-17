/*/////////////////////////////////////////////////////////////////////

Carlos Placencia : Parentheses Balance : 673 : Galactic_Banana

Data structure required : Stacks

Tricks of the trade : Read in line by line and push or pop the characters
					  (Parentheses and brackets) to make sure the string
					  meets the problem requirments.

*/////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include <iostream>
#include <string>
#include <stack>

using namespace std;


int main()
{
	ios_base::sync_with_stdio(false); //Speed!!
	cin.tie(NULL);

	int Num_Lines = 0; // Will determine how many times I loop through the Text.txt file
	string sequence = "";

	cin >> Num_Lines;
	cin.ignore(); // Getline will not work if you don't ignore
	for (int i = 0; i < Num_Lines; i++)
	{
		stack<char> A;
		getline(cin, sequence);

		if ((sequence.size() % 2) == 0) //If the string is Odd then I don't have to check it
		{
				for (int i = 0; i < (sequence.size()); i++)
				{
					if (sequence[i] == '(' || sequence[i] == '[')
					{
						A.push(sequence[i]);
					}

					//checks if the open parentheses or bracket has been pushed
					// to the stack (A)

					if (!A.empty()) 
					{
						if (sequence[i] == ']' && A.top() == '[')
							A.pop();
						else if (sequence[i] == ')' && A.top() == '(')
							A.pop();
						else if (sequence[i] == ')' && A.top() != '(') // Knows the diffrence between a
							break;									   // Closing parentheses and bracket
						else if (sequence[i] == ']' && A.top() != '[')
							break;
					}
					else
					{
						// If you don't start with a open or close Parentheses or bracket
						// the string input is a No.
						A.push(sequence[i]);
						break;
					}
				}

				if (A.empty()) cout << "Yes" << "\n";
				else cout << "No" << "\n";
		}
		else cout << "No" << "\n";
	}
	return 0;
}

