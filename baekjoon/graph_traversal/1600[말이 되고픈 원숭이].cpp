//답 참고함, 3차원 visited 배열에서 사용할 수 있는 능력이 다르면 pass하는 방법을 생각못함. 
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const pair<int, int> horseMoving[8]{ {-2,-1},{-1,-2},{-2,1},{-1,2},{2,1},{1,2},{2,-1},{1,-2} };
const pair<int, int> normalMoving[4]{ {-1,0}, {0,1},{1,0},{0,-1} };
int main() {
	int k, row, col;
	cin >> k >> col >> row;
	vector<vector<int>> map(row);
	bool visited[200][200][31];
	for (int i = 0; i < row; ++i) {
		map[i].resize(col);
		for (int j = 0; j < col; ++j) {
			cin >> map[i][j];
		}
	}
	if (row == 1 && col == 1) {
		cout << 0;
		return 0;
	}
	queue < pair<int, int> >pos_Q;
	queue<int> leftK_Q;
	pos_Q.push({ 0,0 });
	visited[0][0][0] = true;
	leftK_Q.push(k);
	int ans(0);
	while (!pos_Q.empty()) {
		int lc = pos_Q.size();
		for (int i = 0; i < lc; ++i) {
			auto pos(pos_Q.front());
			int leftK(leftK_Q.front());
			pos_Q.pop();
			leftK_Q.pop();
			if (leftK > 0) {
				for (const auto& dydx : horseMoving) {
					int newY = pos.first + dydx.first;
					int newX = pos.second + dydx.second;
					if (newY == row - 1 && newX == col - 1) {
						cout << ans + 1;
						return 0;
					}
					if (newY < 0 || newY >= row || newX < 0 || newX >= col) continue;
					if (visited[newY][newX][leftK - 1] == false && map[newY][newX] != 1) {
						visited[newY][newX][leftK -1] = true;
						pos_Q.push({ newY, newX });
						leftK_Q.push(leftK - 1);
					}
				}
			}
			for (const auto& dydx : normalMoving) {
				int newY = pos.first + dydx.first;
				int newX = pos.second + dydx.second;
				if (newY < 0 || newY >= row || newX < 0 || newX >= col) continue;
				if (newY == row - 1 && newX == col - 1) {
					cout << ans + 1;
					return 0;
				}
				if (visited[newY][newX][leftK] == false && map[newY][newX] != 1) {
					visited[newY][newX][leftK] = true;
					pos_Q.push({ newY, newX });
					leftK_Q.push(leftK);
				}
			}
		}
		ans++;
	}
	cout << -1;
}
