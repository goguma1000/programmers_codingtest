#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>

void InOrder(const std::vector<std::vector<int>>& tree, std::vector<std::vector<int>>& map,int idx ,int depth, int* count) {
	if (map.size() == depth) map.push_back(std::vector<int>());
	int left = tree[idx][0];
	int right = tree[idx][1];
	if(left > 0) InOrder(tree, map, left,depth + 1, count);
	map[depth].push_back(*count);
	*count = *count + 1;
	if (right > 0) InOrder(tree, map, right, depth + 1, count);
}

int main() {
	int n;
	std::cin >> n;
	std::vector<std::vector<int>> tree(n + 1);
	std::vector<int> parent(n + 1);
	std::vector <std::vector<int>> map;

	for (int i = 0; i < n; i++) {
		int node, left, right;
		std::cin >> node >> left >> right;
		tree[node].push_back(left);
		tree[node].push_back(right);
		if (left != -1) parent[left] = node;
		if (right != -1) parent[right] = node;
	}

	int root = 1;
	for (int i = 1; i < parent.size(); i++) {
		if (parent[i] == 0) {
			root = i;
			break;
		}
	}

	int count = 1;
	InOrder(tree, map,root, 0, &count);
	int level = 0;
	int width = 0;
	for (int i = 0; i < map.size(); i++) {
		int temp = map[i].back() - map[i].front() + 1;
		if (temp > width) {
			width = temp;
			level = i + 1;
		}
	}
	std::cout << level << " " << width;
	return 0;
}
