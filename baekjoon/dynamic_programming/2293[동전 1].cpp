//답 봄. 처음엔 O(n*k)로 1~k원까지 모든 동전을 사용하여 만들 수 있는 경우의 수로 구함.
//위와 같이 하면 순서가 다른 것도 같은 경우로 포함됨.
//답은 각 동전으로 만들 수 있는 모든 가격에 대해 업데이트해 순서의 의미를 없앰.

#include<iostream>
#include<vector>
int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	int n, k;
	std::cin >> n >> k;
	std::vector<int>coins(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> coins[i];
	}
	std::vector<int> dp(k + 1);
	dp[0] = 1;
	for (int coin : coins) {
		for (int i = 1; i <= k; i++) {
			if (i - coin < 0) continue;
			dp[i] += dp[i - coin];
		}
	}
	std::cout << dp[k];
	return 0;
}
