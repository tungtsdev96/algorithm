#include<bits/stdc++.h>

using namespace std;

int main(){
	
	while (true){
		
		long long n;
		cin >> n;
		
		if (n == 0) break;
		
		long long sum = 0;
		for (long long i = 0; i<=n; i++){
			sum += i * (n - i);
		}
		
		cout << sum % (1000000000 + 7);
		
	}
	
	
	
	return 0;
}
