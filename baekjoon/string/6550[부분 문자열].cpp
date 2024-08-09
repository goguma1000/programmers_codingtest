#include<iostream>
#include<string>
using namespace std;

int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	string s, t;
	while (cin >> s >> t) {
		if (s.compare("") == 0 || t.compare("") == 0) break;
		int prev = 0, j = 0, i = 0;
		for (int i = 0; i < t.length(); ++i) {
			if (t[i] == s[j]) {
				j++;
			}
		}
		if (j >= s.length()) cout << "Yes\n";
		else cout << "No\n";
	}
	return 0;
}
