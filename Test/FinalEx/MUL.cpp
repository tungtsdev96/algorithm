#include<bits/stdc++.h>

using namespace std;

int main() {
	
	int n;
	unsigned long long a[100005];
	unsigned long long s = 1;
	unsigned long long d = 1e9 + 7;
	
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		s = s*a[i];
		s = s % d;
	}
	
	cout << (s % d);
}
