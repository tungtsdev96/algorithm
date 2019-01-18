#include<bits/stdc++.h>

using namespace std;

int h, a;
int MAX[2005][2005]; // luu thoi gian max theo h, a;

int check(int h, int a);

int main() {
	
	int t;
	cin >> t;
	
	for (int i = 0; i < t; i++) {
		
		cin >> h >> a;
		
		for (int i = 0; i < 2005; i++) {
			for (int j = 0; j < 2005; j++) {
				MAX[i][j] = -1;
			}
		}
		
		cout << check(h, a) << endl;
	}
    return 0;
} 

int check(int h, int a) {
	if (h <= 0 || a <= 0) return -1;
	
	if (MAX[h][a] == -1) MAX[h][a] = max(check(h - 17, a + 7) + 2, check(h - 2, a - 8) + 2);
	
	return MAX[h][a];
}
