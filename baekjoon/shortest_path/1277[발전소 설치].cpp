//답 봄. diijkstra 사용해서 푸는 문제. 1번 부터 시작해서 기존에 있는 전선일때는 dist를 0으로 하고 아닐땐 거리를 구함.
// 그 후, dist table을 업데이트하고 최소값이 갱신되면 priority queue에 넣음.
// queue에서 pop했을 때, 이미 방문한 발전소면 스킵함.
#include <iostream>
#include <queue>
#include <vector>
#include <unordered_set>
#include <cmath>
using namespace std;
double GetDist(pair<int, int>& a, pair<int, int>& b) {
	return sqrt(pow((a.first - b.first), 2) + pow((a.second - b.second), 2));
}
int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	int n, w; float m;
	cin >> n >> w >> m;
	std::vector<pair<int, int>>positions(n + 1);
	std::vector<unordered_set<int>> graph(n + 1);
	for (int i = 1; i <= n; i++) {
		int x, y;
		cin >> x >> y;
		positions[i] = { x,y };
	}
	for (int i = 0; i < w; i++) {
		int a, b;
		cin >> a >> b;
		float dist = GetDist(positions[a], positions[b]);
		graph[a].insert(b);
		graph[b].insert(a);
	}
	priority_queue<pair<double, int>,vector<pair<double, int>>,greater<pair<double, int>>>pq;
	vector<double> d(n + 1,300000.0f);
	vector<bool>visited(n + 1);
	pq.push({ 0,1 });
	d[1] = 0;
	while (!pq.empty()) {
		auto temp = pq.top();
		pq.pop();
		int u = temp.second;
		if (visited[u]) continue;
		//edge update
		for (int v = 1; v <= n; v++) {
			double dist = graph[u].find(v) != graph[u].end() ? 0 : GetDist(positions[u], positions[v]);
			if (!visited[v] && dist <= m) {
				d[v] = min(d[v], d[u] + dist);
				if(u != v) pq.push({ d[v], v });
			}
		}
		visited[u] = true;
	}
	cout << static_cast<int>(1000 * d[n]);
	return 0;
}

