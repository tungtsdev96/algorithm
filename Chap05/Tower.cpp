#include<bits/stdc++.h>

using namespace std;

int n, result, c = 1;
vector< pair<int,int> > area;
vector<int> z;
vector<int> L;
 
bool sortArea(int left, int right);
bool check(pair<int,int> a, pair<int,int> b);

int main() {
	
	while(true) {
		
		cin >> n;
		if (n == 0) break;
		
		result = 0;
		area.clear();
		z.clear();
		L.clear();
		
		for (int i = 0; i < n; i++) {
			int m, n ,h;
			cin >> m >> n >> h;
			area.push_back(make_pair(m, n)); z.push_back(h);
			area.push_back(make_pair(m, h)); z.push_back(n);
			area.push_back(make_pair(h, n)); z.push_back(m);
		}
		
		sortArea(0, 3*n - 1);
		
//		for (int i = 0; i < 3*n; i++) {
//			cout << area[i].first << " " << area[i].second << " " << z[i] << endl;
//		}
		
		L.resize(3 * n);
		for (int i = 0; i < 3*n; i++) {
			L[i] = z[i];
			for (int j = 0; j <= i - 1; j++) {
				if (check(area[i], area[j]) && L[i] < L[j] + z[i]) {
					L[i] = L[j] + z[i];
				}
			}
			result = L[i] > result ? L[i] : result; 
		}
		
		cout << "Case " << c++ << ": maximum height = " << result << endl;
	}
	
	return 0;
}

bool check(pair<int,int> a, pair<int,int> b) {
	if (a.first > b.first && a.second > b.second) return true;
	if (a.first > b.second && a.second > b.first) return true;
	return false;
}

bool sortArea(int left, int right) {
	int key = area[(left+right)/2].first * area[(left+right)/2].second;
	if(left <= right){
		int i = left;
		int j = right;
		while(i<=j){
			while(area[i].first * area[i].second < key) i++;
			while(area[j].first * area[j].second > key) j--;
			if(i <= j){
				swap(area[i], area[j]);
				swap(z[i], z[j]);
				i++;
				j--;
			}
		}
		if(left <= i){
			sortArea(left,j);
		}
		if(right >= j){
			sortArea(i, right);
		}
	}
}
