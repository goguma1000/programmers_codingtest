#include<iostream>
#include<vector>
#include<queue>

int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	int row, col;
	std::cin >> col >> row;
	std::vector<std::vector<int>> map(row);
	std::vector<std::vector<bool>> visited(row);
	int unripedNum(0);
	int day(-1);
	std::queue<std::pair<int,int>> tomatoIdx;
	for (int i = 0; i < row; i++) {
		map[i].resize(col);
		visited[i].resize(col);
		for (int j = 0; j < col; j++) {
			std::cin >> map[i][j];
			if (map[i][j] == 0) ++unripedNum;
			else if (map[i][j] == 1) tomatoIdx.push({ i,j });
		}
	}
	if (unripedNum == 0) {
		std::cout << 0;
		return 0;
	}
	std::pair<int, int> dydx[4] = { {-1,0}, {0,1}, {1,0}, {0,-1} };
	while (!tomatoIdx.empty()) {
		int lc = tomatoIdx.size();
		for (int i = 0; i < lc; ++i) {
			auto node(tomatoIdx.front());
			tomatoIdx.pop();
			for (auto _dydx : dydx) {
				int newY = node.first + _dydx.first;
				int newX = node.second + _dydx.second;
				if (newY < 0 || newY >= row || newX < 0 || newX >= col) continue;
				if (map[newY][newX] == 0 && !visited[newY][newX]) {
					tomatoIdx.push(std::make_pair(newY, newX));
					visited[newY][newX] = true;
					--unripedNum;
				}
			}
		}
		++day;
	}
	if (unripedNum > 0) std::cout << -1;
	else std::cout << day;
	return 0;
}
