#include<iostream>

using namespace std;

int n, k, i;
int dem = 0;
int *a;
bool hasAnswer = false;
int countZezo = 0;

void TRY(int j);
void result();
bool check(int j);

int main() {
	cin >> n >> k >> i;
	a = new int[n];
	TRY(0);
	if (!hasAnswer) cout << -1;
	system("pause");
	return 0;
}

void TRY(int j) {
	if (hasAnswer) return;
	for (int v = 0; v <= 1; v++) {
		a[j] = v;
		if (check(j)) {
			if (j == n - 1) {
				dem++;
				if (dem == k) {
					result();
					return;
				}
			} else {
				TRY(j + 1);
			}
			// sau khi xong thi phai gan countZezo = 0
			countZezo = 0;
		}
	}
}

// kiem tra so luong so 0 lien tiep
bool check(int j) {
	if (a[j] == 0) countZezo++;
	if (countZezo == i) {
		countZezo = 0;
		return false;
	}
	return true;
}

void result() {
	hasAnswer = true;
	for (int j = 0; j < n; j++) {
		cout << a[j] << " ";
	}
	cout << endl;
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
//		}
//		else {
//			TRY(j + 1);
//		}
//	}
//}


//bool check() {
//	int count = 0;
//	for (int j = 0; j < n; j++) {
//		if (a[j] == 0) {
//			count++;
//			if (count == i) return false;
//		} else {
//			if (j >= (n - i)) return true;
//			count = 0;
//		}
//	}
//	return true;
//}
//
