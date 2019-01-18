#include<bits/stdc++.h>

using namespace std;

int n, m;
int *visited, *d; 
vector<int> edges[20005];
queue<int> Q;
int result = 0;

void BFS(int s);
void reset();

int main() {
	
	cin >> n >> m;
		
	visited = new int[n + 1];
	d = new int[n + 1];
	
	for (int t = 0; t < m; t++) {
		int u, v;
		cin >> u >> v;
		edges[u].push_back(v);
		edges[v].push_back(u); 
	}
	
	for (int s = 1; s <= n; s++) {
		BFS(s);
	} 
	
	cout << result << endl;
	
	return 0;
}

void reset() {
	for (int u = 1; u <= n; u++) {
		visited[u] = -1;
		d[u] = 0;
	}
}

void BFS(int s) {
	reset();
	
	d[s] = 0;
	visited[s] = 1;
	Q.push(s);
	
	while (!Q.empty()) {		

		int u = Q.front(); Q.pop();
		
		for (int i = 0; i < edges[u].size(); i++) {
			int v = edges[u][i];		
			if (visited[v] == -1) {
				visited[v] = 1;
				d[v] = d[u] + 1;
				Q.push(v);
				
				if (result < d[v]) {
					result = d[v];
				}
			}	
		}	
	}
	
}
