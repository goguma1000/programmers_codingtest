#include<iostream>
#include<vector>

int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	int n;
	std::cin >> n;
	std::vector<std::vector<int>> arr(n + 1);
	std::vector<int> dp(n + 1);
	for (int i = 1; i <= n; i++) {
		arr[i].resize(2);
		std::cin >> arr[i][0] >> arr[i][1];
	}
	int max(0);
	int maxIdx(0);
	for (int i = n; i > 0; --i) {
		int nextIdx(arr[i][0] + i);
		if (nextIdx > n + 1) dp[i] = max;
		else {
			int temp(arr[i][1]);
			if (nextIdx != n + 1) temp += maxIdx < nextIdx ? dp[nextIdx] : max;
			if (temp >= max) {
				max = temp;
				maxIdx = i;
				dp[i] = temp;
			}
			else dp[i] = max;

		}
	}
	std::cout << max;
	return 0;
}
