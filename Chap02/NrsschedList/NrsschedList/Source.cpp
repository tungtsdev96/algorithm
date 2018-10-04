#include<iostream>

using namespace std;

int n, k1, k2;
int *a;
int countDay;

void TRY(int i, int countDay, int countZero);
void TRY(int i, int  L);
void printResult();

int main() {
	cin >> n >> k1 >> k2;
	a = new int[n];
	TRY(0, 0);
	system("pause");
	return 0;
}

void TRY(int i, int countDay, int countZero) {


	if (i == n) {
		// kiem tra truong hop so 0 nam o vtri ma sau do countDay < k1
		if (countDay == 0 || (countDay >= k1 && countDay <= k2))
		printResult();
		return;
	}
	
	// neu i = 0 hoac trc do k co so 0 va k1 =< countDay <= k2
 	if ((i == 0) || (countZero == 0 && countDay >= k1 && countDay <= k2)) {
		a[i] = 0;
		TRY(i + 1, 0, countZero + 1);	
	}
	
	// chi can countDay + 1 <= k2 thi a[i] co the bang 1
	if (countDay + 1 <= k2) {
		a[i] = 1;
		TRY(i + 1, countDay + 1, 0);
	}
}

void TRY(int i, int  L) {
	if (i == n) {
		if (L >= k1 || L == 0) printResult();
		return;
	}

	a[i] = 0;
	if (i == 0 || L >= k1) TRY(i + 1, 0);
	a[i] = 1;
	if (L < k2) TRY(i + 1, L + 1);
}

void printResult() {
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}