#include<iostream>

using namespace std;

struct MyStack {
	int size;
	char a[100001];
};

struct Test {
	int result;
	char expression[100001];
};

void innitStack(MyStack &stack);
void push(char value, MyStack &stack);
char pop(MyStack &stack);
char top(MyStack &stack);
bool isEmpty(MyStack &stack);
int length(char *s);
int checkingParentheses(char *s);

int main() {
	
	int num; 
	cin >> num;
	
	Test *test = new Test[num];
	
	for (int i = 0; i < num; i++){
		cin >> test[i].expression;
		test[i].result = checkingParentheses(test[i].expression);
	}

	for (int i = 0; i < num; i++){
		cout << test[i].result << endl;
	}

	return 0;
}

int checkingParentheses(char *s) {
	
	int len = length(s);
	
	MyStack stack;
	innitStack(stack);
	
	for (int i = 0; i < len; i++) {	
		if (isEmpty(stack)) push(s[i], stack);
		else if (s[i] == ')' && top(stack) == '(') pop(stack);
		else if (s[i] == ']' && top(stack) == '[') pop(stack);
		else if (s[i] == '}' && top(stack) == '{') pop(stack);
		else push(s[i], stack);
	}
	
	return isEmpty(stack);
}

int length(char *s){
	int i = 0;
	while (s[i] != '\0'){
		i++;
	}
	return i;
}

void innitStack(MyStack &stack){
	stack.size = -1;
}

void push(char value, MyStack &stack) {
	stack.a[++stack.size] = value;
}

char pop(MyStack &stack) {
	return stack.a[stack.size--];
}

char top(MyStack &stack){
	return stack.a[stack.size];
}

bool isEmpty(MyStack &stack) {
	return stack.size == -1;
}

