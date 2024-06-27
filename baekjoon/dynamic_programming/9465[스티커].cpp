#include<iostream>
#include<vector>

int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	
	int t, n;
	std::cin >> t;
	while (t > 0) {
		std::cin >> n;
		std::vector<int> arr;
		int result = 0;
		std::vector<int> dp(2 * n);
		for (int i = 0; i < 2 * n; i++) {
			int temp;
			std::cin >> temp;
			arr.push_back(temp);
		}
		dp[0] = arr[0];
		dp[n] = arr[n];
		if (n > 1) {
			dp[1] = arr[1] + dp[n];
			dp[n + 1] = arr[n + 1] + dp[0];
		}
		for (int i = 2; i < n; i++) {
			int temp1 = dp[n + i - 1] + arr[i];
			int temp2 = dp[n + i - 2] + arr[i];
			dp[i] = temp1 > temp2 ? temp1 : temp2;
			temp1 = dp[i - 1] + arr[n + i];
			temp2 = dp[i - 2] + arr[n + i];
			dp[n + i] = temp1 > temp2 ? temp1 : temp2;
		}
		result = dp[n - 1] > dp[2 * n - 1] ? dp[n - 1] : dp[2 * n - 1];
		std::cout << result << "\n";
		t--;
	}
	return 0;
}
