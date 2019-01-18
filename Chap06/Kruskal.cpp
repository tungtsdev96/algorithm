#include<bits/stdc++.h>

using namespace std;

int n, m;
int *rank, *parent;

struct Edge {
	int u, v, w;
}; 

vector<Edge> edges;
vector<Edge> results;

int findParent(int u);
bool join(int u, int v);
bool compare(Edge &a, Edge &b);

int main() {
	
	cin >> n >> m;
	
	rank = new int[n + 1];
	parent = new int[n + 1];
	
	for (int i = 0; i < m; i++) {
		Edge e;
		cin >> e.u >> e.v >> e.w;
		if (e.u > e.v) swap(e.u, e.v);
		edges.push_back(e);
	}
	
	sort(edges.begin(), edges.end(), compare);
	
	// khoi tao disjoint set
	for (int u = 1; u <= n; u++) {
		rank[u] = 0;
		parent[u] = u;
	}
	
	int totalWeight = 0;
	
	for (int i = 0; i < edges.size(); i++) {
		Edge e = edges[i];
		
	//	cout << e.u << e.v  << e.w << endl;
		
		// hop nhat 2 cay chua u va v
        if (join(e.u, e.v)) {
        	//cout << "true " << e.u << e.v  << e.w << endl;
            // ok
            results.push_back(e);
            totalWeight += e.w;
        }
	}
	
	for (int i = 0; i < results.size(); i++) {
		cout << results[i].u << " " << results[i].v << " ";
	}
	
	cout << endl;
	cout << totalWeight;
	
	return 0;
}

int findParent(int u) {
	if (parent[u] != u) parent[u] = findParent(parent[u]);
	return parent[u];
}

bool join(int u, int v) {
	
	//cout << u << findParent(u) << v << findParent(v) << endl;
	
	u = findParent(u);
	v = findParent(v);
	
	
	if (u == v) return false;
	
	if (rank[u] == rank[v]) rank[u]++;
	
	if (rank[u] > rank[v]) parent[u] = v;
	else parent[v] = u;
	
//	for (int k = 1; k <= n; k++) cout << parent[k] << " ";
//	cout << endl;
	
	return true;
}

bool compare(Edge &a, Edge &b){
	return a.w < b.w;
}
