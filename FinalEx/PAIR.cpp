#include<bits/stdc++.h>

using namespace std;

int n, M;
int a[100005];

int main(){
	
	long long d = 1e9 + 7;
	long long cnt = 0;
	cin >> n >> M;
	
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[i] + a[j] <= M) {
				cnt++;
			}
		}
	}
	
	cout << cnt % d;
}
