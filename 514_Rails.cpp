/*/////////////////////////////////////////////////////////////////////

Carlos Placencia : Rails : 514 : Galactic_Banana

Data structure required : Stacks

Tricks of the trade : Use a stack to control the traffic of coaches (1,2,...,N)
					  and check if you can get the desirable input

*/////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include <iostream>
#include <stack>
#include <vector>

using namespace std;


int main()
{
	/*
		Stacks functions:
			- .push() -> pushes the number to the stack
			- .pop() -> deletes the number from the stack
			- .top() -> gets the value thats on top of the stack 
	*/

	ios_base::sync_with_stdio(false); //Speed!!
	cin.tie(NULL);
	
	int N = 0;
	int counter = 0; // used to index my vector
	int Cindex = 1; // numbers that will be pushed to the stack

	cin >> N;
	while (N != 0)
	{
		vector<int> A(N);
		cin >> A[0];

		while (A[0] != 0) // If the next number is a 0 then it will break
		{
			for (int i = 1; i < N; i++)
			{ 
				cin >> A[i]; // Loading vector
			}

			stack<int> C;
			while (counter < N)
			{						// Load the stack first and then check if the top matches the 
				C.push(Cindex);		// first number in the vector
				while (C.top() == A[counter] && !C.empty()) 
				{
					C.pop();
					counter++;
					if (C.empty()) break;
				}
				if (Cindex >= N) break; // Exit once you've looped through N times
				Cindex++;
			}
			counter = 0;
			Cindex = 1;

			if (C.empty()) cout << "Yes" << "\n";
			else cout << "No" << "\n";

			cin >> A[0];
		}
		cout << "\n";
		cin >> N;
	}
	return 0;
}

