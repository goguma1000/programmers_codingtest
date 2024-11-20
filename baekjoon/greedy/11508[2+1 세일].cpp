#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	int n;
	cin >> n;
	vector<int>arr(n);
	int sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		sum += arr[i];
	}
	sort(arr.begin(), arr.end(), greater<int>());
	for (int i = 2; i < n; i += 3) {
		sum -= arr[i];
	}
	cout << sum;
}
