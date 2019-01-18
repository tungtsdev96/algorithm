#include<bits/stdc++.h>

using namespace std;

int n,m,k;
vector<int> *adj;
stack<int> st;
bool *visited; // xac dinh v co trong thanh phan lien thong hay k
int index;
int result = 0;
int *num; // thoi gian tham nut u DFS 
int *low; //  là num min trong nhung dinh ma u co the di den

void reset();
void DFS_CC(int u);

int main() {
	
	freopen("scc.inp", "r", stdin);
	freopen("scc.out", "w", stdout);
	
	cin >> n >> m >> k;
	
	adj = new vector<int>[n + 1];
	num = new int[n + 1];
	low = new int[n + 1];
	visited = new bool[n + 1];
	reset();
	
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
	}
	
	for (int u = 1; u <= n; u++) {
		if (num[u] == -1) DFS_CC(u);
	}
	
	cout << result << endl;
	
	for (int i = 0; i < k; i++) {
		reset();
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		
		for (int u = 1; u <= n; u++) {
			if (num[u] == -1) DFS_CC(u);
		}
		cout << result << endl;
	}
	
	return 0;
}

void reset(){
	index = 0;
	result = 0;
	for (int u = 1; u <= n; u++) {
		visited[u] = false;
		num[u] = -1;
		low[u] = -1;
	}
}

void DFS_CC(int u) {
	num[u] = ++index;
	low[u] = num[u];
	//cout << "visted u: " << u << " low " << low[u] << " num " << num[u] << endl;
	visited[u] = true;
	st.push(u);
	
	for (int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i];
		if (num[v] == -1) DFS_CC(v);
		if (visited[v]) low[u] = min(low[u], low[v]);
		//cout << u << " low " << low[u] << " num " << num[u] << endl;
	}
	
	if (low[u] == num[u]) {
		result++;
		int v;
        do {
        	// lay ra cac dinh trong thanh phan lien thong
            v=st.top(); st.pop();
            visited[v] = false;
        } while (v != u);
	}
	
}
