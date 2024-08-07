#include<iostream>
#include<unordered_set>
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
	unordered_set<string> arr;
	std::vector<string> result;
	while (n > 0) {
		string temp;
		cin >> temp;
		arr.insert(temp);
		--n;
	}
	for (auto str : arr) result.push_back(str);
	std::sort(result.begin(), result.end(), compare);
	for (auto str : result) cout << str << '\n';
	return 0;
}
