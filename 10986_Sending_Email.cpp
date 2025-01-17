/*/////////////////////////////////////////////////////////////////////

Carlos Placencia : Sending_Email : 10986 : Galactic_Banana

Data structure required : vector, prioity_queue

Tricks of the trade : Used Dijkstra's Algorithm found in books page 148 to 
					  get the shortest distance from point S to T

*/////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <queue>

#define INF 1000000000

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); //Speed!!
	cin.tie(nullptr);

	int Num_cs = 0, n = 0, m = 0, S = 0, T = 0;
	int from = 0, to = 0, latency = 0;

	cin >> Num_cs;

	for (int i = 0; i < Num_cs; i++){
		// Declare vectors
		cin >> n >> m >> S >> T;
		vector<vector<pair<int,int>>> Graph(n); // setting up graph
		for (int j = 0; j < m; j++){
			cin >> from >> to >> latency;  // Loading the graph
			Graph[from].push_back(pair<int, int>(to, latency)); // Bidirectional 
			Graph[to].push_back(pair<int, int>(from, latency));
		}

		// Dijkstra's Algorithm
		vector<int> dist(n, INF); // Contain the vertex value
		dist[S] = 0; // S is the starting vertex with weight of 0

		priority_queue < pair<int, int>,vector < pair<int, int>>, greater<pair<int, int>>> pq;
		pq.push(pair<int,int>(0, S));
		while (!pq.empty()){
			pair<int, int> front = pq.top();
			pq.pop();
			int d = front.first, u = front.second;
			if (d > dist[u]) continue;
			for (int j = 0; j < (int)Graph[u].size(); j++){
				pair<int, int> v = Graph[u][j];
				if (dist[u] + v.second < dist[v.first]){
					dist[v.first] = dist[u] + v.second;
					pq.push(pair<int, int>(dist[v.first], v.first));
				}
			}
		}
		if(dist[T] < INF) cout << "Case #" << i + 1 << ": " << dist[T] << "\n";
		else cout << "Case #" << i + 1 << ": " << "unreachable"<< "\n";
	}
	
    return 0;
}

