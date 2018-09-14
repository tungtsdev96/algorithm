#include<iostream>

using namespace std;

void swap(double &a, double &b);

// basic
void insertionSort(int n, double *a);
void selectionSort(int n, double *a);
void bubbleSort(int n, double *a);

// Merge Sort
void mergeSort(double *a, int left, int right);
void merge(double *a, int left, int right, int mid);



int main() {

	int n;
	double *a;

	cin >> n;
	a = new double[n];
	
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	mergeSort(a, 0, n-1);

	for (int i = 0; i < n; i++) {
		cout << a[i] << endl;
	}

	system("pause");
	return 0;
}

void insertionSort(int n, double *a) {
	int k;
	for (int i = 2; i < n; i++) {
		k = i;
		int last = a[k];

		while (k < n && last < a[k - 1]) {
			a[k] = a[k - 1];
			k--;
		}

		a[k] = last;
	}
}

void selectionSort(int n, double *a) {
	for (int i = 0; i < n - 1; i++) {
		int min = i;
		for (int j = i + 1; j < n; j++) {
			min = a[min] > a[j] ? j : min;
		}
		swap(a[i], a[min]);
	}
}

void bubbleSort(int n, double *a) {
	bool swapped;
	do {

		swapped = false;
		for (int i = 0; i < n - 1; i++) {
			if (a[i] > a[i + 1]) {
				swap(a[i], a[i + 1]);
				swapped = true;
			}
		}

	} while (swapped);
}

void swap(double &a, double &b) {
	int temp = a;
	a = b;
	b = temp;
}

////////////////////////////////
// Merge sort
void mergeSort(double *a, int left, int right) {
	if (left < right) {
		int mid = (left + right) / 2;
		mergeSort(a, left, mid);
		mergeSort(a, mid + 1, right);
		merge(a, left, mid, right);
	}
}

void merge(double *a, int left, int mid, int right) {
	int i = left;
	int j = mid + 1;
	int k = 0;
	int n = right - left + 1;
	double *b = new double[n];

	for (int t = left; t < right + 1; t++) {
		if (i > mid) {
			b[k++] = a[j++];
			//j++; k++;
		}
		else if (j > right) {
			b[k++] = a[i++];
			//i++; k++;
		}
		else {
			if (a[i] < a[j]) {
				b[k++] = a[i++];
				//i++; k++;
			}
			else {
				b[k++] = a[j++];
				//j++; k++;
			}
		}
	}

	for (int k = 0; k < n; k++) {
		a[left++] = b[k];
	}
}

/////////////////////////////////
// Quick Sort

////////////////////////////////
// Heap Sort
