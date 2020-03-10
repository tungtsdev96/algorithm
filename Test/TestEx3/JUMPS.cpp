#include<bits/stdc++.h>

using namespace std;

int n;
int result = 0;

int main() {
	
	int testCase;
	cin >> testCase;
	
	for (int t = 0; t < testCase; t++) {
		cin >> n;
		result = 0;
		int k = 2;
		while (k <= n) {
			result++;
			k = k * 2;
		}
				
		cout << result << endl;
		
	}
	
	return 0;
}
