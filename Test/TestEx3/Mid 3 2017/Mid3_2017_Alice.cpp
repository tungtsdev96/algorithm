#include<bits/stdc++.h>

using namespace std;

int n, m;
int *a;
int result = 0;

int main() {
	
	cin >> n >> m;
	a = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	for (int i = 0; i < n; i++) {
		int sum = 0;
		bool hasMin = false;
		for (int j = i; j < n; j++) {
		//	cout << " j " << j << " " << a[j]  << " "  << sum << endl;
			if (a[j] == m) {
				if (!hasMin) hasMin = true;
				else break;
			}
			sum += a[j];
			result = sum > result ? sum : result;
		}
	}
	
	cout << result;
	
	return 0;
}
