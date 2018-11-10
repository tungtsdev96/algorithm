#include<iostream>

using namespace std;

int l1, l2;
int n;
int *a;

long maxsubseq();

int main() {


	cin >> n >> l1 >> l2;
	a = new int[n];

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	cout << maxsubseq();

	system("pause");
	return 0;
}



long maxsubseq() {
	int max = 0;

	for (int i = 0; i <= n - l2; i++) {
		int sum = 0;

		for (int k = i ; k < i + l1; k++) {
			sum += a[k];
		}

		for (int j = i + l1 ; j <= i + l2 - 1; j++) {
			sum += a[j];
			max = sum > max ? sum : max;
		}

	}

	return max;

}
