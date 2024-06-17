#include<iostream>
#include<vector>
#include<climits>
int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	int n;
	std::cin >> n;
	std::vector<int> dp(n + 1);
	dp[1] = 0;
	for (int i = 2; i <= n; i++) {
		int min = INT_MAX;
		if (i % 3 == 0) min = dp[i / 3] + 1;
		if (i % 2 == 0) min = dp[i / 2] + 1 > min ? min : dp[i / 2] + 1;
		min = dp[i - 1] + 1 > min ? min : dp[i - 1] + 1;
		dp[i] = min;
	}
	std::cout << dp[n];
	return 0;
}
