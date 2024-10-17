#include <string>
#include <vector>
#include <unordered_set>
#include <iostream>
using namespace std;

int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	unordered_set<string> set;
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string temp;
		cin >> temp;
		set.insert(temp);
	}
	int result = 0;
	for (int i = 0; i < m; i++) {
		string temp;
		cin >> temp;
		if (set.find(temp) != set.end()) result++;
	}
	cout << result;
}
