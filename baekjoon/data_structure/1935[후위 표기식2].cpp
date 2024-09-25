//float는 소수점 6자리까지 정확히 표현가능 해당 문제는 계산값의 최대값이 2*10^9 이므로 float를 사용하면 오차가 전파됨.
#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	stack<double> s;
	int n;
	cin >> n;
	double value[26] = { 0, };
	string postFixEXP;
	cin >> postFixEXP;
	for (int i = 0; i < n; i++) {
		cin >> value[i];
	}
	for (int i = 0; i < postFixEXP.length(); i++) {
		if ('A' <= postFixEXP[i] && postFixEXP[i] <= 'Z') {
			s.push(value[postFixEXP[i] - 'A']);
		}
		else {
			double val2 = s.top();
			s.pop();
			double val1 = s.top();
			s.pop();
			switch (postFixEXP[i])
			{
			case '+':
				val1 += val2;
				break;
			case '-':
				val1 -= val2;
				break;
			case '*':
				val1 *= val2;
				break;
			case '/':
				val1 /=val2;
				break;
			default:
				break;
			}
			s.push(val1);
		}
	}
	cout << fixed;
	cout.precision(2);
	cout << s.top();
	return 0;
}
