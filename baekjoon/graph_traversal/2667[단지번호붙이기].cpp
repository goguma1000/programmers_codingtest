#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
int BFS(const std::vector<std::vector<int>>& map, std::vector<std::vector<bool>>& visitied, int y, int x, int& visitCount) {
	std::pair<int, int> dydx[4] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
	std::queue<std::pair<int, int>> q;
	visitied[y][x] = true;
	q.push(std::make_pair(y, x));
	int result = 1;
	while (!q.empty()) {
		std::pair<int, int> n(q.front());
		q.pop();
		for (int i = 0; i < 4; ++i) {
			int newY = n.first + dydx[i].first;
			int newX = n.second + dydx[i].second;
			if (newY < 0 || newY >= map.size() || newX < 0 || newX >= map.size())continue;
			if (map[newY][newX] && !visitied[newY][newX]) {
				q.push(std::make_pair(newY, newX));
				visitied[newY][newX] = true;
				++result;
				++visitCount;
			}
		}
	}
	return result;
}
int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	int n, visitCount(0);
	scanf("%d", &n);
	std::vector<std::vector<int>> map(n);
	std::vector<std::vector<bool>> visited(n);
	for (int i = 0; i < n; i++) {
		map[i].resize(n);
		visited[i].resize(n);
		for (int j = 0; j < n; j++) {
			int temp;
			scanf("%1d",&temp);
			if (!temp) {
				visited[i][j] = true;
				++visitCount;
			}
			map[i][j] = temp;
		}
	}
	std::vector<int> result;
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
		if (visitCount == n * n) break;
		if (map[i][j] && !visited[i][j]) {
			result.push_back(BFS(map, visited, i, j, visitCount));
		}
	}
	std::sort(result.begin(), result.end());
	std::cout << result.size() << '\n';
	if (result.size() == 0) std::cout << 0;
	else {
		for (int r : result) std::cout << r <<'\n';
	}
	return 0;
}
