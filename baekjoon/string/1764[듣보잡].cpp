#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	unordered_map<string, int> not_listened;
	vector<string> result;
	for (int i = 0; i < n; i++) {
		string temp;
		cin >> temp;
		not_listened.insert({ temp,0 });
	}
	for (int j = 0; j < m; j++) {
		string temp;
		cin >> temp;
		if (not_listened.find(temp) != not_listened.end()) {
			result.push_back(temp);
		}
	}
	cout << result.size()<<'\n';
	sort(result.begin(), result.end());
	for (auto s : result) cout << s << '\n';
	return 0;
}
