#include<bits/stdc++.h>

using namespace std;

int h, w;
int a[200][200];
int result = 0;

int main() {
	
	int test;
	cin >> test;
	for (int t = 0; t < test; t++) {
		
		cin >> h >> w;
		
		for (int i = 1; i <= h; i++) {
			for (int j = 1; j <= w; j++) {
				cin >> a[i][j];
			}
		}
		
//		for (int i = 0; i <= h + 1; i++) {
//			a[i][0] = 0;
//			a[i][w + 1] = 0;
//		}
//		
//		for (int i = 0; i <= w + 1; i++) {
//			a[0][i] = 0;
//			
//		}
		
//		for (int i = 1; i <= h + 1; i++) {
//			for (int j = 1; j <= w + 1; j++) {
//				cout << a[i][j] < " ";
//			}
//			cout << endl;
//		}
		
		for (int i = 2; i <= h; i++) {
			for (int j = 1; j <= w; j++) {
				int left = 0; 
				int below = 0;
				int right = 0;
				
				if (j > 1) left = a[i - 1][j - 1];
				if (j < w) right = a[i - 1][j + 1];
				below = a[i - 1][j];
				
				int m = left;
				if(right > m) m = right;
				if(below > m) m = below;
				
				a[i][j] += m;
				result = max(result, a[i][j]);
			}
		}
		
		cout << result << endl;
	}
	
}
