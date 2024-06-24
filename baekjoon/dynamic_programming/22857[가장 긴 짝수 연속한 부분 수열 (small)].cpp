#include<iostream>
#include<vector>

int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	
	int n, k;
	std::cin >> n >> k;
	std::vector<int> arr;
	std::vector<int> dp(n);
	for (int i = 0; i < n; i++) {
		int temp;
		std::cin >> temp;
		arr.push_back(temp);
	}

	for (int i = n - 1; i > -1; i--) {
		int eraseNum = 0;
		int length = arr[i] % 2 == 0 ? 1 : 0;
		if (i != n - 1 && arr[i + 1] % 2 == 0) length += dp[i + 1];
		else {
			for (int j = i + 1; j < n; j++) {
				if (arr[j] % 2 != 0) {
					if (eraseNum != k) eraseNum++;
					else break;
				}
				else length++;
			}
		}
		dp[i] = length;
	}
	int result = dp[0];
	for (int i = 1; i < n; i++) {
		result = result > dp[i] ? result : dp[i];
	}
	std::cout << result;
	return 0;
}
