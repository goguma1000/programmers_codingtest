#include<iostream>
#include<vector>
#include<math.h>
#include<queue>
int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	int N, L, R;
	std::cin >> N >> L >> R;
	std::vector<std::vector<int>> contries(N);
	std::vector<std::vector<bool>> visited(N);
	for (int i = 0; i < N; ++i) {
		contries[i].resize(N);
		visited[i].resize(N);
		for (int j = 0; j < N; ++j) {
			std::cin >> contries[i][j];
		}
	}
	std::pair<int, int> dydx[4] = { {-1,0}, {0,1}, {1,0}, {0,-1} };
	std::vector<std::pair<int, int>> united;
	std::queue<std::pair<int, int>> idx_Q;
	int day(0);
	while (true) {
		int changed(false);
		if (day != 0) for (int i = 0; i < N; i++)for (int j = 0; j < N; j++) visited[i][j] = false;
		for (int i = 0; i < N; ++i) for (int j = 0; j < N; j++) {
			if (visited[i][j]) continue;
			united.clear();
			int sum = contries[i][j];
			idx_Q.push({ i,j });
			united.push_back({ i,j });
			visited[i][j] = true;
			//bfs
			while (!idx_Q.empty()) {
				auto contry = idx_Q.front();
				idx_Q.pop();
				for (auto _dydx : dydx) {
					int newY = contry.first + _dydx.first;
					int newX = contry.second + _dydx.second;
					if (newY < 0 || newY >= N || newX < 0 || newX >= N) continue;
					int diff = std::abs(contries[contry.first][contry.second] - contries[newY][newX]);
					if (!visited[newY][newX] && (L <= diff && diff <= R)) {
						visited[newY][newX] = true;
						auto idx = std::pair<int, int>(newY, newX);
						united.push_back(idx);
						idx_Q.push(idx);
						sum += contries[newY][newX];
					}
				}
			}
			//re-set people num
			if (united.size() == 1) continue;
			int newNum(sum / united.size());
			for (auto memberIdx : united)contries[memberIdx.first][memberIdx.second] = newNum;
			changed = true;
		}
		if (!changed) break;
		++day;
	}
	std::cout << day;
	return 0;
}
