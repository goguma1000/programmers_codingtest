#include<iostream>
#include<stdio.h>
#include<vector>

void dfs(int& leafNum, const int deleteNode, const int node, const std::vector<std::vector<int>>& tree) {
	if (deleteNode == node) return;
	if (tree[node].empty() || (tree[node].size() == 1 && tree[node][0] == deleteNode)) {
		++leafNum;
		return;
	}
	for (int i : tree[node]) {
		dfs(leafNum, deleteNode, i, tree);
	}
}
int main() {
	std::vector<std::vector<int>> tree;
	int n = 0;
	int root = 0;
	std::cin >> n;
	tree.resize(n);
	for (int i = 0; i < n; i++) {
		int p = 0;
		std::cin >> p;
		if (p == -1) root = i;
		else tree[p].push_back(i);
	}
	int deletedNode = 0;
	std::cin >> deletedNode;
	int result = 0;
	dfs(result, deletedNode, root, tree);
	std::cout << result << "\n";
	return 0;
}
