#include<bits/stdc++.h>

using namespace std;

int n, M;
int *a;

int main() {
//	cin >> n >> M;
	scanf("%d", &n);
	scanf("%d", &M);
	a = new int[n];
	
	for (int i = 0; i < n; i++) {
// 		cin >> a[i];
		scanf("%d", &a[i]);
	}
	
	int result = 0;
	
	for (int i = 0; i < n; i++) {
		int sum = 0;
		for (int j = i; j < n; j++) {
			sum += a[j];
			if (sum <= M) result++;
			else break;
		}
	}	
	
	printf("%d", result); 
		
	return 0;
}
