#include<iostream>

using namespace std;

int m, n, k;
int *a;
int countAnswer = 0;
bool hasAnswer = false;

void TRY(int i);
void printResult();

int main() {
	cin >> n >> m >> k;
	a = new int[n];
	a[0] = 0;
	TRY(1);
	if (k > 0) cout << -1;
	system("pause");
	return 0;
}

void TRY(int i) {
	if (k == 0) return;
	for (int ucv = a[i - 1] + 1; ucv <= n - m + i; ucv++) {
		a[i] = ucv;
		if (i == m) {
			k--;
			if (k == 0) {
				printResult();
				return;
			}
		} else {
			TRY(i + 1);
		}
	}
}

void printResult() {
	for (int i = 1; i <= m; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}