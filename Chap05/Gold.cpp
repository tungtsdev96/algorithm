#include<bits/stdc++.h>

using namespace std;

int n, L1, L2;
long long a[1000005], L[1000005], result = 0;

int main(){

	cin >> n >> L1 >> L2;
	
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
		
	result = 0;
	for (int i = 1; i <= n; i++) {
		L[i] = a[i];			
		for (int j = i - L1;j >= i - L2 && j > 0; j--) {
			if (L[j] + a[i] > L[i]) L[i] = L[j] + a[i]; 
		}
		result = L[i] > result ? L[i] : result;
	}
		
	cout << result << endl;
	
		
	return 0;
}

