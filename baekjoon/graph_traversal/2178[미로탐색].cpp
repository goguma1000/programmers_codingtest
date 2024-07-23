#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<queue>
int BFS(const std::vector<std::vector<int>>& map, std::vector<std::vector<bool>>& visited, int y, int x) {
	std::pair<int, int> dxdy[4] = { {1,0},{0,1},{-1,0},{0,-1} };
	std::queue<std::pair<int, int>> q;
	std::queue<int> count_q;
	q.push(std::make_pair(0,0));
	count_q.push(1);
	visited[0][0] = true;
	while (!q.empty()) {
		std::pair<int, int> n(q.front());
		int count(count_q.front());
		q.pop();
		count_q.pop();
		for (int i = 0; i < 4; ++i) {
			int next_y(n.first + dxdy[i].first);
			int next_x(n.second + dxdy[i].second);
			if (next_y < 0 || next_y > y || next_x < 0 || next_x > x) continue;
			if (next_x == x && next_y == y) {
				return count + 1;
			}
			if (!visited[next_y][next_x] && map[next_y][next_x] == 1) {
				q.push(std::make_pair(next_y, next_x));
				count_q.push(count + 1);
				visited[next_y][next_x] = true;
			}
		}
	}
	return 0;
}

int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	int y, x;
	scanf("%d", &y);
	scanf("%d", &x);
	std::vector<std::vector<int>> map(y);
	std::vector<std::vector<bool>> visited(y);
	for (int i = 0; i < y; i++) {
		map[i].resize(x);
		visited[i].resize(x);
		for (int j = 0; j < x; j++) {
			scanf("%1d" ,&map[i][j]);
		}
	}
	std::cout << BFS(map, visited, y - 1,x - 1);
	return 0;
}
