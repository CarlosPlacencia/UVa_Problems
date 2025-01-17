/*/////////////////////////////////////////////////////////////////////

Carlos Placencia : Stern-Brocot Tree : 11350 : Galactic_Banana

Data structure required :

Tricks of the trade : Used recursion to get the end result of the input instructions (RRLL)

*/////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

// Find the result following the input path
void Stern_Brocot_Tree(string M, pair<long long int, long long int> p1, pair <long long int, long long int> p2,
	pair<long long int, long long int> p3, int index); 

int main()
{
	int TestCases = 0;
	int index = 0; // Keeps track of movement
	string Movements = "";
	pair<long long int, long long int> p1(0, 1); 
	pair<long long int, long long int> p2(1, 0);
	pair<long long int, long long int> p3(1, 1);


	cin >> TestCases;

	for (int i = 0; i < TestCases; i++) // Looping through the inputs
	{
		cin >> Movements;
		Stern_Brocot_Tree(Movements, p1, p2, p3, index);
	}

    return 0;
}

void Stern_Brocot_Tree(string M, pair<long long int, long long int> p1, pair < long long int, long long int> p2,
	pair<long long int, long long int> p3, int index) {
	if (index == M.size()) { // You have traversed through the input (Print Out)
		cout << p3.first << "/" << p3.second << "\n";
		return; 
	}
	else if (M[index] == 'R'){ // Right movement
		p1 = p3;
		p3.first = p1.first + p2.first;
		p3.second = p1.second + p2.second;
		index++;
		Stern_Brocot_Tree(M, p1, p2, p3, index);
	}
	else { // Left movement
		p2 = p3;
		p3.first = p1.first + p2.first;
		p3.second = p1.second + p2.second;
		index++;
		Stern_Brocot_Tree(M, p1, p2, p3, index);
	}

}

