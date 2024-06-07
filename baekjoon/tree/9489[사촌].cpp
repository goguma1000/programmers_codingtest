#include<iostream>
#include<stdio.h>
#include<vector>
#include<queue>

struct node {
	int parent;
	std::vector<int>children;
	node(int p) :parent(p) {};
};

int main() {
	
	int n, k;
	while (true) {
		std::vector<node>tree;
		std::cin >> n >> k;
		if (n == 0 && k == 0) break;
		int prev = -1;
		int pIdx = 0;
		int k_idx = 0;
		std::cin >> prev;
		std::queue<int> queue;
		tree.push_back(node(-1));
		queue.push(pIdx);
		for (int i = 0; i < n - 1; i++) {
			int cur;
			std::cin >> cur;
			if (cur - prev > 1) {
				pIdx = queue.front();
				queue.pop();
			}
			node tempNode(pIdx);
			tree.push_back(tempNode);
			int cur_idx = tree.size() - 1;
			if (cur == k) k_idx = cur_idx;
			queue.push(cur_idx);
			tree[pIdx].children.push_back(cur_idx);
			prev = cur;
		}
		int result = 0;
		int k_parent = tree[k_idx].parent;
		if (k_parent != -1 && tree[k_parent].parent != -1) {
			for (int c : tree[tree[k_parent].parent].children) {
				if (c != k_parent) result += tree[c].children.size();
			}
		}
		std::cout << result << "\n";
	}
	return 0;
}
