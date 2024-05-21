#include<iostream>
#include<stdio.h>
#include<vector>
#include<queue>
void bfs(const std::vector<std::vector<int>>& graph, std::vector<int>& tree ,std::vector<bool>& visited, std::queue<int>& q) {
	if (q.empty())return;
	int idx = q.front();
	
	for (int i : graph[idx - 1]) {
		if (!visited[i - 1]) {
			tree[i - 1] = idx;
			visited[i - 1] = true;
			q.push(i);
		}
	}

	q.pop();
	bfs(graph, tree, visited, q);
}

int main() {
	const int root = 1;
	int n = 0;
	std::vector<std::vector<int>> graph;
	std::vector<int> tree;
	std::cin >> n;

	graph.resize(n);
	tree.resize(n);
	for (int i = 0; i < n-1; ++i) {
		int node1, node2;
		std::cin >> node1 >> node2;
		graph[node1 - 1].push_back(node2);
		graph[node2 - 1].push_back(node1);
	}
	std::queue<int> queue;
	std::vector<bool>visited = std::vector<bool>(n);
	queue.push(1);
	visited[0] = true;
	bfs(graph, tree, visited, queue);
	for (int i = 1; i < n; ++i) {
		std::cout << tree[i] << "\n";
	}
	return 0;
}
