#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	string str;
	cin >> str;
	stack<char> pipes;
	stack<int> razerCounts;
	int curRazerCount = 0;
	int sum = 0;
	for (int i = 0; i < str.length() - 1; i++) {
		char left = str[i];
		char right = str[i + 1];
		if (left == '(' && right == '(') {
			razerCounts.push(0);
			pipes.push(left);
		}
		if (left == ')' && right == ')') {
			curRazerCount = razerCounts.top();
			razerCounts.pop();
			sum += curRazerCount + 1;
			if (!razerCounts.empty()) {
				curRazerCount += razerCounts.top();
				razerCounts.pop();
				razerCounts.push(curRazerCount);
			}
			pipes.pop();
		}
		if (left == '(' && right == ')') {
			if (!pipes.empty()) {
				curRazerCount = razerCounts.top();
				razerCounts.pop();
				razerCounts.push(curRazerCount + 1);
			}
		}
	}
	cout << sum;
}
