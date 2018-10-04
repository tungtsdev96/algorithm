#include<iostream>

using namespace std;

int n;
int b;
int a[35], cost[35];
int xopt[35];
int fopt = 0;
int f = 0;

void TRY(int k);
void sort();

int main() {

	cin >> n >> b;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> cost[i];
	}

	sort();
	
	TRY(1);
	cout << fopt;
	system("pause");
	return 0;
}

void sort() {
	for (int i = 1; i <= n - 1; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (1.0 * cost[i] / a[i] < 1.0 * cost[j] / a[j]) {
				swap(a[i], a[j]);
				swap(cost[i], cost[j]);
			}
		}
	}
}

void TRY(int k) {
	int t;
	if (b >= a[k]) t = 1;
	else t = 0;

	for (int ucv = t; ucv >= 0; ucv--) {
		xopt[k] = ucv;
		b = b - a[k] * xopt[k];
		f = f + cost[k] * xopt[k];
		if (k == n) {
			if (f > fopt) fopt = f;
		} else {
			if (f + 1.0 * b * cost[k + 1] / a[k + 1] > fopt) {
				TRY(k + 1);
			}
		}
		b = b + a[k] * xopt[k];
		f = f - cost[ucv] * xopt[k];
	}
}