#include<iostream>

using namespace std;

int n;
int *a;
bool *r; // danh dau cot
bool *d1; // danh dau duong cheo 
bool *d2; // dang dau duong cheo

void TRY(int i);
void displayResults();

int main() {
	cin >> n;
	a = new int[n];

	r = new bool[n + 1];
	for (int i = 1; i <= n; i++) {
		r[i] = true;
	}

	d1 = new bool[n + 1];
	for (int i = 1; i <= n; i++) {
		d1[i] = true;
	}

	d2 = new bool[n + 1];
	for (int i = 1; i <= n; i++) {
		d2[i] = true;
	}

	TRY(1);

	system("pause");
	return 0;
}

void TRY(int i) {
	for (int v = 1; v <= n; v++) {
		if (r[v] && d1[i - v + n] && d2[i + v]) {
			a[i] = v;
			r[v] = false;
			d1[i - v + n] = false;
			d2[i + v] = false;
			if (i == n) {
				displayResults();
			} else {
				TRY(i + 1);
			}
			r[v] = true;
			d1[i - v + n] = true;
			d2[i + v] = true;
		}
	}
}

void displayResults() {
	for (int i = 1; i <= n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}