#include<bits/stdc++.h>

using namespace std;

int f, start, goal, u, d;
queue<int> Q;
int adj[2];
//int visited[1000005];
int *step;

void BFS(int u);

int main() {
	
	cin >> f >> start >> goal >> u >> d;
	adj[0] = u;
	adj[1] = -d;

	step = new int[f + 1];
	for (int i = 0; i <= f; i++) {
		step[i] = -1;
	}
	
	BFS(start);
	
	if (step[goal] != -1) cout << step[goal];
	else cout << "use the stairs";
	
	return 0;
}

void BFS(int start) {
	//visited[start] = 1;
	step[start] = 0;
	Q.push(start);
	
	while (!Q.empty()) {
		int u = Q.front();
		Q.pop();	
		if (u == goal) {
			return;
		}
		
		for (int i = 0; i <= 1; i++) {
			int v = u + adj[i];
			if ( v <= f && v >= 1 &&  step[v] == - 1) {
				//visited[v] = 1;
				step[v] = step[u] + 1;
				Q.push(v);
			}
		}	
	}
}
