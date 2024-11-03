#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	int n;
	cin >> n;
	vector<vector<pair<int,int>>> graph(n + 1);
	vector<int> friends(3);
	vector<vector<long long>>dist(3);
	for (int i = 0; i < 3; i++) {
		cin >> friends[i];
	}
	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({ b,c });
		graph[b].push_back({ a,c });
	}

	for (int i = 0; i < 3; i++) {
		int ind = friends[i];
		dist[i].resize(n + 1, -1);
		dist[i][ind] = 0;
		priority_queue<pair<long long,int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
		pq.push({ 0, ind });
		while (!pq.empty()) {
			auto temp = pq.top();
			pq.pop();
			int cur = temp.second;
			long long curDist = temp.first;
			if (dist[i][cur] != curDist) continue;
			for (auto& edge : graph[cur]) {
				long long newDist = dist[i][cur] + edge.second;
				if (dist[i][edge.first] == -1 || dist[i][edge.first] > newDist) {
					dist[i][edge.first] = newDist;
					pq.push({ newDist, edge.first });
				}
			}
		}
	}
	int max = -1;
	int result = 0;
	for (int i = 1; i <= n; i++) {
		int min = -1;
		for (int j = 0; j < 3; j++) {
			if (friends[j] == i) {
				min = -1;
				break;
			}
			if (min == -1 || min > dist[j][i]) {
				min = dist[j][i];
			}
		}
		if (min >= 0 && (max == -1 || max < min)) {
			max = min;
			result = i;
		}
	}
	cout << result;
	return 0; 
}
