#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
bool table[401][401] = {0,};
int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < k; i++) {
		int a, b;
		cin >> a >> b;
		table[a][b] = true;
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			if (i == k || table[i][k] == false) continue;
			for (int j = 1; j <= n; j++) {
				if (j == k || table[k][j] == false) continue;
				table[i][j] = true;
			}
		}
	}
	int s;
	cin >> s;
	for (int i = 0; i < s; i++) {
		int a, b;
		cin >> a >> b;
		if (table[a][b]) cout << -1 << '\n';
		else if (table[b][a]) cout << 1 << '\n';
		else cout << 0 << '\n';
	}
	return 0;
}
