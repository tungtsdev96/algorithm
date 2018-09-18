#include<iostream>

using namespace std;

void swap(float &a, float &b);

// basic
void insertionSort(int n, float *a);
void selectionSort(int n, float *a);
void bubbleSort(int n, float *a);

// Merge Sort
void mergeSort(float *a, int left, int right);
void merge(float *a, int left, int right, int mid);

// Quick sort
void quickSort(float *a, int left, int right);
int partition(float *a, int left, int right, int indexPivot);
int partitionLeft(float *a, int left, int right);

int main() {

	int n;
	float *a;

	cin >> n;
	a = new float[n];
	
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	quickSort(a, 0, n-1);

	for (int i = 0; i < n; i++) {
		//cout << a[i] << endl;
		printf("%.2f ", a[i]);
	}

	system("pause");
	return 0;
}

void insertionSort(int n, float *a) {
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

void selectionSort(int n, float *a) {
	for (int i = 0; i < n - 1; i++) {
		int min = i;
		for (int j = i + 1; j < n; j++) {
			min = a[min] > a[j] ? j : min;
		}
		swap(a[i], a[min]);
	}
}

void bubbleSort(int n, float *a) {
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

void swap(float &a, float &b) {
	float temp = a;
	a = b;
	b = temp;
}

////////////////////////////////
// Merge sort
void mergeSort(float *a, int left, int right) {
	if (left < right) {
		int mid = (left + right) / 2;
		mergeSort(a, left, mid);
		mergeSort(a, mid + 1, right);
		merge(a, left, mid, right);
	}
}

void merge(float *a, int left, int mid, int right) {
	int i = left;
	int j = mid + 1;
	int k = 0;
	int n = right - left + 1;
	float *b = new float[n];

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
void quickSort(float *a, int left, int right) {
	if (left < right) {
		int index = (left + right) / 2;
		int pivot = partition(a, left, right, index);
		if (left < index) quickSort(a, left, pivot - 1);
		if (index < right) quickSort(a, pivot + 1, right);
	}
}

int partitionLeft(float *a, int left, int right) {
	float pivot = a[left];
	int i = left + 1;
	int j = right;

	while (i <= j) {
		while (pivot >= a[i]) i++;
		while (i == j || (i < j && pivot < a[j])) j--;
		if (i < j) swap(a[i++], a[j--]);
	}
	swap(a[left], a[j]);
	return j;
}

int partition(float *a, int left, int right, int indexPivot) {
	float pivot = a[indexPivot];
	swap(a[indexPivot], a[right]);
	int storeIndex = left;

	for (int i = left; i <= right - 1; i++) {
		if (a[i] < pivot) {
			swap(a[storeIndex], a[i]);
			storeIndex++;
		}
	}
	swap(a[storeIndex], a[right]);
	return storeIndex;
}

////////////////////////////////
// Heap Sort
