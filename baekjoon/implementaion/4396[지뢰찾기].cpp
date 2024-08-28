#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<vector<char>> map(n);
	for (int i = 0; i < n; ++i) {
		map[i].resize(n);
		for (int j = 0; j < n; ++j) {
			cin >> map[i][j];
		}
	}
	const pair<int, int> dirs[8] = { {-1,0}, {-1,1}, {0,1}, {1,1}, {1,0}, {1,-1}, {0,-1}, {-1,-1} };
	bool onMine = false;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			int count(0);
			char temp;
			cin >> temp;
			if (temp == '.') continue;
			if (temp == 'x' && map[i][j] == '*') {
				onMine = true;
				continue;
			}
			for (const auto& dir : dirs) {
				int newY = i + dir.first;
				int newX = j + dir.second;
				if (newY < 0 || newY >= n || newX < 0 || newX >= n) continue;
				if (map[newY][newX] == '*') ++count;
			}
			map[i][j] = count + '0';
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (onMine) cout << map[i][j];
			else {
				if (map[i][j] == '*') cout << '.';
				else cout << map[i][j];
			}
		}
		cout << '\n';
	}
	return 0;
}
