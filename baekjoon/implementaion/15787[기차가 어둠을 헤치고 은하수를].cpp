#include <iostream>
#include<queue>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<vector<bool>> trains(n);
	for (int i = 0; i < n; i++) {
		trains[i].resize(21);
	}
	for (int i = 0; i < m; i++) {
		int command, y, x;
		cin >> command >> y;
		y -= 1;
		switch (command)
		{
		case 1:
			cin  >> x;
			if (trains[y][x] != true) trains[y][x] = true;
			break;
		case 2:
			cin  >> x;
			if (trains[y][x] == true) trains[y][x] = false;
			break;
		case 3:
			trains[y][0] = false;
			for (int i = 19; i >= 0; --i) {
				trains[y][i + 1] = trains[y][i];
			}
			break;
		case 4:
			for (int i = 1; i < 21; ++i) {
				trains[y][i - 1] = trains[y][i];
			}
			trains[y][0] = false;
			trains[y][20] = false;
			break;
		default:
			break;
		}
	}
	vector<int> passed;
	passed.push_back(0);
	for (int i = 1; i < n; i++) {
		bool doPass = true;
		for (int j = 0; j < passed.size(); j++) {
			bool isSame= true;
			for (int k = 1; k <= 20; k++) {
				if (trains[passed[j]][k] != trains[i][k]) {
					isSame = false;
					break;
				}
			}
			if (isSame) {
				doPass = false;
				break;
			}
		}
		if (doPass) passed.push_back(i);
	}
	cout << passed.size();
	return 0;
}
