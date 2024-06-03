#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>

int Post_Order_traversal(const std::vector<std::vector<std::pair<int, int>>>& tree, std::vector<int>& diameters, const int idx) {
	int diameter = 0;
	int first = 0;
	int second = 0;
	for (std::pair<int, int>p : tree[idx]) {
		int temp = Post_Order_traversal(tree, diameters, p.first);
		temp += p.second;
		if (temp > first) {
			second = first;
			first = temp;
		}
		else if (temp > second) second = temp;
	}
	diameter = first + second;
	diameters[idx] = diameter;
	return first;
}
int main() {
	int n;
	std::cin >> n;
	std::vector<std::vector<std::pair<int, int>>> tree(n);
	std::vector<int> diameters(n);
	for (int i = 0; i < n - 1; i++) {
		int p, c, w;
		std::cin >> p >> c >> w;
		tree[p - 1].push_back(std::make_pair(c - 1, w));
	}
	Post_Order_traversal(tree, diameters, 0);
	std::sort(diameters.begin(),diameters.end(), std::greater<int>());
	std::cout << diameters[0];
}
