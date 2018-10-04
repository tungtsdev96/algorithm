#include<iostream>

using namespace std;

int T;
int a[9]; // danh dau su co mat tu 1 -> 8
bool markRow[9];
bool markCol[9];
bool markGrid[9][9];

struct TestCase {
	int hasAnswer;
	int x[9][9];
	int coppy[9][9];
	int countTry;
};

TestCase *testCase;

void input(TestCase &testCase);
void reset();
void resetMark();

void TRY(int i, int j, int index, int x[9][9]);
int check(int r, int c, int ucv, int x[9][9]);
int checkColumn(int r, int c, int ucv, int x[9][9]);
int checkRow(int r, int c, int ucv, int x[9][9]);
int checkGrid(int r, int c, int ucv, int x[9][9]);

bool checkColumn(int r, int c, int x[9][9]);
bool checkRow(int r, int c, int x[9][9]);
bool checkGrid(int r, int c, int x[9][9]);

void display(int x[9][9]);
void coppyAnswer(int coppy[9][9], TestCase &testCase);

int main() {

	cin >> T;
	testCase = new TestCase[T];
	for (int i = 0; i < T; i++) {
		input(testCase[i]);
	}

	

	for (int i = 0; i < T; i++) {
		resetMark();
		TRY(1, 1, i, testCase[i].coppy);
		cout << "Test case #" << i + 1 << ": " << (testCase[i].hasAnswer == 1 ? "YES" : "NO") << endl;
		if (testCase[i].hasAnswer == 1) display(testCase[i].x);
	}

	system("pause");
	return 0;
}

void resetMark() {
	markGrid[1][1] = false;
	markGrid[1][5] = false;
	markGrid[5][1] = false;
	markGrid[5][5] = false;
	for (int i = 1; i <= 8; i++) {
		markRow[i] = false;
		markCol[i] = false;
	}
}

void input(TestCase &testCase) {
	testCase.hasAnswer = -1;
	testCase.countTry = 0;
	for (int i = 1; i < 9; i++) {
		for (int j = 1; j < 9; j++) {
			cin >> testCase.x[i][j];
			testCase.coppy[i][j] = testCase.x[i][j];
		}
	}
}

void TRY(int i, int j, int index, int x[9][9]) { 
	//cout << "i " << i << " j " << j << endl;
	if (testCase[index].hasAnswer == 0 || testCase[index].hasAnswer == 1) return;

	if (i == 9) {
		coppyAnswer(x, testCase[index]);
		return;
	}

	if (x[i][j] == 0) {
		for (int ucv = 1; ucv <= 8; ucv++) {
			if (testCase[index].hasAnswer == 0 || testCase[index].hasAnswer == 1) return;
			//cout << ucv << endl;
			int c = check(i, j, ucv, x);
			if (c == 1) {
				x[i][j] = ucv;
				if (j < 8) TRY(i, j + 1, index, x);
				//if (i == 8 && j == 8) coppyAnswer(x, testCase[index]);
				else if (j == 8) TRY(i + 1, 1, index, x);
				x[i][j] = 0;
			} else if (c == -1) {
				testCase[index].hasAnswer = 0;
				return;
			}
		}
	} else {
		testCase[index].countTry++;
		if (!markRow[i]) 
			if (!checkRow(i, j, testCase[index].x)) testCase[index].hasAnswer = 0;

		if (!markCol[j])
			if (!checkColumn(i, j, testCase[index].x)) testCase[index].hasAnswer = 0;

		if ((i == 1 || i == 5) && (j == 1 || j == 5)) {
			if (!markGrid[i][j])
				if (!checkGrid(i, j, testCase[index].x)) testCase[index].hasAnswer = 0;
		}

		if (j < 8) TRY(i, j + 1, index, x); 
		//else if (i == 8 && j == 8) {
		//	//if (testCase[index].countTry == 64) {
		//	//	testCase[index].hasAnswer = 0;
		//	//	/*if (!checkRow(coppy) || !checkColumn(coppy) || !checkGrid(coppy)) {
		//	//	testCase[index].hasAnswer = 0;
		//	//	return;
		//	//	}
		//	//	testCase[index].hasAnswer = 1;*/
		//	//	return;
		//	//}
		//	return;
		//} 
		else if (j == 8) TRY(i + 1, 1, index, x);
	}

}

void coppyAnswer(int coppy[9][9], TestCase &testCase) {
	testCase.hasAnswer = 1;
	for (int i = 1; i <= 8; i++) {
		for (int j = 1; j <= 8; j++) {
			testCase.x[i][j] = coppy[i][j];
			//cout << testCase.x[i][j] << " ";
		}
		//cout << endl;
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

int check(int r, int c, int ucv, int x[9][9]) {

	// column 
	int column = checkColumn(r, c, ucv, x);
	if (column != 1) return column;

	// row
	int row = checkRow(r, c, ucv, x);
	if (row != 1) return row;

	// grid
	int grid = checkGrid(r, c, ucv, x);
	if (grid != 1) return grid;

	return 1;
}

int checkColumn(int r, int c, int ucv, int x[9][9]) {
	reset();
	for (int i = 1; i <= 8; i++) {
		if (i == r || x[i][c] == 0) continue;
		//else if (x[i][c] == 0) return 1;
		a[x[i][c]]++;
		if (a[x[i][c]] > 0) return -1;
		if (a[ucv] != -1) return 0;
	}
	return 1;
}

int checkRow(int r, int c, int ucv, int x[9][9]) {
	reset();
	for (int j = 1; j <= 8; j++) {
		if (j == c || x[r][j] == 0) continue;
		//else if (x[r][j] == 0) return 1;
		a[x[r][j]]++;
		if (a[x[r][j]] > 0) return -1;
		if (a[ucv] != -1) return 0;
	}
	return 1;
}

int checkGrid(int r, int c, int ucv, int x[9][9]) {
	reset();
	int i, j;
	
	if (1.0 * r / 4 <= 1) i = 1;
	else i = 5;

	if (1.0 * c / 4 <= 1) j = 1;
	else j = 5;

	for (int t = i; t < i + 4; t++) {
		for (int k = j; k < j + 4; k++) {
			if ((t == r && k == c) || x[t][k] == 0) continue;
			//else if (x[t][k] == 0) return 1;
			a[x[t][k]]++;
			if (a[x[t][k]] > 1) return -1;
			if (a[ucv] == 1) return 0;
		}
	}
	return 1;
}

bool checkColumn(int r, int c, int x[9][9]) {
	markCol[c] = true;
	reset();
	for (int i = 1; i <= 8; i++) {
		if (x[i][c] != 0) {
			a[x[i][c]]++;
			if (a[x[i][c]] > 0) return false;
		}
	}
	return true;
}

bool checkRow(int r, int c, int x[9][9]) {
	markRow[r] = true;
	reset();
	for (int i = 1; i <= 8; i++) {
		if (x[r][i] != 0) {
			a[x[r][i]]++;
			if (a[x[r][i]] > 0) return false;
		}
	}
	return true;
}

bool checkGrid(int r, int c, int x[9][9]) {
	markGrid[r][c] = true;
	reset();
	for (int t = r; t < r + 4; t++) {
		for (int k = c; k < c + 4; k++) {
			if (x[t][k] != 0) {
				a[x[t][k]]++;
				if (a[x[t][k]] > 1) return false;
			}
		}
	}
	return true;
}