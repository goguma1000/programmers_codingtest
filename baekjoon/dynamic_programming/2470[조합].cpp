#include<iostream>
#include<vector>
std::vector<int>add(const std::vector<int>& a, const std::vector<int>& b) {
	std::vector<int>result;
	int diff = a.size() - b.size();
	int lc = diff > 0 ? b.size() : a.size();
	int c = 0;
	for (int i = 0; i < lc; i++) {
		int temp = a[i] + b[i] + c;
		c = temp / 10;
		result.push_back(temp % 10);
	}
	if (diff == 0) {
		if (c > 0) result.push_back(c);
		return result;
	}

	for (int i = lc; i < a.size() || i < b.size(); i++) {
		int temp = diff > 0 ? a[i] + c : b[i] + c;
		c = temp / 10;
		result.push_back(temp % 10);
	}
	if (c > 0) result.push_back(c);
	return result;
}

int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	
	int n, r;
	std::cin >> n >> r;
	std::vector<std::vector<std::vector<int>>> table(n);
	table[1].push_back(std::vector<int>(1,1));
	table[1].push_back(std::vector<int>(1,1));
	for (int i = 2; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			std::vector<int>temp;
			if (j == 0 || j == i) temp.push_back(1);
			else {
				temp = add(table[i - 1][j - 1], table[i - 1][j]);
			}
			table[i].push_back(temp);
		}
	}
	std::vector<int> result = add(table[n - 1][r - 1], table[n - 1][r]);
	for (int i = result.size() - 1; i >= 0; i--) {
		std::cout << result[i];
	}
	return 0;
}
