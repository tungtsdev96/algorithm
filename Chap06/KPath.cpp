#include<bits/stdc++.h>

using namespace std;

int n, k ,m;
vector<int> *adj;
int *visited, *p;
int result = 0;
int d = 0;

void reset();
void DFS(int u);
int findRoot(int u);

int main() {
	
	freopen("KPath.inp", "r", stdin);
	freopen("KPath.out", "w", stdout);
	
	cin >> n >> k;
	cin >> m;
	
	adj = new vector<int>[n + 1];
	visited = new int[n + 1];
	p = new int[n + 1];
	
	for (int i = 0; i < m ; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	for (int u = 1; u <= n; u++) {
		reset();
		DFS(u);
	}
	
	cout << result / 2;
	
	return 0;
}

void reset() {
	d = 0;
	for (int i = 1; i <= n; i++) {
		visited[i] = -1;
		p[i] = i;
	}
}

void DFS(int u) {
	
	visited[u] = 1;
	if (d == k) {
		result++;
//		cout << "result : " << result << endl;
		return;
	}
	
//	cout << u << " : " << endl;
	
	for (int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i];
//		cout << v << endl;
		if (visited[v] != 1) {
			d++;
			visited[v] = 1;
			DFS(v);
			d--;
			visited[v] = -1;
		}
		
	}
		
}

int findRoot(int u) {
	if (p[u] != u) p[u] = findRoot(p[u]);
	return p[u];
}
