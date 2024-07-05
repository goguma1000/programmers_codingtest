#include<iostream>
#include<vector>
#include<math.h>
int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	int n, k;
	std::cin >> n >> k;
	std::vector<int> stone(n + 1);
	std::vector<bool>dp(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> stone[i];
	}
	dp[1] = true;
	dp[2] = 1 + std::abs(stone[1] - stone[2]) <= k;
	for (int j = 3; j <= n; j++) {
		for (int i = j - 1; i > 0 && j - i <= k; --i) {
			if (dp[i]) {
				bool temp((j - i) * (1 + std::abs(stone[i] - stone[j])) <= k);
				dp[j] = temp;
				if (temp) break;
			}
		}
	}
	if (dp[n]) std::cout << "YES";
	else std::cout << "NO";
	return 0;
}
