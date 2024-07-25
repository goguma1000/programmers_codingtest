#include<iostream>
#include<vector>
#include<queue>
void printMap(const std::vector<std::vector<char>>& map, int R, int C) {
	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			std::cout << map[i][j];
		}
		std::cout << '\n';
	}
}
int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	int R, C, N;
	std::cin >> R >> C >> N;
	std::vector<std::vector<char>> map(R);
	std::pair<int, int> dydx[4] = { {-1,0}, {0,1},{1,0}, {0,-1} };
	for (int i = 0; i < R; ++i) {
		map[i].resize(C);
		for (int j = 0; j < C; ++j) {
			char temp;
			std::cin >> temp;
			map[i][j] = temp;
		}
	}
	if (N == 1) {
		printMap(map, R, C);
		return 0;
	}
	std::queue<std::pair<int, int>>bomb_idx;
	for (int i = 2; i <= N; ++i) {
		if (i % 2 == 0) {
			for (int i = 0; i < R; ++i)for (int j = 0; j < C; ++j) {
				if (map[i][j] == 'O')bomb_idx.push(std::make_pair(i, j));
				else map[i][j] = 'O';
			}
		}
		else {
			while(!bomb_idx.empty()){
				auto idx = bomb_idx.front();
				bomb_idx.pop();
				map[idx.first][idx.second] = '.';
				for (int k = 0; k < 4; k++) {
					int newY = idx.first + dydx[k].first;
					int newX = idx.second + dydx[k].second;
					if (newY < 0 || newY >= R || newX < 0 || newX >= C) continue;
					if (map[newY][newX] == 'O') map[newY][newX] = '.';

				} 
			}
		}
	}
	printMap(map, R, C);
	return 0;
}
