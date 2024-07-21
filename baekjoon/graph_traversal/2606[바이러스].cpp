#include<iostream>
#include<vector>
#include<queue>
int BFS(const std::vector<std::vector<int>>& graph, std::vector<bool>& visited, int root) {
	int result = 0;
	std::queue<int> idx_q;
	idx_q.push(root);
	while (!idx_q.empty()) {
		int node(idx_q.front());
		for (int c : graph[node]) {
			if (!visited[c]) {
				idx_q.push(c);
				visited[c] = true;
				result++;
			}
		}
		visited[node] = true;
		idx_q.pop();
	}
	return result;
}
int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	int n, k;
	std::cin >> n >> k;
	std::vector<std::vector<int>> graph(n + 1);
	std::vector<bool> visited(n + 1);
	for (int i = 0; i < k; i++) {
		int n1, n2;
		std::cin >> n1>> n2;
		graph[n1].push_back(n2);
		graph[n2].push_back(n1);
	}
	std::cout << BFS(graph, visited, 1);
	return 0;
}
