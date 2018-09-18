#include<iostream>

using namespace std;

void swap(float &x, float &y);

int main() {

	
	int n; cin >> n;
	float * a = new float[n];

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int gap = n;
	bool sorted = false;

	while ((gap > 1) || !sorted) {
		gap = floor(gap / 1.3);
		if (gap < 1) gap = 1;

		int i = 0;
		if (gap == 1) sorted = true;
		while (i + gap < n) {
			if (a[i] > a[i + gap]) {
				swap(a[i], a[i + gap]);
				if (gap == 1) sorted = false;
			}
			i++;
		}
	}

	for (int i = 0; i < n; i++) {
		printf("%.2f ", a[i]);
	}

	system("pause");
	return 0;
}

void swap(float &x, float &y) {
	float temp = x;
	x = y;
	y = temp;
}
