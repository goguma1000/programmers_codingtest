#include<iostream>
#include<vector>
#include<tuple>
#include<queue>
int map[100][100][100];
bool visited[100][100][100];
int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	int row, col, height;
	std::cin >> col >> row >> height;
	int unripedNum(0);
	int day(-1);
	std::queue<std::tuple<int,int, int>> tomatoIdx;
	for (int k = 0; k < height; k++) {
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				std::cin >> map[k][i][j];
				if (map[k][i][j] == 0) ++unripedNum;
				else if (map[k][i][j] == 1) tomatoIdx.push({ k,i,j });
			}
		}
	}
	if (unripedNum == 0) {
		std::cout << 0;
		return 0;
	}
	std::tuple<int, int, int> dhdydx[6] = { { 1,0,0 }, { -1,0,0 }, { 0,-1,0 }, { 0,0,1 }, { 0,1,0 }, { 0,0,-1 } };
	while (!tomatoIdx.empty()) {
		int lc = tomatoIdx.size();
		for (int i = 0; i < lc; ++i) {
			auto node(tomatoIdx.front());
			tomatoIdx.pop();
			for (auto  _dhdydx: dhdydx) {
				int newH = std::get<0>(node) + std::get<0>(_dhdydx);
				int newY = std::get<1>(node) + std::get<1>(_dhdydx);
				int newX = std::get<2>(node) + std::get<2>(_dhdydx);
				if (newH < 0 || newH >=  height || newY < 0 || newY >= row || newX < 0 || newX >= col) continue;
				if (map[newH][newY][newX] == 0 && !visited[newH][newY][newX]) {
					tomatoIdx.push(std::make_tuple(newH,newY, newX));
					visited[newH][newY][newX] = true;
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
