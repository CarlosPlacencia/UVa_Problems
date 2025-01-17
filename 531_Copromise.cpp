/*/////////////////////////////////////////////////////////////////////

Carlos Placencia : Compromise : 531 : Galactic_Banana

Data structure required : 

Tricks of the trade : Utilize the algorithm found in page 246

*/////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()

{

	ios_base::sync_with_stdio(false); //Speed!!
	cin.tie(nullptr);

	string word = "";
	while (cin >> word) {
		vector<string> Text1;
		vector<string> Text2;

		while (word != "#") { // Loading the vector
			Text1.push_back(word);
			cin >> word;
		}
		cin >> word;
		while (word != "#") { // Loading the vector
			Text2.push_back(word);
			cin >> word;
		}

		int Txt1_size = Text1.size();
		int Txt2_size = Text2.size();
		vector<vector<int>> Matrix(Txt1_size + 1, vector<int>(Txt2_size + 1, 0));

		for (int i = 1; i <= Txt1_size; i++)
			for (int j = 1; j <= Txt2_size; j++) {
				// match = 2 points, mismatch = -1 point
				Matrix[i][j] = Matrix[i - 1][j - 1] + (Text1[i - 1] == Text2[j - 1] ? 1 : -50); // cost for match or mismatches
																					 // insert/delete = -1 point
				Matrix[i][j] = max(Matrix[i][j], Matrix[i - 1][j]); // delete
				Matrix[i][j] = max(Matrix[i][j], Matrix[i][j - 1]); // insert
			}

		/* Getting the subsequence */
		stack<string> subseq;
		int X_index = Txt1_size;
		int Y_index = Txt2_size;
		int counter = 0;

		while (Matrix[X_index][Y_index] > 0) {
			if (Text1[X_index - 1] == Text2[Y_index - 1]) {
				subseq.push(Text1[X_index - 1]);
				X_index--;
				Y_index--;
			}
			else if (Matrix[X_index - 1][Y_index] > Matrix[X_index][Y_index - 1])X_index--;
			else Y_index--;
		}

		/* Printing Out the Subsequence */
		while (!subseq.empty())
		{
			if (counter < 1) {
				cout << subseq.top();
				counter++;
				subseq.pop();
			}
			else {
				cout << ' ' << subseq.top();
				subseq.pop();
			}
		}

		cout << "\n";
	}
    return 0;
}

