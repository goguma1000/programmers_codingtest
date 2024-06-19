#include<iostream>
#include<vector>

int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	
	int n;
	std::cin >> n;
	std::vector<int> score(n + 1);
	for (int i = 1; i <= n; i++) {
		int temp;
		std::cin >> temp;
		score[i] = temp;
	}
	std::vector<int> result(n + 1);
	result[1] = score[1];
	result[2] = result[1] + score[2];
	for (int i = 3; i <= n; i++) {
		int val1 = result[i - 2] + score[i];
		int val2 = result[i - 3] + score[i - 1] + score[i];
		result[i] = val1 > val2 ? val1 : val2;
	}
	std::cout << result[n];
	return 0;
}
