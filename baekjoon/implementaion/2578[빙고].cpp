#include <iostream>
using namespace std;


int main() {
	int board[5][5];
	pair<int,int> index[25];
	for (int i = 0; i < 5; i++) for (int j = 0; j < 5; j++) {
		cin >> board[i][j];
		index[board[i][j] - 1] = { i,j };
	}
	int lineCout(0);
	for (int i = 0; i < 5 * 5; i++) {
		int temp;
		cin >> temp;
		auto& idx = index[temp - 1];
		board[idx.first][idx.second] = 0;
		int offsetY = -idx.first;
		int offsetX = -idx.second;
		if (  board[idx.first + offsetY][idx.second]
			+ board[idx.first + (offsetY + 1)][idx.second]
			+ board[idx.first + (offsetY + 2)][idx.second]
			+ board[idx.first + (offsetY + 3)][idx.second]
			+ board[idx.first + (offsetY + 4)][idx.second]
			 == 0) {
			lineCout++;
		}
		if (  board[idx.first][idx.second +offsetX]
			+ board[idx.first][idx.second +(offsetX + 1)]
			+ board[idx.first][idx.second +(offsetX + 2)]
			+ board[idx.first][idx.second +(offsetX + 3)]
			+ board[idx.first][idx.second +(offsetX + 4)]
			== 0) {
			lineCout++;
		}
		if (idx.first == idx.second) {
			if (  board[0][0]
				+ board[1][1]
				+ board[2][2]
				+ board[3][3]
				+ board[4][4]
				== 0) {
				lineCout++;
			}
		}
		if (idx.first + idx.second == 4) {
			if (  board[4][0]
				+ board[3][1]
				+ board[2][2]
				+ board[1][3]
				+ board[0][4]
				== 0) {
				lineCout++;
			}
		}
		if (lineCout >= 3) {
			cout << i + 1;
			break;
		}
	}
	return 0;
}
