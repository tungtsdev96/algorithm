#include<bits/stdc++.h>

using namespace std;

int n, m;
int sum;
int result = -1;
int a[1000005];

//void sort(int left, int right);
bool isValid(int s);

int main() {
	
	cin >> n >> m;
	
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(&a[0], &a[n - 1]);
		
	int left = 1;
	int right = a[n - 1] - 1;
		
	while (left <= right) {
		int mid = (right + left) / 2;
	//	cout << "left " << left << " right " << right << " ";
	//	cout << "mid " << mid << " ";
			
		if (isValid(mid)) {
			result = mid;
			left = mid + 1;
		} else {
			right = mid - 1;
		}
	}
	
	cout << result;
	
	return 0;
}

bool isValid(int s) {
	
	long long sum = 0;
	for (int i = 0; i < n; i++){
		long long detal = a[i] - s;
		sum = detal > 0 ? sum + detal : 0;
	}
//	cout << "sum " << sum << endl;
	return sum >= m;
}

//void sort(int left, int right) {
//	int pivot = a[(right + left) / 2];
//	if (left <= right) {
//		int i = left;
//		int j = right;
//		while (i <= j) {
//			while(a[i] < pivot) i++;
//			while(a[j] > pivot) j--;
//			if (i <= j){
//				swap(a[i], a[j]);
//				i++;
//				j--;
//			}
//			
//			if (left < j) {
//				sort(left, j);
//			}
//			
//			if(right > i){
//				sort(i, right);
//			}
//		}
//	}
//}
