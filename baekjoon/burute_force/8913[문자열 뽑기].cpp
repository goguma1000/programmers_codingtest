#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
bool dfs(string str) {
	if (str.length() == 0) return true;
	else if (str.length() == 1) return false;
	int st = 0, end = 0;
	bool result = false;
	for (int i = 1; i < str.length(); i++) {
		if (str[i] == str[st]) {
			end = i;
		}
		else {
			if (end - st > 0) {
				string sub = str.substr(0, st) + str.substr(end + 1, str.length() - end - 1);
				result = dfs(sub);
				if (result == true) return result;
			}
			st = i;
			end = i;
		}
	}
	if (st != end) {
		string sub = str.substr(0, st) + str.substr(end + 1, str.length() - end - 1);
		return result = dfs(sub);
	}
	return result;
}
int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	int t;
	cin >> t;
	while (t > 0) {
		string str;
		cin >> str;
		bool result;
		result = dfs(str);
		cout << result <<'\n';
		t--;
	}
	return 0;
}

