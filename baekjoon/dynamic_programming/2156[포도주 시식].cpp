//sol1
#include<iostream>
#include<vector>

int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	
	int n;
	std::cin >> n;
	std::vector<int> cups(n);
	std::vector<int> dp(n);
	for (int i = 0; i < n; i++) {
		int temp;
		std::cin >> temp;
		cups[i] = temp;
	}
	dp[0] = cups[0];
	int result(dp[0]);
	if (n > 1) {
		dp[1] = dp[0] + cups[1];
		result = result > dp[1] ? result : dp[1];
	}
	if (n > 2) {
		dp[2] = dp[0] + cups[2] > cups[1] + cups[2] ? dp[0] + cups[2] : cups[1] + cups[2];
		result = result > dp[2] ? result : dp[2];
	}
	for (int i = 3; i < n; i++) {
		int max = 0;
		for (int j = i - 2; j > -1; j--) {
			int temp; 
			if (j == i - 2) temp = dp[j] + cups[i];
			else {
				temp = dp[j] + cups[i - 1] + cups[i];
			}
			max = max > temp ? max : temp;
		}
		dp[i] = max;
		result = result > max ? result : max;
	}
	std::cout << result;
	return 0;
}

//sol 2
#include<iostream>
#include<vector>

int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	
	int n;
	std::cin >> n;
	std::vector<int> cups(n);
	std::vector<int> dp(n);
	for (int i = 0; i < n; i++) {
		int temp;
		std::cin >> temp;
		cups[i] = temp;
	}
	dp[0] = cups[0];
	if (n > 1) {
		dp[1] = dp[0] + cups[1];
	}
	if (n > 2) {
		int temp = cups[1] + cups[2] > cups[0] + cups[2] ? cups[1] + cups[2] : cups[0] + cups[2];
		dp[2] = temp > dp[1] ? temp : dp[1];
	}
	for (int i = 3; i < n; i++) {
		int temp = dp[i - 2] + cups[i] > dp[i - 1] ? dp[i - 2] + cups[i] : dp[i - 1];
		temp = temp > dp[i - 3] + cups[i - 1] + cups[i] ? temp : dp[i - 3] + cups[i - 1] + cups[i];
		dp[i] = temp;
	}
	std::cout << dp[n - 1];
	return 0;
}
