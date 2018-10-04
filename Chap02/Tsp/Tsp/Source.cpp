#include<iostream>

using namespace std;

long fopt = 1000000000;
int f = 0;
int cmin = 1000000000;
int x[25];
int n, m;
int cost[25][25];
bool visited[25];

void TRY(int k);
void TRY(int i, int sum);

int main() {

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		visited[i] = false;
		for (int j = 1; j <= n; j++) {
			cost[i][j] = 0;
		}
	}

	for (int i = 0; i < m; i++) {
		int u, v, c;
		cin >> u >> v >> c;
		cost[u][v] = c;
		cmin = c < cmin ? c : cmin;
	}

	x[1] = 1;
	visited[1] = true;
	TRY(2, 0);
	cout << fopt;

	system("pause");
	return 0;
}

void TRY(int k) {
	for (int ucv = 2; ucv <= n; ucv++) {
		if (!visited[ucv] && cost[x[k - 1]][ucv] != -1) {
			x[k] = ucv;
			visited[ucv] = true;
			f = f + cost[x[k - 1]][ucv];
			if (k == n) {
				if ((f + cost[x[n]][1]) < fopt) {
					fopt = f + cost[x[n]][1];
				}
			}
			else {
				if (f + (n - k + 1)*cmin < fopt) {
					TRY(k + 1);
				}
			}
			visited[ucv] = false;
			f = f - cost[x[k - 1]][ucv];
		}
	}
}

void TRY(int i, int sum) {
	if (i == n + 1) {
		if (sum + cost[x[n]][1] < fopt) fopt = sum + cost[x[n]][1];
		return;
	}

	for (int j = 2; j <= n; j++) {
		if (!visited[j] && cost[x[i - 1]][j] != 0) {
			visited[j] = true;
			x[i] = j;
			if (sum + cost[x[i - 1]][j] + (n - i + 1)*cmin < fopt ) TRY(i + 1, sum + cost[x[i - 1]][j]);
			visited[j] = false;
			/*if (sum + cost[x[i - 1]][j] < fopt) {
				
			}*/
		}
	}
}