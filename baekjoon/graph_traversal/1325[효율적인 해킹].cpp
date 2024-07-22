#include<iostream>
#include<vector>
#include<queue>
int BFS(const std::vector<std::vector<int>>& graph, std::vector<bool> visited, int root) {
	visited[root] = true;
	int sum(0);
	std::queue<int> q;
	q.push(root);
	while (!q.empty()) {
		int n(q.front());
		q.pop();
		for (int c : graph[n]) {
			if (!visited[c]) {
				visited[c] = true;
				q.push(c);
				sum++;
			}
		}
	}
	return sum;
}

int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	int n, m;
	std::cin >> n >> m;
	std::vector<std::vector<int>> graph(n + 1);
	std::vector<bool> visited(n + 1);
	std::vector<int> connNum(n + 1);
	for (int i = 0; i < m; i++) {
		int c, p;
		std::cin >> c >> p;
		graph[p].push_back(c);
	}
	int max(0);
	for(int i = 1; i <= n; ++i){
		connNum[i] = BFS(graph, visited, i);
		max = max < connNum[i] ? connNum[i] : max;
	}
	for (int i = 1; i <= n; ++i) {
		if (connNum[i] == max) std::cout << i << ' ';
	}
	return 0;
}
