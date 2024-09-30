#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	string str;
	cin >> str;
	if (str.length() % 2 != 0) {
		cout << 0;
		return 0;
	}
	stack<char>s;
	stack<int>values;
	for (int i = 0; i < str.length(); i++) {
		if (s.empty() && (str[i] == ')' || str[i] == ']')) {
			cout << 0;
			return 0;
		}

		if (str[i] == '(' || str[i] == '[') {
			s.push(str[i]);
			values.push(0);
		}
		else if (str[i] == ')' || str[i] == ']') {
			if ((s.top() == '[' && str[i] == ')') || (s.top() == '(' && str[i] == ']')) {
				cout << 0;
				return 0;
			}
			int temp = values.top();
			values.pop();
			if (str[i] == ')') {
				if (temp == 0) {
					temp += 2;
				}
				else {
					temp = temp * 2;
				}
			}
			else if (str[i] == ']') {
				if (temp == 0) {
					temp += 3;
				}
				else {
					temp = temp * 3;
				}
			}
			if (!values.empty()) temp += values.top();
			if (!values.empty())values.pop();
			values.push(temp);
			s.pop();
		}
	}
	int sum = 0;
	if (!s.empty()) {
		cout << 0;
	}
	else {
		cout << values.top();
	}
	return 0;
}
