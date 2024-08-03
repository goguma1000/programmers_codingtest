#include<iostream>
#include<vector>
#include<queue>
const std::pair<int, int> dxdy[2][6] = {
	{{-1,0}, {1,0}, {-1,-1}, {0,-1},{-1,1},{0,1}},
	{{-1,0},{1,0},{0,-1},{1,-1},{0,1},{1,1}}
};

int map[102][102] = { 0, };
bool visited[102][102] = { false, };
void zero_BFS(int x, int y, int width, int height) {
	//painting
	std::queue<std::pair<int, int>> q;
	std::queue<std::pair<int, int>> connNodes;
	bool findPath(false);
	q.push({ x,y });
	while (!q.empty()) {
		auto node(q.front());
		q.pop();
		connNodes.push(node);
		for (auto _dxdy : dxdy[node.second % 2]) {
			int newX = node.first + _dxdy.first;
			int newY = node.second + _dxdy.second;
			if (newX < 1 || newX > width || newY < 1 || newY > height) {
				findPath = true;
				continue;
			}
			if (!visited[newY][newX] && map[newY][newX] == 0) {
				q.push({ newX,newY });
				visited[newY][newX] = true;
			}
		
		}
	}
	if (!findPath) {
		while (!connNodes.empty()) {
			map[connNodes.front().second][connNodes.front().first] = 2;
			connNodes.pop();
		}
	}
}

void one_BFS(std::vector<std::vector<std::pair<int, int>>>& connComp,int x, int y, int widht, int height) {
	connComp.push_back(std::vector<std::pair<int, int>>());
	int curIdx = connComp.size() - 1;
	std::queue<std::pair<int, int>> q;
	q.push({ x,y });
	visited[y][x] = true;
	while (!q.empty()) {
		auto node(q.front());
		q.pop();
		connComp[curIdx].push_back(node);
		for (auto _dxdy : dxdy[node.second % 2]) {
			int newX = node.first + _dxdy.first;
			int newY = node.second + _dxdy.second;
			if (!visited[newY][newX] && map[newY][newX] == 1) {
				q.push({ newX,newY });
				visited[newY][newX] = true;
			}
		}
	}
}
int main() {
	int width, height;
	std::cin >> width >> height;
	for (int i = 1; i <= height; ++i) for (int j = 1; j <= width; ++j) {
		std::cin >> map[i][j];
	}
	std::vector<std::vector<std::pair<int,int>>> connComp;
	for (int i = 1; i <= height; ++i) for (int j = 1; j <= width; ++j) {
		if (!visited[i][j]) {
			if (map[i][j] == 0) {
				zero_BFS(j, i, width, height);
			}
			else if (map[i][j] == 1) {
				one_BFS(connComp, j, i, width, height);
			}
		}
	}
	int result(0);
	for (int i = 0; i < connComp.size(); ++i) {
		for (auto node : connComp[i]) {
			for (auto _dxdy : dxdy[node.second % 2]) {
				int newX = node.first + _dxdy.first;
				int newY = node.second + _dxdy.second;
				if (map[newY][newX] == 0) {
					result++;
				}
			}
		}
	}
	std::cout << result;
	return 0;
}
