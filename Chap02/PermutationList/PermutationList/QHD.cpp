#include<iostream>

using namespace std;

int n, k;
int *a, *visited;

void TRY(int i);
void displayResult();

int main() {
	cin >> n >> k;
	a = new int[n];
	visited = new int[n];

	for (int i = 1; i <= n; i++) {
		visited[i] = -1;
	}

	TRY(0);

	system("pause");
	return 0;
}

long long getFL(int n) {
	long f = 1;
	for (int l = n - 1; l >= 0; l--) {
		f = f * (n - l);
		if (f > k) {
			f = k + 1;
		}
	}
	return f;
}

void TRY(int i) {
	long long f = getFL(n - i - 1);
	for (int j = 1; j <= n; j++) {
		if (visited[j] < 0) {
			a[i] = j;
			visited[j] = 1;
			if (i == n - 1) {
				k--;
				displayResult();
			} else {
				TRY(i + 1);
			}
			visited[j] = -1;
		}
	}
}

void displayResult() {
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}