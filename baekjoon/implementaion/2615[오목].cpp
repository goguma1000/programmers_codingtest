#include <iostream>
using namespace std;

int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	int map[19][19] = { 0, };
	bool checked[19][19][4] = { 0, };
	for (int i = 0; i < 19; i++) for (int j = 0; j < 19; j++) {
		cin >> map[i][j];
	}
	for (int i = 0; i < 19; i++) for (int j = 0; j < 19; j++) {
		
		if (map[i][j] != 0) {
			int val = map[i][j];
			if (!checked[i][j][0]) { // 오른쪽
				int count = 1;
				int newJ = j + 1;
				while (newJ < 19 && map[i][newJ] == val) {
					checked[i][newJ][0] = true;
					count++;
					newJ++;
				}
				if (count == 5) {
					cout << val << '\n' << i + 1 << ' ' << j + 1;
					return 0;
				}
			}
			if (!checked[i][j][1]) { //아래
				int count = 1;
				int newI = i + 1;
				while (newI < 19 && map[newI][j] == val) {
					checked[newI][j][1] = true;
					count++;
					newI++;
				}
				if (count == 5) {
					cout << val << '\n' << i + 1 << ' ' << j + 1;
					return 0;
				}

			}
			if (!checked[i][j][2]) { //오른쪽 아래 대각
				int count = 1;
				int newI = i + 1;
				int newJ = j + 1;
				while (newI < 19 && newJ < 19 && map[newI][newJ] == val) {
					checked[newI][newJ][2] = true;
					count++;
					newI++;
					newJ++;
				}
				if (count == 5) {
					cout << val << '\n' << i + 1 << ' ' << j + 1;
					return 0;
				}
			}
			if (!checked[i][j][3]) { //왼쪽 아래 대각
				int count = 1;
				int newI = i + 1;
				int newJ = j - 1;
				while (newI < 19 && newJ >= 0 && map[newI][newJ] == val) {
					checked[newI][newJ][3] = true;
					count++;
					newI++;
					newJ--;
				}
				if (count == 5) {
					cout << val << '\n' << newI << ' ' << newJ + 2;
					return 0;
				}
			}
		}
	}
	cout << 0;
	return 0;
}
