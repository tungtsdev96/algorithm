#include<iostream>

using namespace std;

int n;
int result = 0;
int moneyback;

void back(int money);

int main() {

	cin >> n;
	
	moneyback = 1000 - n;
	back(500);
	back(100);
	back(50);
	back(10);
	back(5);
	back(1);
	cout << result;
	return 0;
}

void back(int money){
	while (moneyback >= money) { 
		moneyback = moneyback - money;
		result++;
	}
}
