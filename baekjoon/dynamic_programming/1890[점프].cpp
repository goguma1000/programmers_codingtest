#include<iostream>
#include<vector>
uint64_t GetPathCount(const std::vector<std::vector<int>>& map,const std::vector<std::vector<uint64_t>>& sol,int row, int col) {
	int step = map[row][col];
	if (step == 0) {
		if (row == map.size() - 1 && col == map.size() - 1) return 1;
		else return 0;
	}
	uint64_t temp = 0;
	if (col + step < map.size()) temp += sol[row][col + step];
	if (row + step < map.size()) temp += sol[row + step][col];
	return temp;
}
int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	
	int n;
	std::cin >> n;
	std::vector<std::vector<int>> map(n);
	std::vector<std::vector<uint64_t>> sol(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int temp;
			std::cin >> temp;
			map[i].push_back(temp);
			sol[i].push_back(0);
		}
	}
	sol[n - 1][n - 1] = 1;
	for (int y = n - 1; y > - 1; y--) {
		for (int x = y; x  >  -1; x--) {
			sol[y][x] = GetPathCount(map, sol, y, x);
			if(x != y) sol[x][y] = GetPathCount(map, sol, x, y);
		}
	}
	std::cout << sol[0][0];
	return 0;
}
