/*/////////////////////////////////////////////////////////////////////

Carlos Placencia : Factors and Factorial : 160 : Galactic_Banana

Data structure required : vectors, map

Tricks of the trade : 

*/////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <map>
#include <cmath>

using namespace std;


int main()
{
	int Number = 0;											// Could've used the Sieve of Eratosthenes like 
	vector<int> POH = { 2, 3, 5,7,11, 13, 17, 19, 23, 29, 31, 37, 41, // in problem 543 Goldbach Conjecture 
									   43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};

	vector<int> Primes(101); // Will hold the amount of primes a number contains (5! = 3-2's, 1-3, 1-5)
	map<int, vector<int>> X;

	for (int i = 2; i <= 100; i++) // Load my uordered_map with all the number of primes it contains
	{
		X.insert(pair<int, vector<int>>(i, Primes)); //
		map<int, vector<int>>::iterator it2 = X.find(i);

		int temp = i;
		while (i % 2 == 0) // Tests for the even numbers
		{
			it2->second[2] += 1;
			i = i / 2;
		}

		for (int j = 3; j <= sqrt(i); j = j + 2) // Test for the odd numbers
		{
			// While i divides n, print i and divide n 
			while (i%j == 0)
			{
				it2->second[j] += 1;
				i = i / j;
			}
		}

		if (i > 2) // When i is greater than 2
			it2->second[i] += 1;

		i = temp;
	}

	cin >> Number;
	while (Number != 0) {
		int counter = 0;
		vector<int> Result(101);
		map<int, vector<int>>::iterator it2;

		for (it2 = X.begin(); it2 != X.find(Number + 1); it2++)// Loops through all the values in the 
		{													   // unordered map and adds the vectors together
			for (int i = 2; i <= 100; i++)
			{
				Result[i] += it2->second[i];
			}
		}

		// Print out
		printf("%3d! =", Number);
		for (int e = 0; e < POH.size(); e++)
		{
			int r = POH[e];
			if (Result[r] > 0) {
				counter++;
				if (counter > 15)	counter -= 15, printf("\n      "); // Print 7 spaces 
				printf("%3d", Result[r]);
			}
		}
		cout << "\n";
		cin >> Number;
	}

    return 0;
}

