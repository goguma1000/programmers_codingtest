//sol 1. diijkstra
#include <iostream>
#include<vector>
#include<queue>
using namespace std;

int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> result(n + 1);
	vector<vector<pair<int, int>>> graph(n + 1);
	for (int i = 1; i <= n; i++) {
		result[i].resize(n + 1, -1);
	}
	
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({ b,c });
		graph[b].push_back({ a,c });
	}

	for (int i = 1; i <= n; i++) {
		vector<int> dist(n + 1, -1);
		dist[i] = 0;
		result[i][i] = i;
		priority_queue<pair<int, int>, vector<pair<int, int>> , greater<pair<int, int>>> pq;
		pq.push({ 0,i });
		while (!pq.empty()) {
			auto cur = pq.top();
			pq.pop();
			if (dist[cur.second] != cur.first) continue;
			for (auto& edge : graph[cur.second]) {
				int newDist = edge.second + dist[cur.second];
				if (dist[edge.first] == -1 || dist[edge.first] > newDist) {
					if (cur.second == i) result[i][edge.first] = edge.first;
					else result[i][edge.first] = result[i][cur.second];
					dist[edge.first] = newDist;
					pq.push({ newDist, edge.first });
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) cout << "- ";
			else cout << result[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0; 
}

//sol 2. floyd warshall
#include <iostream>
#include<vector>
#include<queue>
using namespace std;

int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> result(n + 1);
	vector<vector<int>> dist(n + 1);
	for (int i = 1; i <= n; i++) {
		result[i].resize(n + 1, -1);
		dist[i].resize(n + 1, -1);
	}
	
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		dist[a][b] = c;
		dist[b][a] = c;
		result[a][b] = b;
		result[b][a] = a;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j || dist[j][i] == -1) continue;
			for (int k = 1; k <= n; k++) {
				if (i == k || dist[i][k] == -1) continue;
				int newDist = dist[j][i] + dist[i][k];
				if (dist[j][k] == -1 || dist[j][k] > newDist) {
					dist[j][k] = newDist;
					result[j][k] = result[j][i];
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) cout << "- ";
			else cout << result[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0; 
}
