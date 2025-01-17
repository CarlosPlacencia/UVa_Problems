/*/////////////////////////////////////////////////////////////////////

Carlos Placencia : Rotated squares : 10855 : Galactic_Banana

Data structure required : Vectors

Tricks of the trade : Two functions are created, Rotate and Compare. The rotate function
					  rotates the small_matrix(n). Its then send to the compare function
					  to check if the small_matrix is a sub matrix of Big_matrix(N)

*/////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

void Rotate(vector<vector<char>>& Small_Matrix, int n);
int Compare(vector<vector<char>> Small_Matrix, const vector<vector<char>>& Big_Matrix, 
	int N, int n, int Times_Repeating, int counter);


int main()
{

	int N = 0; // Big_matrix size
	int n = 0; // Small_matrix size
	int counter = 0; //check how many times matrix n is found in matrix N
	int Times_Repeating = 0; // how many times matrix n is in matrix N
	int degrees = 0; // Helps with the rotation
	int Prevent_extra_space = 0;

	cin >> N >> n;
	while (N && n != 0)
	{
		vector<vector<char>> Big_Matrix(N, vector<char>(N)); // Initializing the matrices
		vector<vector<char>> Small_Matrix(n, vector<char>(n));
		//cout << N << "x" << N << "\n";

		for (int r = 0; r < N; r++) // Loading in the Big_Matrix!
		{
			for (int c = 0; c < N; c++)
			{
				cin >> Big_Matrix[r][c];
				//cout << Big_Matrix[r][c];
			}
			//cout << endl;
		}

		//cout << "\n";
		//cout << n << "x" << n << "\n";
		for (int r = 0; r < n; r++) // Loading in the Small_Matrix!
		{
			for (int c = 0; c < n; c++)
			{
				cin >> Small_Matrix[r][c];
				//cout << Small_Matrix[r][c];
			}
			//cout << endl;
		}
		//cout << "\n";
		//cout << N << "X" << N << "\n";
		while (degrees != 360)
		{

			cout << Compare(Small_Matrix, Big_Matrix, N, n, counter, Times_Repeating);
			if (Prevent_extra_space == 3) break;
			cout << " ";
			Rotate(Small_Matrix, n);
			degrees += 90;
			Prevent_extra_space++;

		}
		cout << "\n";
		degrees = 0;
		Prevent_extra_space = 0;
		cin >> N >> n;
	}

    return 0;
}

void Rotate(vector<vector<char>>& Small_Matrix, int n) {
	//cout << "Printing from the Rotate Function" << endl;

	vector<vector<char>> Rotated_Matrix(n, vector<char>(n));

	for (int r = 0; r < n; r++) // Loading in the Small_Matrix!
	{
		for (int c = 0; c < n; c++)
		{
			Rotated_Matrix[c][n - r - 1] = Small_Matrix[r][c];
		}
	}
	for (int r = 0; r < n; r++)
	{
		for (int c = 0; c < n; c++)
		{
			Small_Matrix[r][c] = Rotated_Matrix[r][c];
			//cout << Rotated_Matrix[r][c];
		}
		//cout << endl;
	}
}

int Compare(vector<vector<char>> Small_Matrix, const vector<vector<char>>& Big_Matrix, 
	int N, int n, int Times_Repeating, int counter) 
{
		for (int r = 0; r < N; r++) {
			for (int c = 0; c < N; c++) { // add boundaries 
				if (Big_Matrix[r][c] == Small_Matrix[0][0] && (r + n) <= N && (c + n) <= N)  {
					//cout << "Found a possible sub matrix" << endl;
					for (int r1 = 0; r1 < n; r1++)
					{
						for (int c1 = 0; c1 < n; c1++)
						{
							if (Big_Matrix[r1 + r][c1 + c] == Small_Matrix[r1][c1]) {
								counter++;
								//cout << "Counter: " << counter << endl;
								if (counter == n * n) {
									Times_Repeating++;
									counter = 0;
								}
							}

						}
					}
					counter = 0;
				}
			}
		}

	return Times_Repeating;
}