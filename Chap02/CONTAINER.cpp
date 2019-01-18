#include<bits/stdc++.h>

using namespace std;

int h, w, n;
int *blockWidth, *blockHeight;

void TRY(int k, int x, int y); // (index, x, y)

int main() {
	
	freopen("Container.inp", "r", stdin);
	freopen("Container.out", "w", stdout);
	
	cin >> h >> w >> n;
	
	blockHeight = new int[n];
	blockWidth = new int[n];
	
	for (int i = 0; i < n; i++) {
		cin >>  blockHeight[i] >> blockWidth[i];
	}
	
	TRY(0, 0, 0);
			
	return 0;
}

void TRY(int k, int x, int y) {
	
	if (k == n - 1) {
		if (x + blockHeight[k] == h && y + blockWidth[k] == w) cout << "Done " << endl;
		return;	
	}
	if (x + blockHeight[k] <= h) TRY(k + 1, x + blockHeight[k], y);
	if (y + blockWidth[k] <= w) TRY(k + 1, x, y + blockWidth[k]);
}
