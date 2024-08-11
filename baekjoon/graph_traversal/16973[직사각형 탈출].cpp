#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> map(n);
	vector<vector<int>> visited(n);
	vector < pair<int, int> > walls;
	for (int i = 0; i < n; ++i) {
		map[i].resize(m);
		visited[i].resize(m);
		for (int j = 0; j < m; ++j) {
			cin >> map[i][j];
			if (map[i][j] == 1) walls.push_back({ i,j });
		}
	}
	int h, w, S_r, S_c, F_r, F_c;
	cin >> h >> w >> S_r >> S_c >> F_r >> F_c;
	--S_r;
	--S_c;
	--F_r;
	--F_c;
	pair<int, int> dydx[4]{ {-1,0}, {0,1}, {1,0}, {0,-1} };
	queue<pair<int, int>> pos_Q;
	queue<int> count_Q;
	pos_Q.push({ S_r,S_c });
	count_Q.push(0);
	visited[S_r][S_c] = true;
	bool Movable(true);
	while (!pos_Q.empty()) {
		auto pos = pos_Q.front();
		int count = count_Q.front();
		pos_Q.pop();
		count_Q.pop();
		for (auto _dydx : dydx) {
			int newY = pos.first + _dydx.first;
			int newX = pos.second + _dydx.second;
			if (newY < 0 || newY >= n || newX < 0 || newX >= m || newY + h > n || newX + w > m||map[newY][newX] == 1) continue;
			if (visited[newY][newX])continue;
			Movable = true;
			for (auto wall : walls) {
				if ((newY <= wall.first && wall.first < newY + h) && (newX <= wall.second && wall.second < newX + w)) {
					Movable = false;
					break;
				}
			}
			if (Movable) {
				if (newY == F_r && newX == F_c) {
					cout << count + 1;
					return 0;
				}
				pos_Q.push({ newY, newX });
				visited[newY][newX] = true;
				count_Q.push(count + 1);
			}
		}
	}
	cout << -1;
	return 0;
}
