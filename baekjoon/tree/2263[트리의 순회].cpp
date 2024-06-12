// In_Order의 인덱스를 저장하는 것이 많이 효율적
#include<iostream>
#include<stdio.h>
#include<vector>

void PreOrder(const std::vector<int>& in_order, const std::vector<int>& post_order, int in_start, int in_end, int post_start, int post_end) {
	for (int i = in_start; i <= in_end; i++) {
		if (in_order[i] == post_order[post_end]) {
			std::cout << post_order[post_end] << ' ';
			if (in_start == in_end || post_start == post_end) return;
			int left_offset = i - in_start - 1;
			int right_offset = in_end - i - 1;
			int lPost_end = post_start + left_offset;
			int rPost_start = lPost_end + 1;
			int rPost_end = rPost_start + right_offset;

			PreOrder(in_order, post_order, in_start, i-1, post_start, lPost_end);
			PreOrder(in_order, post_order, i + 1, in_end, rPost_start , rPost_end);
            break;
		}
	}
	
}

int main() {
    std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	int n;
	std::cin >> n;
	std::vector<int> in_order;
	std::vector<int> post_order;
	for (int i = 0; i < n; i++) {
		int temp;
		std::cin >> temp;
		in_order.push_back(temp);
	}
	
	for (int i = 0; i < n; i++) {
		int temp;
		std::cin >> temp;
		post_order.push_back(temp);
	}
	PreOrder(in_order, post_order, 0, n-1, 0, n - 1);
	return 0;
}
