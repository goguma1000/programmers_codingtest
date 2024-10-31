#include <iostream>
#include<algorithm>
#include <vector>
using namespace std;
int map[101][101] = {0, };
int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		map[a][b] = 1;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j || map[j][i] == 0) continue;
			for (int k = 1; k <= n; k++) {
				if (i == k || map[i][k] == 0) continue;
				map[j][k] = 1;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		int cnt = 0;
		for (int j = 1; j <= n; j++) {
			if (i == j) continue;
			if (!(map[i][j] | map[j][i])) cnt++;
		}
		cout << cnt << '\n';
	}
	return 0;
}
