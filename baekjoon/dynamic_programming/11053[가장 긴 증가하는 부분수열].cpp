#include<iostream>
#include<vector>

int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	
	int n;
	std::cin >> n;
	std::vector<int> arr;
	std::vector<int> length(n);
	for (int i = 0; i < n; i++) {
		int temp;
		std::cin >> temp;
		arr.push_back(temp);
	}
	length[n - 1] = 1;
	for (int i = n - 2; i > -1; i--) {
		int sum = 1;
		int max = 0;
		for (int j = i + 1; j < n; j++) {
			if (arr[i] < arr[j] && max < length[j]) {
				max = length[j];
			}
		}
		length[i] = sum + max;
	}
	int result = 0;
	for (int i = 0; i < n; i++) {
		result = result < length[i] ? length[i] : result;
	}
	std::cout << result;
	return 0;
}
