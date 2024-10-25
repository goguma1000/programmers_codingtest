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
	sort(arr.begin(), arr.end());
	int sum = arr[0];
	for (int i = 1; i < n; i++) {
		int temp = arr[i - 1] + arr[i];
		arr[i] = temp;
		sum += temp;
	}
	cout << sum;
}


