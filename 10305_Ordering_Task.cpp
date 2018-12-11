/*/////////////////////////////////////////////////////////////////////

Carlos Placencia : Ordering Task : 10305 : Galactic_Banana

Data structure required : vector

Tricks of the trade : Use Topological sort algorithm ( DBS modified)
					  Algorithm found in the book

*/////////////////////////////////////////////////////////////////////

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> Graph(101); // So we can have our index from 1 to n
vector<int> ts; // Used to store top sort in reverse order
vector<int> dfs_num;

void dfs2(int u);

int main()
{
	ios_base::sync_with_stdio(false); //Speed!!
	cin.tie(nullptr);


	int n = 0, m = 0; // n = Number of task | m = relationship between the task
	int from = 0, to = 0;
	int counter = 1;

	cin >> n >> m;
	while ((n + m) != 0) {

		/* Loading the graph */
		for (int i = 0; i < m; i++) {
			cin >> from >> to;
			Graph[from].push_back(to);
		}

		dfs_num.assign((n + 1), -1); // -1 = UNVISITED | 1 = VISITED
		for (int i = 1; i < (n+1); i++){
			if (dfs_num[i] == -1) dfs2(i);
		}


		/* Read the data backwards */
		for (int i = (int)ts.size() - 1; i >= 0; i--) {
			if (ts.size() > counter) cout << ts[i] << " ";
			else cout << ts[i];
			counter++;
		}
		cout << "\n";

		ts.clear();
		dfs_num.clear();
		Graph.clear(); Graph.resize(101);
		counter = 1;
		
		cin >> n >> m;
	}
	return 0;
}

void dfs2(int u) {
	dfs_num[u] = 1;
	for (int j = 0; j < (int)Graph[u].size(); j++){
		int v = Graph[u][j];
		if (dfs_num[v] == -1) dfs2(v);
	}
	ts.push_back(u);
}