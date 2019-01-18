#include<bits/stdc++.h>

using namespace std;

int n;
vector< pair<int,int> > score;

bool check(int index);

int main() {
	
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		int sc1, sc2;
		cin >> sc1 >> sc2;
		score.push_back(make_pair(sc1, sc2));
	}
	
	
	int result = 0;
	for (int i = 0; i < n; i++) {
		if (check(i)) result++;
	}
	
	cout << result << endl;
	
	return 0;
}

bool check(int index) {
	for (int j = 0 ; j < n; j++) {
		if (score[j].first > score[index].first && score[j].second > score[index].second) {
			return false;
		}
	}
	return true;
}#include<bits/stdc++.h>

using namespace std;

int n;
vector< pair<int,int> > score;

bool check(int index);

int main() {
	
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		int sc1, sc2;
		cin >> sc1 >> sc2;
		score.push_back(make_pair(sc1, sc2));
	}
	
	
	int result = 0;
	for (int i = 0; i < n; i++) {
		if (check(i)) result++;
	}
	
	cout << result << endl;
	
	return 0;
}

bool check(int index) {
	for (int j = 0 ; j < n; j++) {
		if (score[j].first > score[index].first && score[j].second > score[index].second) {
			return false;
		}
	}
	return true;
}#include<bits/stdc++.h>

using namespace std;

int n;
vector< pair<int,int> > score;

bool check(int index);

int main() {
	
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		int sc1, sc2;
		cin >> sc1 >> sc2;
		score.push_back(make_pair(sc1, sc2));
	}
	
	
	int result = 0;
	for (int i = 0; i < n; i++) {
		if (check(i)) result++;
	}
	
	cout << result << endl;
	
	return 0;
}

bool check(int index) {
	for (int j = 0 ; j < n; j++) {
		if (score[j].first > score[index].first && score[j].second > score[index].second) {
			return false;
		}
	}
	return true;
}
