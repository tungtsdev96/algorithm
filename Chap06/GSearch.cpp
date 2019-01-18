#include<bits/stdc++.h>

using namespace std;

const int WHITE = -1;
const int GRAY = 0;
const int BLACK = 1;
int n,m;
vector<int> *adj, *adj_cc;
int start, end;
int dfs_cc;
int minBFS;
bool checkDFS = false;
vector<int> pathDFS;
int minDFS;

struct Node {
	int color; 	// color
	int d;   	// distance
	int p;		// parent
};
Node *listNode;

void reset();
void BFS(int u);
void DFS(int u);
void DFS_CC(int u);

int main() {
    
    freopen("gsearch.inp", "r", stdin);
	freopen("gsearch.out", "w", stdout);
	
	cin >> n >> m;
	listNode = new Node[n + 1];
	adj = new vector<int>[n + 1];
	adj_cc = new vector<int>[n + 1];
	
	for (int i = 0; i < m ; i++) {
		int u,v;
		cin >> u >> v;
		adj[u].push_back(v);
		
		adj_cc[u].push_back(v);
		adj_cc[v].push_back(u);

	}
	
	cin >> start >> end;
	
	// count connected undirected
	reset();
	dfs_cc = 0;
	for (int u = 1; u <= n; u++) {
		if (listNode[u].color == WHITE) {
			dfs_cc++;
			DFS_CC(u);
		}
	}
	cout << dfs_cc << endl;
	
	// BFS 
	reset();
	minBFS = INT_MAX;
	BFS(start);
	cout << minBFS << endl;
	
	// sap xep danh sach ke moi dinh
	for (int u = 1; u <= n; u++) {
	    sort(adj[u].begin(), adj[u].end());
	}
	
//	for (int u = 1; u <= n; u++) {
//		for (int i = 0; i < adj[u].size(); i++) {
//			cout << adj[u][i] << " ";
//		}
//		cout << endl;
//	}
	
	// DFS 
	reset();
	minDFS = 0;
	DFS(start);
//	cout << pathDFS.size() << endl;
//	
//	for (int i = 0; i <pathDFS.size(); i++){
//		cout << pathDFS[i] << " ";
//	}
	
	return 0;
}

void reset() {
	for (int i = 1; i <= n; i++) {
		listNode[i].color = WHITE;
		listNode[i].p = -1;
	}
}

void BFS(int start) {
	queue<int> Q;
	listNode[start].color = GRAY;
	listNode[start].d = 1;
	Q.push(start);
	while (!Q.empty()) {
		int u = Q.front(); Q.pop();
		
		if (u == end) {
			minBFS = listNode[u].d < minBFS ? listNode[u].d : minBFS;
			return;
		}
			
		for (int i = 0; i < adj[u].size(); i++){
			int v = adj[u][i];
			if (listNode[v].color == WHITE) {		
				listNode[v].color = GRAY;
				listNode[v].d = listNode[u].d + 1;
				//listNode[v].p = u;
				Q.push(v);
			}
		}
		//listNode[u].color = BLACK;
	}
}

void DFS_CC(int u){
	listNode[u].color = GRAY;
	for (int i = 0; i < adj_cc[u].size(); i++){
		int v = adj_cc[u][i];
		if (listNode[v].color == WHITE) {
			//listNode[v].p = u;
			DFS_CC(v);
		}
	}
}

void DFS(int u) {
	pathDFS.push_back(u);
	listNode[u].color = GRAY;
	
	if (u == end) {
		// show result;
		cout << pathDFS.size() << endl;
		for (int i = 0; i <pathDFS.size(); i++){
			cout << pathDFS[i] << " ";
		}
		return;
	}
	
	for (int i = 0; i < adj[u].size(); i++){
		int v = adj[u][i];
		if (listNode[v].color == WHITE) {
			//listNode[v].p = u;
			DFS(v);
			pathDFS.pop_back();
		}
	}
		
}


