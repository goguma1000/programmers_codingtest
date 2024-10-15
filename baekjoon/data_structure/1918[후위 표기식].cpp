#include <stack>
#include <string>
#include <iostream>
using namespace std;

int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	string src;
	cin >> src;
	stack<char> operator_S;
	for (int i = 0; i < src.length(); i++) {
		char cur = src[i];
		if ('A' <= cur && cur <= 'Z') {
			cout << cur;
			continue;
		}
		if (operator_S.empty() || cur == '(') {
			operator_S.push(cur);
			continue;
		}
		char top = operator_S.top();
		if (top == '(' && cur != ')') {
			operator_S.push(cur);
		}
		else if (cur == '*' || cur == '/') {
			if((top == '+' || top == '-')) operator_S.push(cur);
			else {
				cout << top;
				operator_S.pop();
				operator_S.push(cur);
			}
		}
		else if ( cur == '+' || cur == '-') {
			while (!operator_S.empty()) {
				top = operator_S.top();
				if (top != '(') cout << top;
				else break;
				operator_S.pop();
			}
			operator_S.push(cur);
		}
		else if (cur == ')') {
			while (true) { 
				if (top != '(') {
					cout << top;
				}
				operator_S.pop();
				if (top == '(') break;
				top = operator_S.top();
			}
		}
	}
	while (!operator_S.empty()) {
		char temp = operator_S.top();
		if (temp != ' (' && temp != ')') cout << temp;
		operator_S.pop();
	}
	return 0;
}
