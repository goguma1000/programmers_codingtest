#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int graph[101][101] = {0,};

int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	int n, m, r;
	cin >> n >> m >> r;
	vector<int> spots(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> spots[i];
	}
	for (int i = 0; i < r; i++) {
		int a, b, l;
		cin >> a >> b >> l;
		graph[a][b] = l;
		graph[b][a] = l;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j || graph[i][j] == 0)continue;
			for (int k = 1; k <= n; k++) {
				if (graph[i][k] == 0) continue;
				int newDist = graph[j][i] + graph[i][k];
				if ( graph[j][k] == 0 || graph[j][k] > newDist) graph[j][k] = newDist;
			}
		}
	}
	int result = 0;
	for (int i = 1; i <= n; i++) {
		int total = spots[i];
		for (int j = 1; j <= n; j++) {
			if (i == j || graph[i][j] == 0 || graph[i][j] > m) continue;
			total += spots[j];
		}
		if (result < total) result = total;
	}
	cout << result;
	return 0;
}

