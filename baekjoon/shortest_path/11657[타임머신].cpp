#include <iostream>
#include<algorithm>
#include <vector>

using namespace std;
const int inf = 1000000000;
int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<vector<pair<int,int>>> graph(n + 1);
	//음수 사이클이 있을 때 int 값을 초과해서 언더플로우 발생할 수 있음.
	vector<long long> dist(n + 1, inf);
	dist[1] = 0;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({ b,c });
	}
	int lc = n;
	while (lc > 0) {
		for (int i = 1; i <= n; i++) {
			if (dist[i] == inf) continue;
			for (auto& edge : graph[i]) {
				dist[edge.first] = dist[edge.first] > dist[i] + edge.second ? dist[i] + edge.second : dist[edge.first];
			}
		}
		lc--;
	}
	for (int i = 1; i <= n; i++) {
		if (dist[i] == inf) continue;
		for (auto& edge : graph[i]) {
			if (dist[edge.first] > dist[i] + edge.second) {
				//negative cycle find
				cout << -1;
				return 0;
			}
		}
	}
	for (int i = 2; i <= n; i++) {
		if (dist[i] == inf) cout << -1 << '\n';
		else cout << dist[i] << '\n';
	}
	return 0;
}
