#include<bits/stdc++.h>

using namespace std;

int n, m ,k;
vector<int> *adj;
int *w, *head;

int find(int u, int key);

int main() {
	
//	freopen("grep.inp", "r", stdin);
//	freopen("grep.out", "w", stdout);

	cin >> n >> m >> k;
	w = new int[k];
	adj = new vector<int>[n + 1];
	head = new int[n];
	
	for(int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
	}
	
	for (int i = 0; i < k; i++) {
		cin >> w[i];
	}
	
	cout << n << " " << m << endl; 
	
	// head
	head[1] = 1; cout << 1 << " ";	
	for (int u = 2; u <= n; u++) {
		head[u] = adj[u - 1].size() + head[u - 1];
		cout << head[u] << " ";
	}
	cout << endl;
	
	// dsach ke
	for (int u = 1; u <= n; u++) {
		int size = adj[u].size();
		if (size == 0) continue;
		sort(adj[u].begin(), adj[u].end());
		for (int i = 0; i < size; i++){
			cout << adj[u][i] << " ";
		}
	}
	cout << endl;
	
	// mang last
	for (int i = 0; i < k; i++) {
		int key = w[i];
		for (int u = 1; u <= n; u++) {
			if (u == key) continue;
			int result = find(u, key);
			if (result != -1) cout << result << " ";
		}
		cout << endl;
	}
	
    return 0;
}

int find(int u, int key){
	if (binary_search(adj[u].begin(), adj[u].end(), key)) return u;
	else return -1;
}
