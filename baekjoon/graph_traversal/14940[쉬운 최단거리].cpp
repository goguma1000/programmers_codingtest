#include<iostream>
#include<vector>
#include<queue>

int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	int n,m;
	std::cin >> n >> m;
	std::vector<std::vector<int>> map(n);
	std::vector<std::vector<int>> dist(n);
	std::vector<std::vector<bool>> visited(n);
	std::pair<int, int> targetIdx;
	for (int i = 0; i < n; i++) {
		map[i].resize(m);
		dist[i].resize(m);
		visited[i].resize(m);
		for (int j = 0; j < m; j++) {
			std::cin >> map[i][j];
			if (map[i][j] == 2) targetIdx = std::make_pair(i, j);
		}
	}
	std::queue<std::pair<int, int>> q;
	q.push(targetIdx);
	visited[targetIdx.first][targetIdx.second] = true;
	std::pair<int, int> dydx[4] = { {-1,0}, {0,1}, {1,0}, {0,-1} };
	while (!q.empty()) {
		auto node(q.front());
		q.pop();
		for (auto _dydx : dydx) {
			int newY = node.first + _dydx.first;
			int newX = node.second + _dydx.second;
			if (newY < 0 || newY >= n || newX < 0 || newX >= m) continue;
			if (map[newY][newX] == 1 && !visited[newY][newX]) {
				q.push(std::make_pair(newY, newX));
				dist[newY][newX] = dist[node.first][node.second] + 1;
				visited[newY][newX] = true;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (dist[i][j] == 0 && map[i][j] == 1) std::cout << -1 << ' ';
			else std::cout << dist[i][j] << ' ';
		}
		std::cout << '\n';
	}
	return 0;
}
