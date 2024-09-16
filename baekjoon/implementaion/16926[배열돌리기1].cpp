#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, m, r;
	cin >> n >> m >> r;
	vector<vector<int>> map(n);
	for (int i = 0; i < n; i++) {
		map[i].resize(m);
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	vector<vector<pair<int, int>>> rotationSet;
	int level = 0;
	int i = 0, j = 0;
	while (level <= n - 1 - level && level <= m - 1 -level) {
		rotationSet.push_back(vector< pair<int, int>>());
		while (true) {
			rotationSet[level].push_back({ i,j });
			if ((level != n - 1 - level && i == level && j == level + 1) || (level == n-1-level && j == m - 1- level) || (level == m - 1 - level && i == n - 1 - level)) {
				i = level + 1;
				break;
			}
			if (i < n - 1 - level && j == level) {
				++i;
			}
			else if (i == n - 1 - level && j < m - 1 - level) {
				++j;
			}
			else if (j == m - 1 - level && i > level) {
				--i;
			}
			else if (i == level && j > level) {
				--j;
			}
		}
		level++;
	}
	vector<vector<int>> copy_map = map;
	for (int i = 0; i < rotationSet.size(); i++) {
		for (int j = 0; j < rotationSet[i].size(); j++) {
			if ((j + r) % rotationSet[i].size() == j) break;
			int next = (j + r) % rotationSet[i].size();
			map[rotationSet[i][next].first][rotationSet[i][next].second] = copy_map[rotationSet[i][j].first][rotationSet[i][j].second];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << map[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}
