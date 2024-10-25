#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const pair<int, int> moveDir[8] = { {-1,0}, {-1,-1}, {0,-1},{1,-1},{1,0},{1,1},{0,1},{-1,1} };
const pair<int, int> copyDir[4] = { {-1,-1},{-1,1},{1,-1},{1,1} };
int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> map(n);
	vector<vector<bool>> nextClouds(n);
	for (int i = 0; i < n; i++) {
		map[i].resize(n);
		nextClouds[i].resize(n, true);
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	queue<pair<int, int>> clouds;
	clouds.push({ 0 , n - 1 });
	clouds.push({ 1 , n - 1 });
	clouds.push({ 0 , n - 2 });
	clouds.push({ 1 , n - 2});
	vector<pair<int, int>> deletedClouds;
	for (int i = 0; i < m; i++) {
		int d, s;
		cin >> d >> s;
		while (!clouds.empty()) {
			auto cloud = clouds.front();
			clouds.pop();
			int new_col = (cloud.first + moveDir[d - 1].first * s) % n;;
			int new_row = (cloud.second + moveDir[d - 1].second * s) % n;
			if (new_col < 0) new_col += n;
			if (new_row < 0) new_row += n;
			map[new_row][new_col]++;
			deletedClouds.push_back({ new_col, new_row });
			nextClouds[new_row][new_col] = false;
		}
		for (auto copyCloud : deletedClouds) {
			int sum = 0;
			for (auto dir : copyDir) {
				int new_col = copyCloud.first + dir.first;
				int new_row = copyCloud.second + dir.second;
				if (new_col < 0 || new_col >= n || new_row < 0 || new_row >= n) continue;
				if (map[new_row][new_col] > 0) sum++;
			}
			map[copyCloud.second][copyCloud.first] += sum;
		}
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				if (map[j][k] >= 2 && nextClouds[j][k] == true) {
					map[j][k] -= 2;
					clouds.push({ k,j });
				}
				else if (nextClouds[j][k] == false) nextClouds[j][k] = true;
			}
		}
		deletedClouds.clear();
	}
	int result = 0;
	for (int j = 0; j < n; j++) {
		for (int k = 0; k < n; k++) {
			result += map[j][k];
		}
	}
	cout << result;

	return 0;
}


