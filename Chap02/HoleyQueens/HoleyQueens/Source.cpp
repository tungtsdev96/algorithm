#include<iostream>

using namespace std;

int n, m;
int *a;
int *hole; // dia chi hole
bool *r; // danh dau cot
bool *d1; // danh dau duong cheo 
bool *d2; // dang dau duong cheo
int countResult = 0;

void TRY(int i);
void displayResults();

int main() {

	
	while (true) {
		cin >> n >> m;
		if (n == 0 && m == 0) break;

		a = new int[n + 1];

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
		
		hole = new int[n + 1];
		for (int i = 1; i <= n; i++) {
			hole[i] = -1;
		}

		for (int i = 0; i < m; i++) {
			int x, y;
			cin >> x >> y;
			hole[x] = y;
		}

		TRY(1);
		cout << countResult;
		countResult = 0;
	}
	system("pause");
	return 0;
}

void TRY(int i) {
	//cout << hole[i] << endl;
	for (int v = 1; v <= n; v++) {
		if (hole[i] != v && r[v] && d1[i - v + n] && d2[i + v]) {
			a[i] = v;
			r[v] = false;
			d1[i - v + n] = false;
			d2[i + v] = false;
			if (i == n) {
				displayResults();
			}
			else {
				TRY(i + 1);
			}
			r[v] = true;
			d1[i - v + n] = true;
			d2[i + v] = true;
		}
	}
}

void displayResults() {
	countResult++;
	/*for (int i = 1; i <= n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;*/
}