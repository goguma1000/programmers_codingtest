#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;
const pair<int, int> dirs[9]{ {-1,0}, {-1,1}, {0,1}, {1,1}, {1,0}, {1,-1}, {0,-1}, {-1,-1}, {0,0} };
int dfs(char (&map)[8][8], vector<pair<int,int>>& wall_inddices, pair<int,int> pos) {
	if (map[pos.first][pos.second] == '#') {
		return 0;
	}
	if (pos.first == 0 && pos.second == 7) return 1;
	stack < pair<int, int>> positions;
	//moving
	for (const auto& dir : dirs) {
		int newY = pos.first + dir.first;
		int newX = pos.second + dir.second;
		if (newY < 0 || newY >= 8 || newX < 0 || newX >= 8) continue;
		if (map[newY][newX] == '.') positions.push({ newY,newX });
	}
	//wall moviing
	int deletedWallNum(0);
	for (auto& wall : wall_inddices) {
		if(0 <= wall.first && wall.first < 8 && 0 <= wall.second && wall.second < 8) map[wall.first][wall.second] = '.';
		++wall.first;
	}
	for (auto& wall : wall_inddices) {
		if (wall.first >= 8) ++deletedWallNum;
		else if (0 <= wall.second && wall.second < 8) map[wall.first][wall.second] = '#';
	}

	if (deletedWallNum == wall_inddices.size()) return 1;

	while (!positions.empty()) {
		int result = dfs(map, wall_inddices, positions.top());
		positions.pop();
		if (result == 1) return 1;
	}

	for (auto& wall : wall_inddices) {
		if ((0 <= wall.first && wall.first < 8 )&& (0 <= wall.second && wall.second < 8)) map[wall.first][wall.second] = '.';
		--wall.first;
	}
	for (auto& wall : wall_inddices) {
		if ((0 <= wall.first && wall.first < 8) && (0 <= wall.second && wall.second < 8)) map[wall.first][wall.second] = '#';
	}
	return 0;
}
int main() {
	char map[8][8];
	vector<pair<int, int>> wall_idices;
	for (int i = 0; i < 8; ++i){
		string temp;
		cin >> temp;
		for (int j = 0; j < 8; ++j) {
			map[i][j] = temp[j];
			if (temp[j] == '#') wall_idices.push_back({ i,j });
		}
	}
	int result;
	if (wall_idices.size() == 0)result = 1;
	else result = dfs(map, wall_idices ,{ 7,0 });
	cout << result;
	return 0;
}
