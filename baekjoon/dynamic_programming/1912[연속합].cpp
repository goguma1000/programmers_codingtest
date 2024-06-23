#include<iostream>
#include<vector>

int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	
	int n;
	std::cin >> n;
	std::vector<int> arr;
	std::vector<int> maxSum(n);
	for (int i = 0; i < n; i++) {
		int temp;
		std::cin >> temp;
		arr.push_back(temp);
	}
	int result = arr[n - 1];
	maxSum[n - 1] = arr[n - 1];
	for (int i = n - 2; i > -1; i--) {
		int tempSum = arr[i] + maxSum[i + 1];
		int max = arr[i] > tempSum ? arr[i] : tempSum;
		maxSum[i] = max;
		result = result >= max ? result : max;
	}

	std::cout << result;
	return 0;
}
