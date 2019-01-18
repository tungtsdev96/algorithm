#include<bits/stdc++.h>

using namespace std;

int n;
int *visited, *d, *p;
vector< pair<int, int> > *edges;
queue<int> Q;
int result = 0;
int idMax;



void BFS(int u);
void reset();

int main() {
	
	int testCase;
	cin >> testCase;
	
	for (int t = 0; t < testCase; t++) {
		cin >> n;
		
		visited = new int[n + 1];
		d = new int[n + 1];
		p = new int[n + 1];
		edges = new vector< pair<int, int> >[n + 1];
		
		for (int i = 0; i < n - 1; i++) {
			int u, v, w;
			cin >> u >> v >> w;
			edges[u].push_back(make_pair(v, w));
			edges[v].push_back(make_pair(u, w));
		}
		
		BFS(1);
		
		//cout << idMax << " " << result << endl;
		
		BFS(idMax);
		
		//cout << idMax << " " << result;
		
		cout << result << endl;
		
	}
}

void reset() {
	result = 0;
	for (int i = 1; i <= n; i++) {
		visited[i] = -1;
		d[i] = 0;
		p[i] = i;
	}
}

void BFS(int s) {
	reset();
	
	visited[s] = 1;
	Q.push(s);
	
	while (!Q.empty()) {		
		int u = Q.front(); Q.pop();
		
	//	cout << u << endl;
				
		for (int i = 0; i < edges[u].size(); i++) {
			int v = edges[u][i].first;		
			
		//	cout << v << " ";
			
			if (visited[v] == -1) {
				d[v] = edges[u][i].second + d[u];
				visited[v] = 1;
				Q.push(v);
				
				if (result < d[v]) {
					result = d[v];
					idMax = v;
				}
			}
		}
		
		//cout << endl;
	}
	
}
