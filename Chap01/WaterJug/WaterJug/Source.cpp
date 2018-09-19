#include<iostream>
#include<queue>

using namespace std;

struct State {
	int x;
	int y;
	bool checked;
};

int waterjug(int a, int b, int c);
bool check(State s, queue<State> myQueue);

int main() {
	int a, b, c;
	cin >> a >> b >> c;

	cout << waterjug(a, b, c);

	system("pause");
	return 0;
}

// check state have in queue
int waterjug(int a, int b, int c) {
	if (a < c && b < c) return -1;

	int dem = 0;
	bool hasAnswer = false;
	State start;
	start.x = a;
	start.y = b;
	start.checked = true;

	queue<State> myQueue;
	myQueue.push(start);

	while (!myQueue.empty())
	{
		dem++;
		State s = myQueue.front();
		myQueue.pop();
		int x = s.x;
		int y = s.y;

		int x1 = x, y1 = 0;
		State ss; ss.x = x1; ss.y = y1;
		if (x1 == c || y1 == c) {
			hasAnswer = true;
			break;
		}
		else {
			ss.checked = true;
			myQueue.push(ss);
		}

		x1 = 0; y1 = y;
		if (x1 == c || y1 == c) {
			hasAnswer = true;
			break;
		} else {
			myQueue.push(ss);
		}

		x1 = a; y1 = y;
		if (x1 == c || y1 == c) {
			hasAnswer = true;
			break;
		}
		else {
			myQueue.push(ss);
		}

		x1 = x; y1 = b;
		if (x1 == c || y1 == c) {
			hasAnswer = true;
			break;
		}
		else {
			myQueue.push(ss);
		}

		if (x + y >= a) {
			x1 = a; y1 = x + y - a;
			if (x1 == c || y1 == c) {
				hasAnswer = true;
				break;
			}
			else {
				myQueue.push(ss);
			}
		} else {
			x1 = x + y; y1 = 0;
			if (x1 == c || y1 == c) {
				hasAnswer = true;
				break;
			}
			else {
				myQueue.push(ss);
			}
		}

		if (x + y >= b) {
			x1 = x + y - b; y1 = b;
			if (x1 == c || y1 == c) {
				hasAnswer = true;
				break;
			}
			else {
				myQueue.push(ss);
			}
		}
		else {
			x1 = 0; y1 = x + y;
			if (x1 == c || y1 == c) {
				hasAnswer = true;
				break;
			}
			else {
				myQueue.push(ss);
			}
		}
	}

	dem = hasAnswer ? dem : -1;
	return dem;
}

bool check(State s, queue<State> myQueue) {
	
}
