//답 봄
#include<iostream>
#include<vector>
int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	int c, n;
	std::cin >> c >> n;
	std::vector<std::vector<int>>arr(n);
	int maxCost = 0;
	for (int i = 0; i < n; i++) {
		arr[i].resize(2);
		std::cin >> arr[i][0] >> arr[i][1];
		maxCost = maxCost > arr[i][0] ? maxCost : arr[i][0];
	}
	int loopCnt(maxCost * c + 1);
	std::vector<int>dp(loopCnt);
	for (int i = 0; i < n; i++) {
		for (int j = 1; j < loopCnt; j++) {
			if (arr[i][0] <= j) {
				dp[j] = std::max(dp[j], dp[j - arr[i][0]] + arr[i][1]);
			}
		}
	}
	for (int i = 1; i < loopCnt; i++) {
		if (dp[i] >= c) {
			std::cout << i;
			break;
		}
	}
	return 0;
}
