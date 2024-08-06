#include<iostream>
#include<vector>
#include<queue>

std::pair<int, int> dydx[4]={ {-1,0}, {0,1}, {1,0}, {0,-1} };
void GetAllCombination(std::vector<std::vector<int>>& result, const std::vector<std::pair<int,int>>& zeroIdx) {
	for (int i = 0; i < zeroIdx.size() - 2; ++i) {
		for (int j = i + 1; j < zeroIdx.size() - 1; ++j) {
			for (int k = j + 1; k < zeroIdx.size(); k++) {
				result.push_back(std::vector<int>());
				result[result.size()-1].push_back(i);
				result[result.size()-1].push_back(j);
				result[result.size()-1].push_back(k);
			}
		}
	}
}
void resetVisited(std::vector<std::vector<bool>>& visited) {
	for (int i = 0; i < visited.size(); ++i) for (int j = 0; j < visited[i].size(); ++j)
		visited[i][j] = 0;
}

int BFS(const std::vector<std::vector<int>>& map, std::vector<std::vector<bool>>& visited, const std::vector<std::pair<int,int>>& twoIdx) {
	int result(0);
	std::queue<std::pair<int, int>> q;
	for (auto idx : twoIdx) q.push(idx);
	while (!q.empty()) {
		auto cur = q.front();
		q.pop();
		for (auto _dydx : dydx) {
			int newY = cur.first + _dydx.first;
			int newX = cur.second + _dydx.second;
			if (newY < 0 || newY >= map.size() || newX < 0 || newX >= map[0].size()) continue;
			if (!visited[newY][newX] && map[newY][newX] == 0) {
				q.push({ newY,newX });
				++result;
				visited[newY][newX] = true;
			}
		}
	}
	return result;

}
int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	int n, m;
	std::cin >> n >> m;
	std::vector<std::vector<int>> map(n);
	std::vector<std::vector<bool>> visited(n);
	std::vector<std::pair<int, int>> zeroIdx;
	std::vector<std::pair<int, int>> twoIdx;

	for (int i = 0; i < n; i++) {
		map[i].resize(m);
		visited[i].resize(m);
		for (int j = 0; j < m; j++) {
			std::cin >> map[i][j];
			if (map[i][j] == 0) zeroIdx.push_back({ i,j });
			else if (map[i][j] == 2) twoIdx.push_back({ i,j });
		}
	}
	int zeroNum(zeroIdx.size());
	std::vector<std::vector<int>> indices;
	GetAllCombination(indices, zeroIdx);
	int max(0);
	for (std::vector<int> idx : indices) {
		for (int i = 0; i < 3; ++i) {
			map[zeroIdx[idx[i]].first][zeroIdx[idx[i]].second] = 1;
		}
		int temp = BFS(map, visited, twoIdx);
		temp = zeroNum - temp - 3;
		max = max > temp ? max : temp;
		for (int i = 0; i < 3; ++i) {
			map[zeroIdx[idx[i]].first][zeroIdx[idx[i]].second] = 0;
		}
		resetVisited(visited);
	}
	std::cout << max;
	return 0;
}
