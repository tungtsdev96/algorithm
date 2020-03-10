#include<bits/stdc++.h>

using namespace std;

int n, m;
int *a;
int sum = 0, result = 0;
int indexCheck = -1;
int xopt[25];

void TRY(int k, int s);

int main() {
	
	cin >> n >> m;
	a = new int[n];
	
	for (int i = 0; i < n; i++){
		cin >> a[i];
		sum+= a[i];
	}
	
	sort(a, a + n);
	
	int x = (sum - m) / 2; 
	
	TRY(0, m);
	
	indexCheck = 0;
	while (indexCheck < n && a[indexCheck] <= x) {
//		cout  << indexCheck << endl;
		TRY(0, m + a[indexCheck]);
		indexCheck++;
		cout << "result " << result << endl;
	}
	
//	for (indexCheck = 0; indexCheck < n; indexCheck++) {
//		TRY(0, m + a[indexCheck]);
//	}
	
	
	cout << result;
	
}

void TRY(int k, int s) {
	int t;
	if (s >= a[k] && k != indexCheck) t = 1;
	else t = 0;
	
	for (int ucv = t; ucv >= 0; ucv--){
		xopt[k] = ucv;
		s-=a[k]*ucv;
		if (k == n - 1){
			if (s == 0) {
				result++;
				for (int i = 0; i < n; i++) {
					cout << xopt[i] << " ";
				}
				cout << endl;
			}
			return;
		} else {
			TRY(k+1, s);
		}
		s+=a[k]*ucv;	
	}
	
}

