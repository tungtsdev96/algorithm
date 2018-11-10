//#include<iostream>
//
//using namespace std;
//
//// O(n3)
//long subseqmax1(int a[], int n);
//
//// O(n2)
//long subseqmax2(int a[], int n);
//
//// Divide and Conquer
//long subseqmax3(int a[], int left, int right);
//long maxLeft(int a[], int left, int right);
//long maxRight(int a[], int left, int right);
//
//int main() {
//	int n;
//	int *a;
//	
//	cin >> n;
//	a = new int[n];
//
//	for (int i = 0; i < n; i++) {
//		cin >> a[i];
//	}
//	
//	cout << subseqmax3(a, 0, n - 1);
//
//	system("pause");
//	return 0;
//}
//
//// O(n3)
//long subseqmax1(int a[], int n) {
//	int max = a[0];
//	for (int i = 0; i < n - 1; i++) {
//		for (int j = i; j < n; j++) {
//			int sum = 0;
//			for (int k = i; k <= j; k++) {
//				sum += a[k];
//			}
//			max = max < sum ? sum : max;
//		}
//	}
//	return max;
//}
//
//// O(n2)
//long subseqmax2(int a[], int n) {
//	int max = a[0];
//	for (int i = 0; i < n; i++) {
//		int sum = 0;
//		for (int j = i; j < n; j++) {
//			sum += a[j];
//			max = max < sum ? sum : max;
//		}
//	}	
//	return max;
//}
//
//// O(nlogn)
//long subseqmax3(int a[], int left, int right) {
//	
//	long max;
//
//	max = a[left];
//	if (left < right) {
//		int mid = (right + left) / 2;
//		long maxL = subseqmax3(a, left, mid);
//		long maxR = subseqmax3(a, mid + 1, right);
//		
//		long mLeft = maxLeft(a, left, mid);
//		long mRight = maxRight(a, mid + 1, right);
//		long mLR = mLeft + mRight;
//		max = maxL > maxR ? maxL : maxR;
//		max = max < mLR ? mLR : max;
//	}
//	
//	return max;
//}
//
//long maxLeft(int a[], int left, int right) {
//	long maxL = a[right];
//	long sum = 0;
//	for (int i = right; i >= left; i--) {
//		sum += a[i];
//		maxL = maxL < sum ? sum : maxL;
//	}
//
//	return maxL;
//}
//
//long maxRight(int a[], int left, int right) {
//	long maxR = a[left];
//	long sum = 0;
//	for (int i = left; i <= right; i++) {
//		sum += a[i];
//		maxR = maxR < sum ? sum : maxR;
//	}
//	return maxR;
//}
//
