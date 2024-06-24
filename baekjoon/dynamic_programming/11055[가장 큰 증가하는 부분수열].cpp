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
	maxSum[n - 1] = arr[n - 1];
	for (int i = n - 2; i > -1; i--) {
		int max = arr[i];
		for (int j = i + 1; j < n; j++) {
			int temp = arr[i] + maxSum[j];
			if (arr[i] < arr[j] && max < temp) max = temp;
		}
		maxSum[i] = max;
	}
	int result = 0;
	for (int i = 0; i < n; i++) {
		result = result > maxSum[i] ? result : maxSum[i];
	}
	std::cout << result;
	return 0;
}
