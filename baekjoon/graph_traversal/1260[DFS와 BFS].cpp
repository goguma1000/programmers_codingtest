#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>
void BFS(const std::vector<std::vector<int>>& graph, std::vector<bool> visited, int root) {
	std::queue<int> idx_q;
	idx_q.push(root);
	while (!idx_q.empty()) {
		int node(idx_q.front());
		for (int c : graph[node]) {
			if (!visited[c]) {
				idx_q.push(c);
				visited[c] = true;
			}
		}
		std::cout << node << ' ';
		visited[node] = true;
		idx_q.pop();
	}
}
void DFS(const std::vector<std::vector<int>>& graph, std::vector<bool> visited, int root) {
	std::stack<int> idx_stack;
	idx_stack.push(root);
	while (!idx_stack.empty()) {
		int node(idx_stack.top());
		idx_stack.pop();
		if (visited[node]) continue;
		for (auto iter = graph[node].rbegin(); iter != graph[node].rend(); ++iter) {
			if (!visited[*iter]) {
				idx_stack.push(*iter);
			}
		}
		std::cout << node << ' ';
		visited[node] = true;
	}
}

int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	int n, k, root;
	std::cin >> n >> k >> root;
	std::vector<std::vector<int>> graph(n + 1);
	std::vector<bool> visited(n + 1);
	for (int i = 0; i < k; i++) {
		int n1, n2;
		std::cin >> n1>> n2;
		graph[n1].push_back(n2);
		graph[n2].push_back(n1);
	}
	for (int i = 1; i <= n; i++) {
		std::sort(graph[i].begin(), graph[i].end());
	}
	DFS(graph, visited, root);
	std::cout << '\n';
	BFS(graph, visited, root);
	return 0;
}
