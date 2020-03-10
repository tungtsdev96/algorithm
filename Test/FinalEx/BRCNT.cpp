#include<bits/stdc++.h>

using namespace std;

long long di = 1e9 + 7;
long long a[100005];

int main() {
	int T;
	
	cin >> T;
	
	for (int t = 0; t < T; t++) {
		
		int n;
		cin >> n;
		
		if (n == 0) {
			cout << 0 << endl;
			continue;			
		}

		a[2] = 3; a[4] = 18;
		long long a2 = 9;
		
		for (int i = 6; i <= n; i = i + 2) {
			a2 = a2 * 3; // a2 ^ (i/2)   
			
			long long sum = 3 * a[i - 2];			
					
			int k = i / 2;
			for (int j = 2; j < k; j = j + 2) {
				sum = sum + 2 * a[j] * a[i - j] - a2;  
				sum = sum % di;
			}
			
//			if (k % 2 == 0) {
//				sum =sum + a[k] * a[k] - a2; 		
//				sum = sum % di;
//			} 
			
			a[i] = sum;
			
		}
		
		cout << a[n] % di << endl;
		
	}
	
}
