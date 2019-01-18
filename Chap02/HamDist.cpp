#include<bits/stdc++.h>

using namespace std;

int n, h;
int *a;

void TRY(int k, int L);
void result();

int main(){
	
	int test;
	cin >> test;
	
	for (int i = 0; i < test; i++) {
		cin >> n >> h;
		a = new int[n];
		TRY(0, 0);
		cout << endl;
	}
	
	return 0;
}

void TRY(int k, int L){
	
	if (k == n) {
		if (L == h) result();
		return;
	}
	
	a[k] = 0;
	TRY(k + 1, L);
	if (L <= h) {
		a[k] = 1;	
		TRY(k + 1, L + 1);
	}
}

void result(){
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}
