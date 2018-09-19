#include<iostream>

using namespace std;

int n, k, i;
int dem = 0;
int *a;
bool hasAnswer = false;

void TRY(int j);
void result();
bool check();
bool check(int *a, int size);

int main() {
	cin >> n >> k >> i;
	a = new int[n];
	TRY(0);
	if (!hasAnswer) cout << -1;
	system("pause");
	return 0;
}

//void TRY(int j) {
//	if (hasAnswer) return;
//	for (int v = 0; v <= 1; v++) {
//		a[j] = v;
//		if (j == n - 1) {
//			if (check()) {
//				dem++;
//				if (dem == k) {
//					result();
//					return;
//				}
//			}
//		} else {
//			TRY(j + 1);
//		}
//	}
//}

void TRY(int j) {
	if (hasAnswer) return;
	for (int v = 0; v <= 1; v++) {
		a[j] = v;	
		if ( j >= (i - 1) || j == n - 1) {
			if (!check(a, j)) continue;
			dem++; 
			result();
			if (dem == k) {
				hasAnswer = true; 
				
				return;
			}
		} else {
			TRY(j + 1);
		}
	}
}

void result() {
	for (int j = 0; j < n; j++) {
		cout << a[j] << " ";
	}
	cout << endl;
}

bool check() {
	int count = 0;
	for (int j = 0; j < n; j++) {
		if (a[j] == 0) {
			count++;
			if (count == i) return false;
		} else {
			if (j >= (n - i)) return true;
			count = 0;
		}
	}
	return true;
}

bool check(int *a, int last) {
	int sum = 0;
	for (int k = last; k > (last - i); k--) {
		sum += a[k];
		if (sum > 0) return true;
 	}
	return false;
}
