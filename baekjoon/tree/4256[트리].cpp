#include<iostream>
#include<stdio.h>
#include<vector>

void Post_Order(const std::vector<int>& preOrder, const std::vector<int>& inOrder, int start, int end, int root_idx) {
	for (int i = start; i < end; i++) {
		if (inOrder[i] == preOrder[root_idx]) {
			Post_Order(preOrder, inOrder, start, i, root_idx + 1);
			Post_Order(preOrder, inOrder, i + 1, end, root_idx + 1 + i - start );
			std::cout << preOrder[root_idx] << " ";
			break;
		}
	}
}
int main() {
	int t;
	std::cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		std::cin >> n;
		std::vector<int> pre_Order;
		std::vector<int> in_Order;
		for (int j = 0; j < n; j++) {
			int temp;
			std::cin >> temp;
			pre_Order.push_back(temp);
		}
		for (int j = 0; j < n; j++) {
			int temp;
			std::cin >> temp;
			in_Order.push_back(temp);
		}
		Post_Order(pre_Order,in_Order,0, n, 0);
		std::cout << "\n";
	}
	return 0;
}
