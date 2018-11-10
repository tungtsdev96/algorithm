//#include<iostream>
//
//using namespace std;
//
//int n, k;
//int *a, *visited;
//int countResult = 0;
//
//void TRY(int i);
//bool check();
//void displayResult();
//
//int main_test() {
//	cin >> n >> k;
//	a = new int[n];
//	visited = new int[n];
//	for (int i = 1; i <= n; i++) {
//		visited[i] = -1;
//	}
//	TRY(0);
//	system("pause");
//	return 0;
//}
//
//void TRY(int i) {
//	for (int j = 1; j <= n; j++) {
//		if (visited[j] < 0) {
//			a[i] = j;
//			visited[j] = 1;
//			if (i == n - 1) {
//				countResult++;
//				if (countResult == k) displayResult();
//			} else {
//				TRY(i + 1);
//			}
//			visited[j] = -1;
//		} 
//	}
//}
//
//void displayResult() {
//	for (int i = 0; i < n; i++) {
//		cout << a[i] << " ";
//	}
//	cout << endl;
//}