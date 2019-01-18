#include<bits/stdc++.h>

using namespace std;

int n, m;
int *visited, *cost, *numberCity, *parent, *d;			// cost: chi phi, numberCity: so thanh pho di qua dc
vector< pair<int, int> > *adj;					// danh dau dinh ke do thi ban dau
queue<int> Q;						// duyet do thi dau

vector< pair<int, int> > *newAdj;	// danh dau dinh ke do thi sau bien doi
priority_queue<pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > pQ; // pair<d[s],s>

int start = -1; // dinh dau khi dfs
long result = LONG_MAX;

void reset();
void DFS(int u);
void Dijkstra(int start);

int main() {
	
	freopen("ICBus.inp", "r", stdin);
	freopen("ICBus.out", "w", stdout);
	
	cin >> n >> m;
	adj = new vector< pair<int, int> >[n + 1];
	newAdj = new vector< pair<int, int> >[n + 1];
	visited = new int[n + 1];
	parent = new int[n + 1];
	d = new int[n + 1];
	cost = new int[n + 1];
	numberCity = new int[n + 1];
	
	for (int u = 1; u <= n; u++) {
		cin >> cost[u] >> numberCity[u];
	}
	
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(make_pair(v, cost[u]));
		adj[v].push_back(make_pair(u, cost[v]));
		newAdj[u].push_back(make_pair(v, cost[u]));
		newAdj[v].push_back(make_pair(u, cost[v]));
	}
	
	for (int u = 1; u <= n; u++) {
		reset();
		start = u;
		DFS(u);
	}
	

//	for (int u = 1; u <= n; u++) {
//		cout << u << " : " << endl;
//		for (int i = 0; i < newAdj[u].size(); i++) {
//			cout << newAdj[u][i].first << " " << newAdj[u][i].second << endl;
//		}
//		cout << endl;
//	}
	
	reset();
	Dijkstra(1);
	
	cout << result;
	
	return 0;
	
}


void reset() {
	for (int i = 1; i <= n; i++) {
		visited[i] = -1;
		parent[i] = i;
		d[i] = INT_MAX;
	}
}

void DFS(int s) {
	
	visited[s] = 1;
	
	if (numberCity[start] == 0) {
		// chi phi tu start -> s
		newAdj[start].push_back(make_pair(s, cost[start]));
		return;
	}
	
	for (int i = 0; i < adj[s].size(); i++) {
		int v = adj[s][i].first;
		int w = adj[s][i].second;
		
		if (visited[v] == -1) {
//			visited[v] = 1;
//			parent[v] = s;
			numberCity[start]--;
			
			DFS(v);
			
			numberCity[start]++;
		}
		
	}
	
}

void Dijkstra(int s) {
	
	d[s] = 0;
	
	pQ.push(make_pair(d[s], s));
	
	while (!pQ.empty()) {
		
		int u = pQ.top().second;
		visited[u] = 1;
		pQ.pop();
		
//		cout << u << ": ";
		
		for (int i = 0; i < newAdj[u].size(); i++) {
			int v = newAdj[u][i].first;
			int w = newAdj[u][i].second;
//			cout << v << " " << w << " ; ";
			if (visited[v] == -1) {
				
				if (d[u] + w < d[v]) {
					d[v] = d[u] + w;
					parent[v] = u;
					pQ.push(make_pair(d[v], v)); 
					
					if (v == n) {
						if (result > d[v]) result = d[v];
					}
				}
			}
			
		}
	}
	
}




