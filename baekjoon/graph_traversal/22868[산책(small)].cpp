#include <iostream>
#include<queue>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	//입력
	int n, m;
	cin >> n >> m;
	vector<vector<int>> graph(n + 1);
	vector<int> visited(n + 1);
	vector<int> preNode(n + 1);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	int s, e;
	cin >> s >> e;
	//정렬
	for (int i = s; i < e; i++) {
		sort(graph[i].begin(), graph[i].end());
	}
	//SE BFS
	int step(0);
	bool isReach = false;
	queue<int> q;
	q.push(s);
	++visited[s];
	preNode[s] = s;
	while (!q.empty()) {
		int lc = q.size();
		for (int i = 0; i < lc; ++i) {
			auto idx(q.front());
			q.pop();
			for (int next : graph[idx]) {
				if (visited[next] > 0) continue;
				q.push(next);
				++visited[next];
				preNode[next] = idx;
				if (next == e) {
					isReach = true;
					break;
				}
			}
			if (isReach) break;
		}
		step++;
		if (isReach) break;
	}
	for (int i = 0; i <= n; i++) {
		visited[i] = 0;
	}
	int result(step);
	//update visited;
	int node = e;
	while (node != s) {
		++visited[node];
		node = preNode[node];
	}
	//ES BFS
	q = queue<int>();
	q.push(e);
	step = 0;
	isReach = false;
	while (!q.empty()) {
		int lc = q.size();
		for (int i = 0; i < lc; ++i) {
			auto idx(q.front());
			q.pop();
			for (int next : graph[idx]) {
				if (visited[next] > 0) continue;
				q.push(next);
				++visited[next];
				if (next == s) {
					isReach = true;
					break;
				}
			}
			if (isReach) break;
		}
		step++;
		if (isReach) break;
	}
	result += step;
	cout << result;
	return 0;
}
