#include<iostream>
#include<stdio.h>
#include<vector>

struct Node {
	char left;
	char right;

	Node() {
		left = '\0';
		right = '\0';
	}
};
void Pre_Order_Traversal(const std::vector<Node>& tree, char idx) {
	if (idx == '.' - 'A') return;
	printf("%c", idx + 'A');
	Pre_Order_Traversal(tree,tree[idx].left - 'A');
	Pre_Order_Traversal(tree,tree[idx].right - 'A');
}
void In_Order_Traversal(const std::vector<Node>& tree, int idx) {
	if (idx == '.' - 'A') return;
	In_Order_Traversal(tree, tree[idx].left - 'A');
	printf("%c", idx + 'A');
	In_Order_Traversal(tree, tree[idx].right - 'A');
}
void Post_Order_Traversal(const std::vector<Node>& tree, int idx) {
	if (idx == '.' - 'A') return;
	Post_Order_Traversal(tree, tree[idx].left - 'A');
	Post_Order_Traversal(tree, tree[idx].right - 'A');
	printf("%c", idx + 'A');
}

void main() {
	int nodeNum = 0;
	std::vector<Node> tree;
	std::cin >> nodeNum;

	tree.resize(nodeNum);

	for (int i = 0; i < nodeNum; ++i) {
		char left, mid, right;
		std::cin >> mid >> left >> right;
		tree[mid - 'A'].left = left;
		tree[mid - 'A'].right = right;
	}

	Pre_Order_Traversal(tree,0);
	std::cout << std::endl;
	In_Order_Traversal(tree, 0);
	std::cout << std::endl;
	Post_Order_Traversal(tree, 0);
	std::cout << std::endl;
}
