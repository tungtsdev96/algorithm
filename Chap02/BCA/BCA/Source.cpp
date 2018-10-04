#include<iostream>
#include<vector>

using namespace std;

int n, m;
bool conflict[35][35];		// check xem khoa hoc co bị conflict k 
bool checkAssignedCourse[15][35];  // check xem thang GV da dki khoa hoc nao r
bool checkHasCourse[15][35];  // check xem thang GV co nhung mon nao
int a[35];				// luu tru GV tuong ung vs cac KH 1 -> m
int countMax[15];
int result = 1000;
bool hasAnswer = false;

void inputCourseOfTeacher();
void inputConflicting();
bool checkConditional(int teacher, int course);
void TRY(int i);
void displayResult();

int main() {

	cin >> m >> n;
	 
	// innit checkAssignedCourse [GV][CourseAssigned], checkHasCourse[GV][Course]
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			checkAssignedCourse[i][j] = false;
			checkHasCourse[i][j] = false;
		}
	}

	// innit confilict [Course1][Course2]
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			conflict[i][j] = false;
		}
	}

	// input
	inputCourseOfTeacher();
	inputConflicting();

	// back track
	/*TRY(1);
	cout << result;*/

	system("pause");
	return 0;
}

// m teacher
void inputCourseOfTeacher() {
	for (int teacher = 1; teacher <= m; teacher++) {
		int size;
		cin >> size;
		for (int j = 0; j < size; j++) {
			int course; 
			cin >> course;
			checkHasCourse[teacher][course] = true;
		}
	}
}

// n course
void inputConflicting() {
	int k;
	cin >> k;
	while (k-- > 0) {
		int i, j;
		cin >> i >> j;
		conflict[i][j] = true;
	}
}

/*
	i: course
	v: teacher
*/
void TRY(int i) {
	//cout << "i " << i << endl;
	for (int v = 1; v <= m; v++) {
		//cout << "te " << v << " cou " << i << endl;
		if (checkConditional(v, i)) {
			a[i] = v;
			checkAssignedCourse[v][i] = true;
			if (i == n) {
				displayResult();
			} else {
				TRY(i + 1);
			}
			checkAssignedCourse[v][i] = false;
		} 
	}
}

bool checkConditional(int teacher, int course) {

	// kiem tra gv co day course va mon hoc chua dc dki
	if (checkAssignedCourse[teacher][course]) return false;
	if (!checkHasCourse[teacher][course]) return false;

	// lay cac Khoa Hoc Gv da dki -> check confilct -> neu conflict return false
	for (int i = 1; i < course; i++) {
		if (checkHasCourse[teacher][i] && checkAssignedCourse[teacher][i]) {
			if (conflict[i][course]) return false;
		}
	}

	return true;
}

void displayResult() {
	hasAnswer = true;

	// reset count max
	int max = 0;

	for (int i = 1; i <= m; i++) {
		countMax[i] = 0;
	}

	for (int i = 1; i <= n; i++) {
		countMax[a[i]]++;
	}

	for (int i = 1; i <= m; i++) {
		max = max < countMax[i] ? countMax[i] : max;
	}
	
	result = max < result ? max : result;
}
