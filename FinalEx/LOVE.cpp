#include<bits/stdc++.h>

using namespace std;

int n, m;
vector< pair<int, int> > *adj;
int visited[100005];
int d = 0;
int d1 = 0;
int result = 0;
vector<int> path;
int minTime = INT_MAX;

void love(int s);

int main() {
	
	freopen("Test.inp", "r", stdin);
 	freopen("Test.out", "w", stdout);
	
	cin >> n >> m;
	
	adj = new vector< pair<int, int> >[n + 1];
	
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back(make_pair(v, w));
		adj[v].push_back(make_pair(u, w));
	}
	
	for (int i = 1; i <= n; i++) {
		visited[i] = -1;
	}
	
	love(1);
	
	cout << minTime;
}

void love(int u) {
	
	visited[u] = 1;
	
	if (u == n) {
		int result = 0;
		for (int i = 0; i < path.size(); i++){
			if (result < path[i]) result = path[i];
		}
		if (minTime > result) minTime = result;
		return;
	}
	
	for (int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i].first;
		int w = adj[u][i].second;
		
		if (w > minTime) continue;
		
		if (visited[v] != 1) {	
			visited[v] = 1;
			path.push_back(w);
			love(v);
			path.pop_back();
			visited[v] = -1;
		}
		
	}
		
	
}
