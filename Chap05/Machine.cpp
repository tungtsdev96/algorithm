#include<bits/stdc++.h>

using namespace std;

int n;
int result;
vector<int> L;

bool sortbysec(const pair<int,int> &a, const pair<int,int> &b);

int main() {
	
	vector< pair <int,int> > data; 
	cin >> n;
	for (int i = 0; i < n; i++) {
		int s, f;
		cin >> s >> f;
		data.push_back(make_pair(s ,f )); 
	}
	
	sort(data.begin(), data.end(), sortbysec);
	
//	for (int i = 0; i < n; i++) { 
//		int detalI = data[i].second - data[i].first;
//		L.push_back(detalI);
//		for (int j = 0; j <= i - 1; j++) {
//			int detalJ = data[j].second - data[j].first;
//			if ((data[i].first > data[j].second) && (L[i] < detalI + detalJ)) {
//				L[i] = detalI + detalJ;
//				result = L[i] > result ? L[i] : result;
//			}
//		}
//	}

	int i = 0, j = 1;
	result = 0;
	
	while (i < n && j < n) {
		int detalI = data[i].second - data[i].first;
		int detalJ = data[j].second - data[j].first;
		if ((data[j].first > data[i].second)){
			result = detalI + detalJ > result ? detalI + detalJ : result;
			i = j;
		} 	
		j++;
	}
	
	cout << result;
	
	return 0;
}

bool sortbysec(const pair<int,int> &a, 
              const pair<int,int> &b) { 
    return (a.second < b.second); 
} 
