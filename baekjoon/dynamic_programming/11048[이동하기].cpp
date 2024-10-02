#include <iostream>
#include <vector>

using namespace std;

int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<vector<int>>map(n + 2);
	vector<vector<int>> dp(n + 2);
	map[0].resize(m + 2, 0);
	dp[0].resize(m + 2, 0);
	map[n + 1].resize(m + 2, 0);
	dp[n + 1].resize(m + 2, 0);

	for (int i = 1; i <= n; i++) {
		map[i].resize(m + 2, 0);
		dp[i].resize(m + 2, 0);
		for (int j = 1; j <= m; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			int var1 = map[i][j] + dp[i - 1][j];
			int var2 = map[i][j] + dp[i][j - 1];
			int var3 = map[i][j] + dp[i - 1][j - 1];
			dp[i][j] = max(var1,max(var2, var3));
		}
	}
	cout << dp[n][m];
	return 0;
}
