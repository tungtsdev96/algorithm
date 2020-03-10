#include<bits/stdc++.h>

using namespace std;

int n, k;
int a[100005];

int main() {
	
	double result = 0;
	
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	for (int i = 0; i <= n - k; i++) {
		double sum = 0;
		for (int j = i; j < n; j++) {
			sum += a[j];
			if (j - i + 1 >= k) {
				double t = sum / (j - i + 1);
				if (t > result) result = t;
			}
		}
	}
	
	printf("%.5f", result);
	
}
