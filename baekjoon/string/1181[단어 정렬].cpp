#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
bool compare(string s1, string s2) {
	if (s1.length() < s2.length()) return true;
	else if (s1.length() == s2.length()) {
		if (s1 < s2) return true;
	}
	return false;
}
int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	int n;
	cin >> n;
	vector<string> arr(n);
	while (n > 0) {
		cin >> arr[n - 1];
		--n;
	}
	std::sort(arr.begin(), arr.end(), compare);
	string prev(" ");
	for (auto str : arr) {
		if (prev.compare(str) != 0) {
			cout << str << '\n';
			prev = str;
		}
	}
	return 0;
}
