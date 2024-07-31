#include<iostream>
#include<vector>

int dfs(const std::vector<std::vector<int>>& graph, std::vector<bool>& visited, int cur, int prev, int depth) {
	if (depth == 4) return 1;
	for (int next : graph[cur]) {
		if (!visited[next]) {
			visited[next] = true;
			if (dfs(graph, visited, next, cur, depth + 1) == 1) return 1;
			visited[next] = false;
		}
	}
	return 0;
}
int main() {
	int N, M;
	std::cin >> N >> M;
	std::vector<std::vector<int>> graph(N + 1);
	for (int i = 0; i < M; i++) {
		int c1, c2;
		std::cin >> c1 >> c2;
		graph[c1].push_back(c2);
		graph[c2].push_back(c1);
	}
	int result(0);
	for (int i = 0; i < N; i++) {
		std::vector<bool> visited(N + 1);
		visited[i] = true;
		if (dfs(graph, visited, i, -1, 0) == 1) {
			result = 1;  break;
		}
	}
	std::cout << result;
	return 0;
}
