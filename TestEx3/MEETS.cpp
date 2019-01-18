#include<bits/stdc++.h>

using namespace std;

int n;
int countTime[1000006];
int result = 1;

int main() {

	cin >> n;
	
	for (int i = 0; i < 1000006; i++) {
		countTime[i] = 0;
	}
	
	for (int i = 0; i < n; i++) {
		int a,b;
		cin >> a >> b;
		for (int k = a + 1; k <= b; k++) {
			countTime[k] += 1;
			result = max(result, countTime[k]);
		}
	}
	
	
	cout << result << endl;

	
	return 0;
}

