#include<bits/stdc++.h>

using namespace std;

int main(){
	
	long long a, b, m;
	
	cin >> a >> b >> m;
	
	long long sum = 0;
	
//	while (b >= a){
//		long long number1 = (b - a + 1) * a * a;
//		sum = sum + number1 % m;
//		long long number2 = a * (b - a) * (b - a + 1);
//		sum = sum + number2 % m;	
//		b = b - a;
//		a = 1;
//	}
	
	int t = b - a;
	long long number1 = (t + 1) * a * a;
	sum = sum + number1 % m;
	long long number2 = a * t * (t + 1);
	sum = sum + number2 % m;
	
	long long number3 = t * (t + 1) * (2 * t + 1) / 6;
	sum = sum + number3 % m;
	
	cout << sum;
	return 0;
}

