#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stack>

using namespace std;

bool Comp(pair<char, int> a, pair<char, int> b);

int main() {

	int N = 0, H = 0, W = 0, counter = 1;

	cin >> N;
	for (int i = 0; i < N ; i++){
		cin >> H >> W;
		vector<vector<char>> Map((H + 2), vector<char>((W + 2), '#'));
		vector<pair<char,int>> L; // keep track of the diffrent letters in the map

		for (int i = 1; i <= H; i++){
			for (int j  = 1; j <= W; j++){
				cin >> Map[i][j];
			}
		}

	/*	for (int i = 0; i < h + 2; i++) {
			for (int j = 0; j < w + 2; j++) {
				cout << map[i][j];
			}
			cout << "\n";
		}*/

		vector<int> ASCII(128, 0); // ASCII Table
		stack<pair<int, int>> S;
		pair<int, int> Coordinates;
		for (int r = 1; r <= H; r++){
			for (int c = 1; c <= W; c++){
				if (Map[r][c] != '#') {
					char letter = Map[r][c];
					Coordinates = pair<int, int>(r, c);
					S.push(Coordinates);
					Map[r][c] = '#';
					while (!S.empty()){
						int x = Coordinates.first, y = Coordinates.second;
						if (Map[x - 1][y] == letter) { // UP
							S.push(pair<int, int>((x - 1), y));
							Map[x - 1][y] = '#';
						}
						if (Map[x + 1][y] == letter) { // Down
							S.push(pair<int, int>((x + 1), y));
							Map[x + 1][y] = '#';
						}
						if (Map[x][y - 1] == letter) { // Left
							S.push(pair<int, int>(x, (y - 1)));
							Map[x][y - 1] = '#';
						}
						if (Map[x][y + 1] == letter) { // Right
							S.push(pair<int, int>(x, (y + 1)));
							Map[x][y + 1] = '#';
						}
						Coordinates = S.top(); S.pop();
					}
					// Add to the ASCII Table
					ASCII[letter] += 1;
				}
			}
		}
		
		for (int i = 97; i <= 122; i++){
			if (ASCII[i] != 0) {
				L.push_back(pair<char, int>(char(i), ASCII[i]));
			}
		}

		sort(L.begin(), L.end(), Comp);

		/* Displat Output */
		cout << "World #" << counter << "\n";
		for (int a = 0; a < L.size(); a++){
			cout << L[a].first<< ": " << L[a].second << "\n";
		}

		counter++;
	}

	return 0;
}

bool Comp(pair<char, int> a, pair<char, int> b) {
	if (a.second == b.second) {
		return a.first < b.first;
	}
	else {
		return a.second > b.second;
	}
}