#include<iostream>

int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	
	int n;
	int modNum = 1000000000;
	std::cin >> n;
	long long dp[101][10] = {0};

	for (int i = 0; i < 10 ; i++) {
		dp[1][i] = 1;
	}
	for (int i = 2; i <= n; i++) {
		dp[i][0] = dp[i - 1][1];
		for (int j = 1; j < 10; j++) {
			dp[i][j] += dp[i - 1][j - 1] % modNum;
			if(j + 1 < 10)dp[i][j] += dp[i - 1][j + 1] % modNum ;
		}
	}
	long long result = 0;
	for (int i = 1; i < 10; i++) {
		result += dp[n][i];
		result %= modNum;
	}
	std::cout << result;
	return 0;
}
