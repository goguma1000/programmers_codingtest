#include<iostream>
#include<string>
#include<stack>
using namespace std;

void printStack(stack<char>& stack) {
	while (!stack.empty()) {
		cout << stack.top();
		stack.pop();
	}
}

int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	string str;
	stack<char> stack;
	bool onTag(false);
	getline(cin, str);
	for (int i = 0; i < str.length(); ++i) {
		if (str[i] == '<') {
			onTag = true;
			printStack(stack);
			cout << str[i];
		}
		else if (str[i] == '>') {
			onTag = false;
			cout << str[i];
		}
		else if (str[i] == ' ') {
			printStack(stack);
			cout << str[i];
		}
		else
		{
			if (onTag) cout << str[i];
			else stack.push(str[i]);
		}
	}
	printStack(stack);
	return 0;
}
