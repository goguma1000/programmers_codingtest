#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		stack<char> s;
		for (int j = 0; j < str.length(); j++) {
			if (str[j] == '(') s.push(str[j]);
			else {
				if (s.empty()) {
					s.push(str[j]);
					break;
				}
				else s.pop();
			}
		}
		if (s.size() == 0) {
			cout << "YES" << '\n';
		}
		else {
			cout << "NO" << '\n';
		}
	}
	return 0;
}
