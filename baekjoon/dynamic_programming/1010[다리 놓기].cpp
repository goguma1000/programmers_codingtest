#include<iostream>

int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	long long t,n,m;
	std::cin >> t;
	for (int i = 0; i < t; i++) {
		std::cin >> n >> m;
		long long result = 0;
		if (n == m) {
			result = 1;
		}
		else {
			long long left = n, right = 1;
			result = left + right;
			for (long long i = 2; i < m - n + 1; i++) {
				left = left * (n - 1 + i) / i;
				result += left;
			}
		}
		std::cout << result << "\n";
	}
	
	return 0;
}
///sol 2
#include<iostream>

int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	long long t,n,m;
	std::cin >> t;
	for (int i = 0; i < t; i++) {
		std::cin >> n >> m;
		int r = 1;
		long long result = 1;
		for (int j = m; j > m - n; j--) {
			result = result * j / r;
			r++;
		}
		std::cout << result << "\n";
	}
	
	return 0;
}
