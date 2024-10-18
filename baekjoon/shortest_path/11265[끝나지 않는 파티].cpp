#include <queue>
#include <vector>
#include <iostream>
using namespace std;


int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> map(n);
	for (int i = 0; i < n; i++) {
		map[i].resize(n);
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j || map[j][i] == 0) continue;
			for (int k = 0; k < n; k++) {
				if (map[i][k] == 0) continue;
				int temp = map[j][i] + map[i][k];
				map[j][k] = map[j][k] > temp ? temp : map[j][k];
			}
		}
	}

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		if (map[a - 1][b - 1] > c) cout << "Stay here";
		else  cout << "Enjoy other party";
		cout << '\n';
	}
}
