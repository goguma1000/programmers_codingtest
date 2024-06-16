#include<iostream>
#include<math.h>
int SquareSumCount(int n, int depth) {
	int sqrt_n = sqrt(n);
	int result = 5;
	if (depth > 3) return 4;
	for (int i = sqrt_n; i > 0; i--) {
		if (n == i * i) return depth;
		int temp = SquareSumCount(n - i * i, depth + 1);
		if (temp < result) result = temp;
	}
	return result;
}
int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	int n;
	std::cin >> n;
	std::cout << SquareSumCount(n,1);
	return 0;
}

//sol2
#include<iostream>
#include<vector>
int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	int n;
	std::cin >> n;
	std::vector<int> dp(n + 1);
	dp[1] = 1;
	for (int i = 2; i <= n; i++) {
		int min = 0;
		for (int j = 1; j * j <= i; j++) {
			int temp = i - j * j;
			if (min == 0 || min > dp[temp]) min = dp[temp];
		}
		dp[i] = min + 1;
	}
	std::cout << dp[n];
	return 0;
}
