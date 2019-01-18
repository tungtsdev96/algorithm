#include<bits/stdc++.h>

using namespace std;

int n, r;
int a[101][101];
bool check[101];
int result = 0;
vector<int> *data;


int main() {
	
	freopen("Rounting.inp", "r", stdin);
	freopen("Rounting.out", "w", stdout);
	
	cin >> n >> r;
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
		}
	}
	
	data = new vector<int>[r + 1];
	for (int i = 0; i < r; i++) {
		
	}
	
	
	return 0;
}
