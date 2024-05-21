#include<iostream>
#include<stdio.h>
#include<vector>

//tree는 연결되어있는 node가 2개이상이면 단절점이다.
//tree의 모든 edge는 단절선이다.
int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	int n = 0;
	std::vector<std::vector<int>> graph;
	std::cin >> n;
	graph.resize(n + 1);
	for (int i = 0; i < n - 1; i++) {
		int node1, node2;
		std::cin >> node1 >> node2;
		graph[node1].push_back(node2);
		graph[node2].push_back(node1);
	}
	int q = 0;
	std::cin >> q;
	for (int i = 0; i < q; i++) {
		int t = 0;
		int target = 0;
		std::cin >> t >> target;
		if (t == 1) {
			if(graph[target].size() > 1) std::cout << "yes\n";
			else std::cout << "no\n";
		}
		else {
			std::cout << "yes\n";
		}
	}
	return 0;
}
