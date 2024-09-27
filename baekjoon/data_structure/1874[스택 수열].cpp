#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	int n;
	cin >> n;
	vector<int> arr(n);
	for(int i = 0; i<n;i++){
		cin >> arr[i];
	}
	stack<int> s;
	int idx = 0;
	int num = 1;
	string result = "";
	while (idx < n) {
		if (num <= arr[idx]) {
			s.push(num);
			num++;
			result += '+';
		}
		else {
			if (s.empty() || s.top() < arr[idx]) {
				cout << "NO";
				return 0;
			}
			while (!s.empty())
			{
				int top = s.top();
				s.pop();
				result += '-';
				if (arr[idx] == top) {
					idx++;
					break;
				}
			}
		}
	}
	for (int i = 0; i < result.length(); i++) {
		cout << result[i] << '\n';
	}
}
