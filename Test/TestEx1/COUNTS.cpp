#include<bits/stdc++.h>

using namespace std;

int main(){
	
	int n, s , a[100005];
	
	int count;
	
	
	cin >> n >> s;
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	
	for (int i = 0; i < n ; i++){
		int sum = 0;
		for (int j = i; j < n ;j++) {
			sum+=a[j];
			count = ((sum * 1.0 / (j - i + 1)) <= s) ? count + 1 : count;
		}
	}
	
	cout << count;
	
	return 0;
}
