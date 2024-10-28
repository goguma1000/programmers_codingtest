#include <iostream>
#include <vector>
using namespace std;

int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	int n,m; 
	cin >> n >> m;
	vector<vector<int>> map(n + 1);
	for (int i = 1; i <= n; i++) {
		map[i].resize(n + 1,0);
	}
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		if (map[a][b] == 0) map[a][b] = c;
		else if(map[a][b] > c ) map[a][b] = c;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j || map[j][i] == 0) continue;
			for (int k = 1; k <= n; k++) {
				if (j == k || map[i][k] == 0) continue;
				int newDist = map[j][i] + map[i][k];
				if (map[j][k] == 0 || map[j][k] > newDist) map[j][k] = newDist;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << map[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}


