#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;
void QuardTree(const vector<vector<int>>& map, int lc_y, int lc_x, int n) {
	int sum(0);
	for (int i = lc_y; i < lc_y + n; i++) {
		for (int j = lc_x; j < lc_x + n; j++) {
			sum += map[i][j];
		}
	}
	if (sum == 0) {
		printf("0");
	}
	else if (sum == n * n) {
		printf("1");
	}
	else {
		printf("(");
		QuardTree(map, lc_y, lc_x, n / 2);
		QuardTree(map, lc_y, lc_x + (n / 2), n / 2);
		QuardTree(map, lc_y + (n/2), lc_x, n / 2);
		QuardTree(map, lc_y + (n / 2), lc_x + (n / 2), n / 2);
		printf(")");
	}
}
int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	int n;
	scanf("%d", &n);
	vector<vector<int>> map(n);
	
	for (int i = 0; i < n; i++) {
		map[i].resize(n);
		for (int j = 0; j < n; j++) {
			scanf("%1d", &map[i][j]);
		}
	}
	QuardTree(map, 0, 0, n);
	return 0;
}
