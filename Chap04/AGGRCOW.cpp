#include<bits/stdc++.h>

using namespace std;

int n, c;
int maxOfMin = -1;
int x[100005];

void sort(int left, int rigth);
bool checkValid(int s);

int main() {
	
	int t;
	cin >> t;
	for (int k = 0; k < t; k++){
		cin >> n >> c;
		for (int i = 0; i < n; i++){
			cin >> x[i];
		}	
		sort(0, n - 1);	
		
		int minLeft = 1;
		int minRight = x[n - 1] - x[0];
		
//		while (minLeft < minRight - 1) { 
//			
//			int mid = (minLeft + minRight) / 2;
//			
//			if (checkValid(mid)) minLeft = mid;
//			else minRight = mid - 1;
//		}
//		
//		maxOfMin = minRight;
//		
//		if (!checkValid(minRight)){
//			maxOfMin = minLeft;
//		}
//		
//		cout << maxOfMin << endl;
		
		while (minLeft <= minRight) {
			int mid = (minLeft + minRight) / 2;
			if (checkValid(mid)) {
				maxOfMin = mid;
				minLeft = mid + 1;
			} else {
				minRight = mid - 1;
			}
		}
		
		cout << maxOfMin << endl;
	}
	
	return 0;
}

bool checkValid(int s) {
	int pos = 0;
	int i = 1;
	int detal;
	int count = 1;
	
	while (i < n) {
		detal = x[i] - x[pos];
		
		if (detal >= s) {
			pos = i;
			count++;
		}	
		
		i++;
		if (count == c) return true;
	}
	
	return false;
}

void sort(int left, int right) {
	int pivot = x[(right + left) / 2];
	if (left <= right) {
		int i = left;
		int j = right;
		while (i <= j) {
			while(x[i] < pivot) i++;
			while(x[j] > pivot) j--;
			if (i <= j){
				swap(x[i], x[j]);
				i++;
				j--;
			}
			
			if (left < j) {
				sort(left, j);
			}
			
			if(right > i){
				sort(i, right);
			}
		}
	}
}
