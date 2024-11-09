//sol 1은 0ms 2292kb sol 2는 332ms 5992kb
//sol 1. 그래프의 엣지를 반대로 하여 diijkstra 거꾸로 돌릴 수 있음. 즉 i번 노드에서 특정 노드까지 거리를 업데이트 할 수 있음.
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	int n, m, x;
	cin >> n >> m >> x;
	vector<vector<pair<int, int>>> graph(n + 1);
	vector<vector<pair<int, int>>> invGraph(n + 1);
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({ b,c });
		invGraph[b].push_back({ a,c });
	}
	vector<int> I2X(n + 1, -1);
	vector<int> X2I(n + 1, -1);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	I2X[x] = 0;
	pq.push({ 0,x });
	while (!pq.empty()) {
		auto cur = pq.top();
		pq.pop();
		if (cur.first != I2X[cur.second]) continue;
		for (auto& edge : invGraph[cur.second]) {
			int newDist = I2X[cur.second] + edge.second;
			if (I2X[edge.first] < 0 || I2X[edge.first] > newDist) {
				I2X[edge.first] = newDist;
				pq.push({ newDist, edge.first });
			}
		}
	}
	X2I[x] = 0;
	pq.push({ 0,x });
	while (!pq.empty()) {
		auto cur = pq.top();
		pq.pop();
		if (cur.first != X2I[cur.second]) continue;
		for (auto& edge : graph[cur.second]) {
			int newDist = X2I[cur.second] + edge.second;
			if (X2I[edge.first] < 0 || X2I[edge.first] > newDist) {
				X2I[edge.first] = newDist;
				pq.push({ newDist, edge.first });
			}
		}
	}
	int max = 0;
	for (int i = 1; i <= n; i++) {
		int temp = I2X[i] + X2I[i];
		if (max < temp) max = temp;
	}
	cout << max;
	return 0;
}

//sol 2. floyd warshall
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	int n, m, x;
	cin >> n >> m >> x;
	vector<vector<int>> table(n + 1);
	for (int i = 1; i <= n; i++) {
		table[i].resize(n + 1, -1);
		table[i][i] = 0;
	}
	for (int i = 0; i < m; i++) {
		int a, b, t;
		cin >> a >> b >> t;
		table[a][b] = t;
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			if (i == k || table[i][k] < 0) continue;
			for (int j = 1; j <= n; j++) {
				if (table[k][j] < 0) continue;
				int newDist = table[i][k] + table[k][j];
				if (table[i][j] < 0 || table[i][j] > newDist) table[i][j] = newDist;
			}
		}
	}
	int max = 0;
	for (int i = 1; i <= n; i++) {
		int temp = table[i][x] + table[x][i];
		if (max < temp) max = temp;
	}
	cout << max;
	return 0;
}
