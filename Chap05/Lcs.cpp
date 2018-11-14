#include<bits/stdc++.h>

using namespace std;

int T;
int n, m;
string x, y;
int **s;

int max();

int main() {
	
	cin >> T;
	
	for (int i = 0; i < T; i++){
	    cin >> x >> y;
		n = x.length();
		m = y.length();
		s = new int*[n + 1];
		for (int j = 0; j <= n ; j++) {
			s[j] = new int[m + 1];
		}

		for (int k = 0; k <= n ; k++){
			s[k][0] = 0;
		}
		
		for (int k = 0; k <= m; k++){
			s[0][k] = 0;
		}
		
		for (int u = 1; u <= n; u++){
			for (int v = 1; v <= m ; v++) {
				if (x[u - 1] == y[v - 1]) {
					s[u][v] = s[u  - 1][v - 1] + 1;
				} else {
					if (s[u - 1][v] > s[u][v - 1]) {
						s[u][v] = s[u - 1][v];
					} else {
						s[u][v] = s[u][v - 1];
					}
				}
			}
		}
		
		cout << s[n][m] << endl;
				
	}
	
	return 0;
}

