/*/////////////////////////////////////////////////////////////////////

Carlos Placencia : Vertex : 280 : Galactic_Banana

Data structure required : vector, bitset, queue

Tricks of the trade : Used Bread first search algorithm to traverse the graph

*/////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <queue>
#include <bitset>

using namespace std;


int main()
{	

	ios_base::sync_with_stdio(false); //Speed!!
	cin.tie(nullptr);

	int Vertices = 0;
	int Previous = 1;
	int from = 0;
	int to = 0;

	cin >> Vertices;
	while (Vertices != 0){
		vector<vector<int>> Graph(Vertices + 1);
		cin >> from;
		while ((Previous + from) != 0){
			cin >> to;
			while (to != 0) {  // Creating the Graph
				Graph[from].push_back(to);
				cin >> to;
				Previous = to;
			}
			cin >> from;
		}

		int Num_instructions = 0;
		int Starting_Vert = 0;
		queue<int> Q;

		cin >> Num_instructions;
		for (int i = 0; i < Num_instructions; i++)
		{
			cin >> Starting_Vert; // Starting Vector
			bitset<100> Tracker;

			Q.push(Starting_Vert); // Bread First Search
			while (!Q.empty()){
				int u = Q.front();
				Q.pop();
				for (int  j = 0; j < (int)Graph[u].size(); j++){
					int v = Graph[u][j];
					if (Tracker[v] == 0){
						Tracker[v] = 1;
						Q.push(v);
					}
				}
			}

			int counter = 0;
			int count = Tracker.count(); // Return how many bits where changed
			int inaccessible = Vertices - count; // Give me the number of inaccessible vertices

			if(inaccessible != 0) cout << inaccessible << " "; // Preventing extra whote space 
			else cout << inaccessible;
			for (int p = 1; p < (Vertices + 1); p++){
				if (Tracker[p] == 0 ){
					if (counter < (inaccessible - 1)) { // Preventing extra white space
						cout << p << " ";
						counter++;
					}
					else cout << p;
				}
			}
			cout << "\n";
		}

		cin >> Vertices;
	}
    return 0;
}

