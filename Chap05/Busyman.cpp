#include<bits/stdc++.h>

using namespace std;

int n;
int *L;
vector< pair<int,int> > timeWork;

bool sortByTimeEnd(const pair<int,int> &a, 
              const pair<int,int> &b); 

int main() {
	int t;
 	cin >> t;
    	
	for (int u = 0; u < t; u++) {
		
		timeWork.clear();
		cin >> n;
		L = new int[n];
		
		for (int i = 0; i < n; i++) {
			int start, end;
			cin >> start >> end;
			timeWork.push_back(make_pair(start, end));
		}
		
		sort(timeWork.begin(), timeWork.end(), sortByTimeEnd);
		
		int max = 1;
//		L[0] = 1;
//		
//		for (int i = 1; i < n; i++) {
//			L[i] = 1;
//			for (int j = 0; j <= i - 1; j++) {
//				if (timeWork[i].first >= timeWork[j].second && L[j] + 1 > L[i]){
//					L[i] = L[j] + 1;					
//					max = L[i] > max ? L[i] : max;
//				}
//			}
//		}
 
		int i = 0, j = 1;
		
		while (i < n && j < n){
			if (timeWork[j].first >= timeWork[i].second) {
				max++;
				i = j; 
			} 
			j++;
		}	
			
		cout << max << endl;
		
	}
	
	return 0;
}

bool sortByTimeEnd(const pair<int,int> &a, const pair<int,int> &b) {
	return (a.second < b.second);
}
