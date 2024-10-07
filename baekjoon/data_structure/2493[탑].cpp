#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	int n;
	cin >> n;
	vector<int> heights(n);
	vector<int> result(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> heights[i];
	}
	stack<int> s;
	s.push(n - 1);
	for (int i = n - 2; i >= 0; i--) {
		while (!s.empty()) {
			if (heights[i] >= heights[s.top()]) {
				result[s.top()] = i + 1;
				s.pop();
			}
			else break;
		}
		s.push(i);
	}
	for (int r : result) {
		cout << r << ' ';
	}
	return 0;
}
