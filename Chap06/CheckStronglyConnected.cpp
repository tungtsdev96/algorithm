#include<bits/stdc++.h>

using namespace std;

int n,m,k;
vector<int> *adj, *adj_t;
bool *visited;
bool *visited_t;

void reset();
void DFS_CC(int u);
void DFS_CC_N(int u);
void checkStronglyConnected();

int main() {
	
	freopen("scc.inp", "r", stdin);
	freopen("scc.out", "w", stdout);
	
	cin >> n >> m >> k;
	
	adj = new vector<int>[n + 1];
	adj_t = new vector<int>[n + 1];
	visited = new bool[n + 1];
	visited_t = new bool[n + 1];
	reset();
	
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj_t[v].push_back(u);
	}
	
	// Kiem tra tinh lien thong manh cua mot do thi
	//checkStronglyConnected();
	
	return 0;
}

void reset(){
	for (int u = 1; u <= n; u++) {
		visited[u] = false;
		visited_t[u] = false;
	}
}

// Kiem tra tinh lien thong cua mot do thi
void checkStronglyConnected(){
	DFS_CC(1);
	for (int u = 1; u <= n; u++) {
		if (!visited[u]) {
			cout << "false";
			return;
		}
	}
	
	DFS_CC_N(1);
	for (int u = 1; u <= n; u++) {
		if (!visited_t[u]) {
			cout << "false";
			return;
		}
	}
	
	cout << "true";
}

void DFS_CC(int u) {
	visited[u] = true;
	for (int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i];
		if (!visited[v]) {
			DFS_CC(v);
		}
	}
}

void DFS_CC_N(int u) {
	visited_t[u] = true;
	for (int i = 0; i < adj_t[u].size(); i++) {
		int v = adj_t[u][i];
		if (!visited_t[v]) {
			DFS_CC_N(v);
		}
	}
}
