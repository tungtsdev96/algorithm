#include<bits/stdc++.h>

using namespace std;

int n;
int **a;

int main() {
	
	cin >> n;
	
	a = new int*[n + 1];
	for (int i = 1; i <= n; i++) {
		a[i] = new int[n + 1];
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
		}
	}
	
	
	
	return 0;
}
