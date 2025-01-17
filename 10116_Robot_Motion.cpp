/*/////////////////////////////////////////////////////////////////////

Carlos Placencia : Robot_Motion : 10116 : Galactic_Banana

Data structure required : vector

Tricks of the trade : In order order to know when the robot went out of bounds
					  I added 2 extra rows and columns. I also had a separate matrix
					  that kept track of the number of steps taken to get to a specific 
					  position.

*/////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); //Speed!!
	cin.tie(nullptr);

	int row = 0, col = 0, start = 0;
	
	cin >> row >> col >> start;

	// Add a while loop to loop every case
	while ((row + col + start) != 0) {

		bool flag = true;
		vector<vector<char>> Matrix(row + 2, vector<char>(col + 2, 'X'));

		// keeps track of visited area
		vector<vector<int>> Visited(row + 2, vector<int>(col + 2, -1)); 

		/* Loading the Matrix */
		for (int i = 1; i < row + 1; i++) {
			for (int j = 1; j < col + 1; j++) {
				cin >> Matrix[i][j];
			}
		}

	/*	for (int i = 0; i < row + 2; i++) {
			for (int j = 0; j < col + 2; j++) {
				cout << Matrix[i][j];
			}
			cout << "\n";
		}*/


		int r = 1, c = start, counter = 0;
		Visited[r][c] = 0; // setting the first step as seen

		while (flag){ // will break when the robot is looping
			// If the robot makes it out of the matrix then we would break from the loop

			if (Matrix[r][c] == 'N') r--; // Movement in the matrix
			else if (Matrix[r][c] == 'E') c++;
			else if (Matrix[r][c] == 'S') r++;
			else c--;

			counter++;

			if (Matrix[r][c] == 'X') break; // We have exited the matrix;

			if (Visited[r][c] != -1) flag = false; // check for loop
			else Visited[r][c] = counter; // store the number of steps done

		}

		if (!flag) { // We know that we where  in a loop 
			cout << Visited[r][c] << " step(s) before a loop of " << 
				counter  - Visited[r][c] << " step(s)" << "\n";
		}
		else cout << counter << " step(s) to exit" << "\n";

		cin >> row >> col >> start;
	}
    return 0;
}

