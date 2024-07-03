#include<iostream>
#include<vector>
int dp[1025][1025];
int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	
	int n, m;
	std::cin >> n >> m;
	for (int y = 1; y <=n; y++) for(int x = 1; x <= n; x++) {
		std::cin >> dp[y][x];
		dp[y][x] += dp[y][x - 1] + dp[y - 1][x] - dp[y - 1][x - 1];

	}

	for (int i = 0; i < m; i++) {
		int lc_row, lc_col, rc_row, rc_col;
		std::cin >> lc_row >> lc_col >> rc_row >> rc_col;
		std::cout << dp[rc_row][rc_col] -  dp[rc_row][lc_col - 1] - dp[lc_row - 1][rc_col] + dp[lc_row - 1][lc_col - 1] << '\n';
	}
	return 0;
}
