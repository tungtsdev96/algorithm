/*
	Minpath
*/

#include<bits/stdc++.h>

using namespace std;

int n, m;
vector< pair<long long, int> > *adj;
int *mark, *parent; 
long long *d;

//priority_queue<pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > Q; // pair<d[s],s>
struct cmp{
    bool operator() (pair<int, int> a,pair<int, int> b) {return a.first > b.first;}
};
priority_queue<pair<long long, int>, vector< pair<int, int> >, cmp > Q; // pair<d[s],s>

void Dijkstra(int start);
void reset();

int start, end;
long long result = LLONG_MAX;


int main() { 
	
   	freopen("MinPath.inp", "r", stdin);
   	freopen("MinPath.out", "w", stdout);
	
	cin >> n >> m;	
	
	mark = new int[n + 1];
	d = new long long[n + 1];
	parent = new int[n + 1];	
	adj = new vector< pair<long long, int> >[m + 1];
	
	for (int i = 0; i < m ; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back(make_pair(v, w));
	}

	cin >> start >> end;
	reset();
	
	Dijkstra(start);
	
	cout << result << endl;
	
	stack<int> path;
	int p = end; 
	path.push(end);
	while (p != start) {
		p = parent[p];
		path.push(p);
	}
	
	while(!path.empty()){
		cout << path.top() << " ";
		path.pop();
	}
	
	return 0;
}

void reset(){
	for (int u = 1; u <= n; u++) {
		mark[u] = -1;
		d[u] = INT_MAX;
		parent[u] = u;
	}
	
}

void Dijkstra(int start) {
	
	d[start] = 0;
	Q.push(make_pair(d[start], start));
	
	while(!Q.empty()) {
		
		int u = Q.top().second;
		mark[u] = 1;
		Q.pop();
			
		for (int i = 0; i < adj[u].size(); i++) {
			int v = adj[u][i].first;
			long long w = adj[u][i].second;
			
			if (mark[v] == -1) {
				//mark[v] = 1; 
				if (d[v] > d[u] + w) {
					d[v] = d[u] + w;
					parent[v] = u;
					Q.push(make_pair(d[v], v)); 
					
					if (v == end) {
						result = result > d[v] ? d[v] : result;
//						return;	
					}
				}		
			}
		}
			
	}
}
