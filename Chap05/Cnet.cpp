//#include<bits/stdc++.h>
//
//using namespace std;
//
//int n, k, G;
//int c[10005][10005];
//int father[10005];
//
//int main() {
//	
//	cin >> n >> k >> G;
//	
//	for (int i = 1; i <= n; i++) {
//		father[i] = -1;
//		for (int j = 1; j <= n; j++) {
//			c[i][j] = -1;
//		}
//	}
//	
//	for (int i = 1; i <= G; i++) {
//		int u, v, cost;
//		cin >> u >> v >> cost;
//		c[u][v] = cost;
//		c[v][u] = cost;
//	}
//	
//	int f = 0;
//	int count = 0;
//	int j = 1;
//	while (j <= n) {
//		
//		int min = 2e9;
//		int index = -1;
//		for (int i = 1; i <= n; i++) {
//			if (father[i] != j && c[i][j] != -1) {
//				if (c[i][j] < min) {
//					min = c[i][j];
//					index = i;	
//				}
//			}
//		}
//		
//		if (index == -1) {
//			j++;
//			count = 0;	
//		} else {
//			f += min;
//			j = index;
//			father[j] = index;
//			count++;
//			if (count == k - 1) {
//				break;
//			}
//		}
//		
//	}
//	
//	cout << f;
//	
//}


