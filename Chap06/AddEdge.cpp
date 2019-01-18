#include<bits/stdc++.h>

/*
	Dinh chieu do thi (trong qua trinh duyet DFS cu duyet qua u -> v thi bo qua v -> u)
	rank[u] : so thu tu duyet dinh u
	num[u]: la rank nho nhat trong tap cac dinh ma u den
	
	low[v] > rank[u] thi u -> v la cau
	low[v] >= rank[u] thi u la khop
	 
	1, tim cau
		neu chua duyet v 
			dinh chieu u -> v 
			low[v] > rank[u] thi u -> v la cau
			cuc tieu hoa low[u] = min(low[u], low[v])
		nguoc lai
			cuc tieu hoa low[u] = min(low[u], rank[v])
	2, tinh so tplt cua cac do thi
		sum = C(2,k) - (k - 1)
*/

using namespace std;

int n, m;
int *visited, *p;
int *rank; // thu tu duyet dinh
int *low; // min rank trong tap nhung dinh ma u co the di dem 
int deep = 0;  // do sau 
int countVertice = 0; // dem so dinh trong TPLT cua dthi moi
int result = 0;
vector<int> *adj;
vector<int> *newAdj;
vector< pair<int, int> > bridges;  // danh sach cau

void reset();
void DFS(int u, int p);  
void DFS_CC(int u);

int main() {
	
	freopen("AddEdge.inp", "r", stdin);
	freopen("AddEdge.out", "w", stdout);
	
	cin >> n >> m;
	
	visited = new int[n + 1];
	p = new int[n + 1];
	low = new int[n + 1];
	rank = new int[n + 1];
	adj = new vector<int>[n + 1];	
	newAdj = new vector<int>[n + 1];
	
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	reset();
	for (int u = 1; u <= n; u++) {
		if (rank[u] == -1) {
			DFS(u, u);	
		}
	}
	
	for (int u = 1; u <= n; u++) {
		if (visited[u] == -1) {
			countVertice = 0;
			DFS_CC(u);	
			if (countVertice > 2) result += (countVertice - 1) * (countVertice - 2) / 2; 
		}
	}
	
	cout << result;
	
//	for (int u = 1; u <= n; u++) {
//		cout << u << ": " << rank[u] << " " << low[u] << endl;
//	}
	
//	for (int i = 0; i < bridges.size(); i++) {
//		cout << bridges[i].first << " " << bridges[i].second << endl;
//	}
	
}

void reset() {
	for (int u = 1; u <= n; u++) {
		visited[u] = -1;
		p[u] = u;
		low[u] = -1;
		rank[u] = -1;
	}
}

void DFS(int u, int p) {
	rank[u] = ++deep;
	low[u] = rank[u];
	
	for (int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i];
		
		if (rank[v] == -1) {
				
			DFS(v, u); // khong duyet u khi dfs v 
			
			if (low[v] > rank[u]) {
					
				// tim dc canh cau
				cout << "result "<< u << " -> " << v << endl;
				newAdj[u].push_back(v);
				newAdj[v].push_back(u);
			}
				
			low[u] = min(low[u], low[v]);	
				
		} else if (v != p) {
				
			low[u] = min(low[u], rank[v]);
				
		}
		
	}
	
	
}

void DFS_CC(int u) {
	
	visited[u] = 1;
	countVertice++;
	
	for (int i = 0; i < newAdj[u].size(); i++) {
		int v = newAdj[u][i];
		if (visited[v] == -1) DFS_CC(v);
	}
	
}


