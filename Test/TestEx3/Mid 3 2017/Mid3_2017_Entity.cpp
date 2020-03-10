#include<bits/stdc++.h>

using namespace std;

int n, m;
vector<int> *adj;
int *visited;

void DFS(int u);

int main() {
	
	cin >> n >> m;
	
	adj = new vector<int>[n];
	visited = new int[n + 1];
	
	for (int i = 1; i <= n; i++){
		visited[i] = -1;
	}
	
	for (int i = 1; i <= m ; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
	}
	
	return 0;
}

void DFS(int u) {
	
	visited[u] = 1;
	
	for (int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i];
		if (!visited[v]) DFS(v);
	}
	
}


