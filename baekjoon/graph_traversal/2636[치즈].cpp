#include<iostream>
#include<vector>
#include<queue>
using namespace std;
pair<int, int> dydx[4] = { {-1,0}, {0,1}, {1,0}, {0,-1} };

void BFS(vector<vector<int>>& map, vector<vector<bool>>& visited) {
	queue<pair<int, int>> q;
	vector<pair<int, int>> meltedChese_Q;
	q.push({ 0,0 });
	visited[0][0] = true;
	int hour(0);
	int prev(0);
	while(true){
		prev = meltedChese_Q.size();
		meltedChese_Q.clear();
		while (!q.empty()) {
			auto pos = q.front();
			q.pop();
			for (auto _dydx : dydx) {
				int newY = pos.first + _dydx.first;
				int newX = pos.second + _dydx.second;
				if (newY < 0 || newY >= map.size() || newX < 0 || newX >= map[0].size()) continue;
				if (!visited[newY][newX]) {
					if (map[newY][newX] == 0) {
						q.push({ newY,newX });
					}
					else {
						meltedChese_Q.push_back({ newY,newX });
					}
					visited[newY][newX] = true;
				}
			}
		}
		if (meltedChese_Q.size() == 0) {
			cout << hour << '\n' << prev;
			break;
		}
		++hour;
		for (auto temp : meltedChese_Q) q.push(temp);
	}
	return;
}
int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	int row, col;
	cin >> row >> col;
	vector<vector<int>> map(row);
	vector<vector<bool>> visited(row);
	int cheseCount(0);
	for (int i = 0; i < row; ++i) {
		map[i].resize(col);
		visited[i].resize(col);
		for (int j = 0; j < col; ++j) {
			cin >> map[i][j];
			if (map[i][j] == 1) ++cheseCount;
		}
	}
	BFS(map, visited);
	return 0;
}
