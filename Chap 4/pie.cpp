#include<bits/stdc++.h>

using namespace std;

int n, f;
int a[10005];

int F(double s);

int main(){
	
	int test;
	cin >> test;
	for (int i = 0; i < test; i++){
		cin >> n;
		cin >> f;
		int max;
		for (int i = 0; i < n; i++){
			cin >> a[i];
			if (i == 0) max = a[i];
			else max = max < a[i] ? a[i] : max; 
		}
		
		double eps = 1e-6;
	
		double low = 0.0, high = M_PI * max * max;
		
		while (high - low > eps){
			double mid = (low + high) / 2.0;
			
			if (F(mid) > 0) {
				low = mid;
			} else {
				high = mid;
			}
		}		
		printf("%0.6f", low);
	}
	
	return 0;
}

int F(double s) {
	int count = 0;
	for (int i = 0; i < n ; i++) {
		count += a[i] * a[i] * M_PI / s;
	}
	
	if (count >= f + 1) {
		return 1;
	}
	return 0;
}
