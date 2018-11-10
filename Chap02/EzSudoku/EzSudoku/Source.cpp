#include<iostream>

using namespace std;

int T;
int a[9]; // danh dau su co mat tu 1 -> 8

struct TestCase {
	int hasAnswer;
	int x[9][9];
	int startRow;
	int startColumn;
};

TestCase *testCase;

void input(TestCase &testCase);
void reset();

void TRY(int i, int j, int index, int x[9][9]);

bool checkFullRowCol(int x[9][9]);
bool checkColumnRow(int r, int c, int x[9][9]);
bool checkGrid(int r, int c, int x[9][9]);

void display(int x[9][9]);

int main() {

	cin >> T;
	testCase = new TestCase[T];

	for (int i = 0; i < T; i++) {
		input(testCase[i]);
		bool check = checkGrid(1, 1, testCase[i].x) && checkGrid(1, 5, testCase[i].x) 
						&& checkGrid(5, 1, testCase[i].x) && checkGrid(5, 5, testCase[i].x) 
						&& checkFullRowCol(testCase[i].x);
		if (check) {
			TRY(testCase[i].startRow + 1, testCase[i].startColumn + 1, i, testCase[i].x);
			if (testCase[i].hasAnswer == 1) {
				cout << "Test case #" << i + 1 << ": " << "YES" << endl;
				display(testCase[i].x);
			}
			else {
				cout << "Test case #" << i + 1 << ": " << "NO" << endl;
			}
		} else {
			cout << "Test case #" << i + 1 << ": " << "NO" << endl;
		}
	}

	system("pause");
	return 0;
}

void input(TestCase &testCase) {
	testCase.startRow = 0;
	testCase.startColumn = 0;
	testCase.hasAnswer = -1;
	for (int i = 1; i < 9; i++) {
		for (int j = 1; j < 9; j++) {
			cin >> testCase.x[i][j];
			if (testCase.x[i][j] == 0 && testCase.startRow == 0 && testCase.startColumn == 0) {
				testCase.startRow = i - 1;
				testCase.startColumn = j - 1;
			}
		}
	}
}

void TRY(int i, int j, int index, int x[9][9]) { 
	//cout << "i " << i << " j " << j << endl;

	if (i == 9) {
		testCase[index].hasAnswer = 1;
		return;
	}

	if (x[i][j] == 0) {
		for (int ucv = 1; ucv <= 8; ucv++) {
			//cout << ucv << endl;
			x[i][j] = ucv;
			bool c = checkColumnRow(i, j, x) && checkGrid(i, j, x);
			if (c) {
				if (j < 8) TRY(i, j + 1, index, x);
				else if (j == 8) TRY(i + 1, 1, index, x);
			}
			if (testCase[index].hasAnswer == 1) return;
			x[i][j] = 0;
		}
	} else {
		if (j < 8) TRY(i, j + 1, index, x); 
		else if (j == 8) TRY(i + 1, 1, index, x);
	}

}

void display(int x[9][9]) {
	for (int i = 1; i < 9; i++) {
		for (int j = 1; j < 9; j++) {
			cout << x[i][j] << " ";
		}
		cout << endl;
	}
}

void reset() {
	for (int i = 1; i <= 8; i++) {
		a[i] = -1;
	}
}

bool checkFullRowCol(int x[9][9]) {
	for (int i = 1; i <= 8; i++) {
		if (!checkColumnRow(i, i, x)) return false;
	}
	return true;
}

bool checkColumnRow(int r, int c, int x[9][9]) {
	
	int checkRow[9], checkCol[9];

	for (int i = 1; i <= 8; i++) {
		checkCol[i] = checkRow[i] = -1;
	}

	for (int i = 1; i <= 8; i++) {
		if (x[i][c] != 0) {
			checkCol[x[i][c]]++;
			if (checkCol[x[i][c]] > 0) return false;
		}
	}

	for (int i = 1; i <= 8; i++) {
		if (x[r][i] != 0) {
			checkRow[x[r][i]]++;
			if (checkRow[x[r][i]] > 0) return false;
		}
	}

	return true;
}

bool checkGrid(int r, int c, int x[9][9]) {
	reset();
	int i, j;
	
	if (1.0 * r / 4 <= 1) i = 1;
	else i = 5;

	if (1.0 * c / 4 <= 1) j = 1;
	else j = 5;
	for (int t = i; t < i + 4; t++) {
		for (int k = j; k < j + 4; k++) {
			if (x[t][k] != 0) {
				a[x[t][k]]++;
				if (a[x[t][k]] > 1) return false;
			}
		}
	}
	return true;
}