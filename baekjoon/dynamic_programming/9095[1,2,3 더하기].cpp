#include<iostream>
#include<vector>
int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	int t;
	std::cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		std::cin >> n;
		std::vector<int> dp(n + 1);
		dp[1] = 1;
		dp[2] = 2;
		dp[3] = 4;
		for (int j = 4; j <= n; j++) {
			dp[j] = dp[j - 3] + dp[j - 2] + dp[j - 1];
		}
		std::cout << dp[n] << '\n';
	}
	return 0;
}
