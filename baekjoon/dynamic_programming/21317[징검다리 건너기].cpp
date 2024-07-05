#include<iostream>
#include<vector>
int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	int n, k;
	int stone[21][2] = { 0 };
	int dp[21][2] = { 0 };
	//dp[i][0] => i에 도착할 때까지 3step 안 뛴 경우
	//dp[i][1] => i에 도착할 때 3step을 뛰었거나 뛰어서 도착 
	std::cin >> n;
	for (int i = 1; i < n; i++) {
		std::cin >> stone[i][0] >> stone[i][1];
	}
	std::cin >> k;
	dp[1][1] = 999999;
	dp[2][1] = 999999;
	dp[3][1] = 999999;
	dp[2][0] = stone[1][0];
	dp[3][0] = std::min(stone[1][1], stone[1][0] + stone[2][0]);
	for (int i = 4; i <= n; i++) {
		dp[i][0] = std::min(dp[i - 2][0] + stone[i - 2][1], dp[i - 1][0] + stone[i - 1][0]);
		dp[i][1] = std::min(std::min(dp[i - 2][1] + stone[i - 2][1], dp[i - 1][1] + stone[i - 1][0]), dp[i - 3][0] + k);
	}
	std::cout << std::min(dp[n][0], dp[n][1]);
	return 0;
}
