#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	int n, k;
	cin >> n >> k;
	vector<int> coins(n);
	for (int i = 0; i < n; i++) {
		cin >> coins[i];
	}
	int useCount = 0;
	for (int i = n - 1; i >= 0; i--) {
		if (coins[i] > k) continue;
		useCount += k / coins[i];
		k %= coins[i];
	}
	cout << useCount;
}
