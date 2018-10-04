#include<bits/stdc++.h>

using namespace std;

int n;
int t[100001];

int eatliestDay();
void sort(int t[100001], int left, int right);
int partitionLeft(int t[100001], int left, int right);
void swap(int &a, int &b);

int main(){
	
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> t[i];
	}
	sort(t, 0, n -1);
	
	cout << eatliestDay();
	
	return 0;
}

int eatliestDay(){
	int sum = 0;
	for (int i = 0; i < n; i++){
		if (t[i] + i > sum) sum= t[i] + i;
	}
	return sum + 2;
}

void sort(int t[100001], int left, int right){
	if (left < right) {
		int index = (left + right) / 2;
		int pivot = partitionLeft(t, left, right);
		sort(t, left, pivot - 1);
		sort(t, pivot + 1, right);
	}
}

int partitionLeft(int t[100001], int left, int right) {
	int pivot = t[left];
	int i = left + 1;
	int j = right;

	while (i <= j) {
		while (pivot <= t[i]) i++;
		while (i == j || (i < j && pivot > t[j])) j--;
		if (i < j) swap(t[i++], t[j--]);
	}
	swap(t[left], t[j]);
	return j;
}

void swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}
