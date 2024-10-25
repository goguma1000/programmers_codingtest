#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	int n;
	cin >> n;
	vector<int>arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end(), greater<int>());
	long long result = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] - i > 0) result += static_cast<long long>(arr[i] - i);
	}
	cout << result;
	return 0;
}


