#include<bits/stdc++.h>

using namespace std;

int l, k ,m;
int *coins;
int F[1000005]; //  Goi F[i] kiem tra xem lúc trò choi còn i dong là thang hay thua.
		// F[0] = 0 => con 0 dong thi ng choi luot do thua

int main() {
	
	cin >> k >> l >> m;
	
	coins = new int[m];
	
	for (int i = 0; i < m; i++) {
		cin >> coins[i];
	}
	
	for (int i = 0; i < 1000005; i++) F[i] = 0;
	
	for (int i = 0; i < m; i++) {
		int coin = coins[i];
		
		for (int c = 1; c <= coin; c++) {
			if (c - 1 >= 0 && F[c - 1] == 0) F[c] = 1;
			if (c - l >= 0 && F[c - l] == 0) F[c] = 1;
			if (c - k >= 0 && F[c - k] == 0) F[c] = 1;
		}
		
		cout << (F[coin] == 1 ? "A" : "B");
		
	}
	
	return 0;
}

