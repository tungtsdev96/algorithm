#include<bits/stdc++.h>
using namespace std;

int n, m, weigth[45];
int countResult = 0;
int xopt[45];

int BACKTRACK(int n);

int main(){
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> weigth[i];
	}
	
	BACKTRACK(1);
	cout << countResult;
	return 0;
}

int BACKTRACK(int k){
	int t;
	if (m >= weigth[k]) t = 1;
	else t = 0;
	
	for (int i = t; i >= 0; i--){
		xopt[k] = i;
		m = m - xopt[k] * weigth[k];
		if (k == n){
			countResult++;
		} else {
			BACKTRACK(k+1);
		}
		m = m + xopt[k] * weigth[k];	
	}
}

