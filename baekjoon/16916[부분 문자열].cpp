#include<iostream>
#include<string>
#include<vector>
std::vector<int> MakeTable(const std::string& pattern) {
	std::vector<int> result(pattern.length());
	int i = 0, j = 1;
	while (j < pattern.length()) {
		if (pattern[i] == pattern[j]) {
			++i;
			result[j] = i;
		}
		else {
			while (true) {
				if (i == 0) break;
				i = result[i - 1];
				if (pattern[i] == pattern[j]) {
					++i;	
					result[j] = i;
					break;
				}
			}
		}
		++j;
	}
	return result;
}
bool KMP(const std::string& src, const std::string& pattern) {
	std::vector<int> table = MakeTable(pattern);
	int i(0), j(0);
	while (i < src.length()) {
		if (src[i] == pattern[j]) {
			++i;
			++j;
		}
		else {
			if (j == 0) i++;
			else j = table[j - 1];
		}
		if (j >= pattern.length()) return true;
	}
	return false;
}
int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	std::string s1, s2;
	std::cin >> s1 >> s2;
	if (KMP(s1, s2)) std::cout << 1;
	else std::cout << 0;
	return 0;
}
