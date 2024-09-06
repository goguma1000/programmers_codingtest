#include <iostream>
#include <vector>

using namespace std;
void printArr(const vector<vector<int>>& map) {
	for (int i = 0; i < map.size(); i++) {
		for (int j = 0; j < map[i].size(); j++) {
			cout << map[i][j] << ' ';
		}
		cout << '\n';
	}
}
int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n, deg;
		cin >> n >> deg;
		vector<vector<int>>map;
		for (int j = 0; j < n; j++) {
			map.push_back(vector<int>());
			for (int k = 0; k < n; k++) {
				int temp;
				cin >> temp;
				map[j].push_back(temp);
			}
		}
		if (deg % 360 == 0) {
			printArr(map);
			continue;
		}
		vector<vector<int>> copy = map;
		int dir(1);
		if (deg < 0) {
			deg *= -1;
			dir = -1;
		}
		int step = deg / 45;
		int center = n / 2;
		const pair<int, int> dydx[8] = { {-1,-1}, {-1,0}, {-1,1}, {0,1},{1,1},{1,0}, {1,-1}, {0,-1} };
		vector<vector<pair<int, int>>> movingComponents(center);
		for (int j = 0; j < center; j++) {
			for (int k = 0; k < 8; k++) {
				movingComponents[j].push_back({ center + (j + 1) * dydx[k].first, center + (j + 1) * dydx[k].second });
			}
		}
		for (int j = 0; j < center; j++) {
			for (int k = 0; k < 8; k++) {
				int dstK = k + dir * step;
				if (dstK < 0) dstK += 8;
				else dstK %= 8;
				int y = movingComponents[j][k].first;
				int x = movingComponents[j][k].second;
				int dstY = movingComponents[j][dstK].first;
				int dstX = movingComponents[j][dstK].second;
				copy[dstY][dstX] = map[y][x];
			}
		}
		printArr(copy);
	}
	return 0;
}
