#include<bits/stdc++.h>

using namespace std;

int n, L1, L2;
int *a;
int **F;

int main() {
	
	cin >> n >> L1 >> L2;
	a = new int[n];
	
	F = new int*[n + 1];
	for (int j = 0; j <= n ; j++) {
		F[j] = new int[n + 1];
	}
	
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		//a[i] = i;
		F[i - 1][0] = 0;	
	}	
	
	int max = 0;
	
	for (int i = 1; i <= n; i++) {
		for (int L = 1; L <= L2 ; L++) {
			if (L > i) continue;
			F[i][L] = F[i - 1][L - 1] + a[i]; 
			cout << "i " << i << " L " << L << " " << F[i][L] << endl; 	
			if (L >= L1 && L <= L2) max = F[i][L] > max ? F[i][L] : max;
		}
		
	}
	
	cout << max;	
	return 0;
}
