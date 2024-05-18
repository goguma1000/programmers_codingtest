#include<iostream>
#include<stdio.h>
#include<vector>
#include<math.h>

void CompleteBinaryTree(const std::vector<int>& stream, std::vector<std::vector<int>>& tree,int depth, int start, int end) {
	
	int mid = (start + end) / 2;
	tree[depth].push_back(stream[mid]);
	if (start == end) return;
	CompleteBinaryTree(stream, tree, depth - 1, start, mid - 1);
	CompleteBinaryTree(stream, tree, depth - 1, mid + 1, end);
}
int main() {
	int k;
	std::cin >> k;
	std::vector<int> stream;
	std::vector<std::vector<int>> tree;
	tree.resize(k);
	int nodeNum = (int)pow(2, k);
	for (int i = 0; i < nodeNum-1; ++i) {
		int  temp;
		std::cin >> temp;
		stream.push_back(temp);
	}
	CompleteBinaryTree(stream, tree, k - 1, 0, nodeNum - 2);
	for (int i = k - 1; i  > -1; --i) {
		for (int j : tree[i]) {
			std::cout << j << " ";
		}
		std::cout << "\n";
	}
	return 0;
}
