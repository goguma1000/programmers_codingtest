//sol 2는 직접 작성한 코드.
//답을 참고하여 sol 1 작성.
//sol 2보다 sol 1이 코드가 훨씬 깔끔함.

//sol 1.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	int result = 0;
	scanf("%d", &result);
	char op;
	int num;
	bool onParenthesis = false;
	while (true) {
		scanf("%c", &op);
		if (op == '\n') break;
		scanf("%d", &num);
		if (op == '-') {
			onParenthesis = true;
		}
		
		if (onParenthesis) result -= num;
		else result += num;
	}
	printf("%d", result);
}

//sol 2.
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	string str;
	cin >> str;
	string numBuf = "";
	int result = 0;
	int inParenthesisNum = 0;
	bool onParenthesis = false;
	bool firstNum = true;
	for (int i = 0; i < str.length(); i++) {
		if ('0' <= str[i] && str[i] <= '9') {
			numBuf += str[i];
		}
		else {
			int temp  = stoi(numBuf);
			if (firstNum) {
				result += temp;
				firstNum = false;
				if (str[i] == '-') onParenthesis = true;
				numBuf = "";
				continue;
			}
			numBuf = "";

			if (str[i] == '-') {
				if (onParenthesis) {
					result -= inParenthesisNum;
					inParenthesisNum = 0;
					inParenthesisNum += temp;
				}
				else {
					result += temp;
					onParenthesis = true;
				}
			}
			else if (str[i] == '+') {
				if (onParenthesis) {
					inParenthesisNum += temp;
				}
				else result += temp;
			}
		}
	}
	if (onParenthesis) {
		inParenthesisNum += stoi(numBuf);
		result -= inParenthesisNum;
	}
	else {
		result += stoi(numBuf);
	}
	cout << result;
}
