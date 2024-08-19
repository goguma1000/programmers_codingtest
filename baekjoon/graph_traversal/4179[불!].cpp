#include<iostream>
#include<vector>
#include<string>
#include<queue>
using namespace std;



int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	int row, col;
	string temp;
	cin >> row >> col;
	getline(cin, temp);
	vector<vector<char>> map(row);
	vector<vector<bool>> visited(row);
	queue<pair<int, int>> player_pos;
	queue<pair<int, int>> fire_pos;
	for (int i = 0; i < row; ++i) {
		visited[i].resize(col);
		getline(cin, temp);
		for (int j = 0; j < temp.length(); ++j) {
			map[i].push_back(temp[j]);
			if (temp[j] == 'J') player_pos.push({ i,j });
			else if (temp[j] == 'F') fire_pos.push({ i,j });
		}
	}
	visited[player_pos.front().first][player_pos.front().second] = true;
	bool escape(false);
	int step(0);
	pair<int, int> dydx[4] = { {-1,0},{0,1}, {1,0}, {0,-1} };
	while (!player_pos.empty()) {
		int lc = player_pos.size();
		for (int i = 0; i < lc; ++i) {
			auto pPos = player_pos.front();
			player_pos.pop();
			if (map[pPos.first][pPos.second] == 'F') continue;
			for (const auto& _dydx : dydx) {
				int newY = pPos.first + _dydx.first;
				int newX = pPos.second + _dydx.second;
				if (newY < 0 || newY >= row || newX < 0 || newX >= col) {
					escape = true;
					break;
				}
				if (map[newY][newX] == '.' && !visited[newY][newX]) {
					visited[newY][newX] = true;
					player_pos.push({ newY, newX });
				}
			}
		}
		step++;
		if (escape) break;
		lc = fire_pos.size();
		for (int i = 0; i < lc; ++i) {
			auto fPos = fire_pos.front();
			fire_pos.pop();
			for (const auto& _dydx : dydx) {
				int newY = fPos.first + _dydx.first;
				int newX = fPos.second + _dydx.second;
				if (newY < 0 || newY >= row || newX < 0 || newX >= col) continue;
				if (map[newY][newX] != '#' && map[newY][newX] != 'F') {
					fire_pos.push({ newY, newX });
					map[newY][newX] = 'F';
				}
			}
		}
	}
	if (escape) cout << step;
	else cout << "IMPOSSIBLE";
	return 0;
}
