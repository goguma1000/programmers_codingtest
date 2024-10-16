#include <vector>
#include <iostream>
using namespace std;

int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	int n;
	cin >> n;
	vector<vector<int>> map(n);
	for (int i = 0; i < n; i++) {
		map[i].resize(n);
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	//floyd-warshall
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j || map[j][i] == 0) continue;
			for (int k = 0; k < n; k++) {
				int temp = map[j][i] + map[i][k];
				if (map[j][k] == 0 && temp == 2) map[j][k] = 1;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << map[i][j] << ' ';
		}
		cout << '\n';
	}
}
