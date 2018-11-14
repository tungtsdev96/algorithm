#include<bits/stdc++.h>

using namespace std;

int n, k1, k2;

int result = 0;
long long module = 1000000007;
long long F[1005][400];

long long Fk(int k, int L);

int main(){
	
	cin >> n >> k1 >> k2;
		
	for (int i = 0; i <= k2 ; i++){
		if (i == 0 || i >= k1) {
			F[n][i] = 1;
			continue;
		}
		F[n][i] = 0;
	}
	
	for (int i = n - 1; i >= 0; i--) {
		for (int L = k2; L >= 0; L--){
			if (L > i) continue;
			if (i == 0 || (k1 <= L && L <= k2)){
				F[i][L] =  F[i + 1][0] % module  + F[i + 1][L + 1] % module;	
			} else if (L >= k2) {
				F[i][L] = F[i + 1][0] % module;
			} else if (L < k1) {
				F[i][L] = F[i + 1][L + 1] % module;
			} 
			//cout << " i " << i << " L " << L << ": " << F[i][L] << endl;
		}
	}
		
	
	cout << F[0][0];
	return 0;
}

long long Fk(int k, int L) {
	if (k == n) {
		if (L == 0 || L >= k1) return 1;
		else return 0;
	} else if (k == 0 || (k1 <= L && L < k2)) {
		return Fk(k + 1, 0) % module  + Fk(k + 1, L + 1) % module;	
	} else if (L >= k2) {
		return Fk(k + 1, 0) % module;  
	} else {   // L < k1
		return Fk(k + 1, L + 1) % module;
	}
}
