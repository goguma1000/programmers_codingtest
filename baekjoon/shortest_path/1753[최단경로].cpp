#include <iostream>
#include <functional>
#include <queue>
#include <vector>
using namespace std;
bool comp(pair<int, int>& a, pair<int, int>& b) {
	return a.second > b.second;
}
int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	int v, e;
	cin >> v >> e;
	int start;
	cin >> start;
	vector<vector<pair<int,int>>>graph(v + 1);
	vector<int> dist(v + 1, -1);
	vector<bool> visited(v + 1, false);
	dist[start] = 0;
	for (int i = 0; i < e; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		graph[u].push_back({ v, w });
	}
	priority_queue<pair<int,int>, vector<pair<int,int>>, function<bool(pair<int, int>&, pair<int, int>&)>> pq(comp);
	pq.push({ start,dist[start]});
	visited[start] = true;
	while (!pq.empty()) {
		int u = pq.top().first;
		int d = pq.top().second;
		pq.pop();
		if (d != dist[u]) continue;
		for (const auto& edge : graph[u]) {
			int v = edge.first;
			int w = edge.second;
			int newDist = dist[u] + w;
			if (dist[v] == -1 || dist[v] > newDist) {
				dist[v] = newDist;
				pq.push({ v, newDist });
			}
		}
	}
	for (int i = 1; i < dist.size(); i++) {
		if (dist[i] == -1) cout << "INF\n";
		else cout <<dist[i] << '\n';
	}
	return 0;
}


