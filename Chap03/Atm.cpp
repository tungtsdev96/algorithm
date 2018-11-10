#include<bits/stdc++.h>

using namespace std;

int TestCase;
int countMoney = 0;  // dem so tien 
int countResult = 1; // dem so cach
int money[] = {1 , 2 , 3 , 5}; 
int baseCountMoney[] =  {1, 1, 1, 2, 1, 2, 2, 2, 3};
int baseCountResult[] = {1, 1, 1, 2, 1, 2, 1, 1, 3};

struct Test{
	int w;
	int c;
};
Test myTest[105]; 

void input(Test &myTest);
void result(Test &myTest);
int pow(int x, int n); // x^n

int main() {
	cin >> TestCase;
	for (int i = 0; i < TestCase; i++){
		countMoney = 0;
		countResult = 1;
		input(myTest[i]);
		if (myTest[i].w % 1000 != 0) {
			cout << 0 << " " << 0 << endl;
			continue;
		} 
		result(myTest[i]);
		cout << countMoney << " " << countResult << endl;
	}
}


void input(Test &myTest) {
	cin >> myTest.w;
	cin >> myTest.c;
}

int pow(int x, int n){
	int r = 1;
	for (int i = 1; i <= n; i++){
		r = r *x;
	}
	return r;
}

void result(Test &myTest){
	int w = myTest.w;
	int c = myTest.c;

	w = w / 1000;
	int p = pow(10, c + 1); // 10^(c + 1)
	int k = p /2;
	
	while (w >= p) {
		w -= p / 2;
		countMoney++;
	}
	
	while (w != 0) {
		int t = w % 10;
		if (t != 0) {
			countMoney += baseCountMoney[t - 1];
			countResult *= baseCountResult[t - 1];	
		}
		w = w / 10;
	}			
}
