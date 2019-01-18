#include<bits/stdc++.h>

using namespace std;

int n;
long long di = 1e9 + 7;
int a[100005];
long long result;

void TRY(int k);
int check();

int main() {
	
	int T;
	
	cin >> T;
	
	for (int t = 0; t < T; t++) {
		
		cin >> n;

		if (n == 0) {
			cout << 0 << endl;
			continue;			
		}
		
		result = 0;
		TRY(0);
		cout << result << endl;
	}
		
}

void TRY(int k) {
	
	if (k == n) {
		int c = check();
		if (c == 1) result++;
//		result = result * pow(3, (n / 2));
		result = result % di;
		return;
	}
	
	for (int ucv = 1; ucv <= 2; ucv++) {
		a[k] = ucv;
		TRY(k + 1);
	}	
}

int check() {
	stack<int> stk;
	for (int i = 0; i < n; i++) {	
		if (stk.empty()) stk.push(a[i]);
		else if (a[i] == 1 && stk.top() == 2) stk.pop();
		else stk.push(a[i]);
	}
	
	if (stk.empty()) return 1;
	return -1;
}


