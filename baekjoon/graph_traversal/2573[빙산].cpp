#include<iostream>
#include<vector>
#include<list>
#include<queue>
using namespace std;



int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	int row, col;
	bool flipflop = false;
	cin >> row >> col;
	vector<vector<int>> map(row);
	vector<vector<int>> visited(row);
	list<pair<int, int>> ice_pos;
	for (int i = 0; i < row; ++i) {
		visited[i].resize(col);
		for (int j = 0; j < col; ++j) {
			int temp;
			cin >> temp;
			if (temp == 0) --temp;
			else ice_pos.push_back({ i,j });
			map[i].push_back(temp);
		}
	}
	
	pair<int, int> dydx[4] = { {-1,0}, {1,0}, {0,-1}, {0,1} };
	int year(0);
	while (true) {
		queue<pair<int, int>> q;
		auto itor = ice_pos.begin();
		while(itor != ice_pos.end()){
			const auto& pos = *itor;
			for (const auto& _dydx : dydx) {
				int newY = pos.first + _dydx.first;
				int newX = pos.second + _dydx.second;
				if (newY < 0 || newY >= row || newX < 0 || newX >= col) continue;
				if (map[newY][newX] < 1) {
					map[pos.first][pos.second] += map[newY][newX];
					if (map[pos.first][pos.second] == 0) break;
				}
			}
			if (map[pos.first][pos.second] == 0) {
				q.push(pos);
				itor = ice_pos.erase(itor);
			}
			else ++itor;
		}
		++year;
		while (!q.empty()) {
			map[q.front().first][q.front().second] = -1;
			q.pop();
		}
		int groupCount(0);
		for (const auto& pos : ice_pos) {
			if (visited[pos.first][pos.second] != flipflop) continue;
			q.push(pos);
			visited[pos.first][pos.second] = !visited[pos.first][pos.second];
			while (!q.empty()) {
				auto temp = q.front();
				q.pop();
				for (const auto& _dydx : dydx) {
					int newY = temp.first + _dydx.first;
					int newX = temp.second + _dydx.second;
					if (newY < 0 || newY >= row || newX < 0 || newX >= col) continue;
					if (map[newY][newX] >= 1 && visited[newY][newX] == flipflop) {
						q.push({ newY,newX });
						visited[newY][newX] = !visited[newY][newX];
					}
				}
			}
			++groupCount;
		}
		if (groupCount > 1) {
			cout << year;
			break;
		}
		else if (groupCount == 0) {
			cout << 0;
			break;
		}
		flipflop = !flipflop;
	}
	return 0;
}
