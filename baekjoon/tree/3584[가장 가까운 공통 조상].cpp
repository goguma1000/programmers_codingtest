#include<iostream>
#include<stdio.h>
#include<vector>


int dfs(const std::vector<std::vector<int>>& children, const std::vector<int>& parent, const int target, const int idx){
	if (idx == target) return idx;
	int isFind = 0;
	for (int c: children[idx]) {
		isFind = dfs(children, parent, target, c);
		if (isFind != 0) break;
	}
	if (isFind != 0) return idx;
	else return 0;
}

int main() {
	int t;
	std::cin >> t;
	for (int l = 0; l < t; l++) {
		int n;
		std::cin >> n;
		std::vector<std::vector<int>> children(n + 1);
		std::vector<int> parent(n + 1);
		for (int i = 0; i < n - 1; i++) {
			int p, c;
			std::cin >> p >> c;
			children[p].push_back(c);
			parent[c] = p;
		}
		int start, target;
		int result = 0;
		std::cin >> start >> target;
		while (!result) {
			int temp = dfs(children, parent, target, start);
			start = parent[start];
			if (temp != 0) result = temp;
		}
		std::cout << result << "\n";
	}
}

//sol 2
/*
#include<iostream>
#include<stdio.h>
#include<vector>

int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	int t;
	std::cin >> t;
	for (int l = 0; l < t; l++) {
		int n;
		std::cin >> n;
		std::vector<int> parent(n + 1);
		std::vector<bool> visitied(n + 1);
		for (int i = 0; i < n - 1; i++) {
			int p, c;
			std::cin >> p >> c;
			parent[c] = p;
		}
		int node1, node2;
		std::cin >> node1 >> node2;
		while (true) {
			if (node1 == 0) break;
			visitied[node1] = true;
			node1 = parent[node1];
		}
		while (true) {
			if (visitied[node2]) {
				std::cout << node2 << "\n";
				break;
			}
			node2 = parent[node2];
		}
	}
}
*/
