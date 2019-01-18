#include<bits/stdc++.h>

using namespace std;

int MAX = 5001;
string s; 
int *F;
int result;

int main() {
	
	while (true) {
		cin >> s;
		
		if (s[0] == '0') break;	
		
		F = new int[s.length() + 1];
		F[0] = 1;
		F[1] = 1;
		
//		for(int i = 2 ; i <= s.length();i++)
//			F[i] = 0;
		
		// 110
		// 1110
		// 1001
		
		for (int i = 1; i < s.length(); i++) {  
			if(s[i] != '0' && s[i - 1] != '0' && s[i + 1] != '0' && (s[i] - '0') + (s[i - 1] - '0') * 10 <= 26)		
				F[i+1] = F[i] + F[i-1];
			else
				F[i+1] = F[i];
		}
		
		cout << F[s.length()] << endl;
	}
	
	return 0;
}

