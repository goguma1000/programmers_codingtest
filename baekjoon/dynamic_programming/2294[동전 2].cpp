#include<iostream>
#include<vector>
int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	int n, k;
	std::cin >> n >> k;
	std::vector<int> dp(k + 1);
	for (int i = 0; i < n; ++i) {
		int coin;
		std::cin >> coin;
		for (int i = coin; i <= k; i++) {
			if (i - coin == 0) {
				dp[i] = 1;
				continue;
			}
			if (dp[i - coin] == 0) continue;
			int temp(dp[i - coin] + 1);
			if (dp[i] == 0 || dp[i] > temp) dp[i] = temp;
		}
	}
	if (dp[k] == 0) std::cout << -1;
	else std::cout << dp[k];
	return 0;
}
