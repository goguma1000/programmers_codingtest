//처음엔 dfs로 풀었는데 dfs는 현재 노드일때 거리가 최단인지 보장이 안 됨. bfs로 바꿈
//sol 1
#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	int n, m, k, x;
	cin >> n >> m >> k >> x;
	vector<vector<int>> graph(n + 1);
	vector<int> distance_from_X(n + 1, 2000000);
	vector<int> visited(n + 1);
	distance_from_X[x] = 0;
	visited[x] = true;
	for (int i = 1; i <= m; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
	}
	queue<int> q;
	q.push(x);
	int step = 1;
	while (!q.empty()) {
		if (step > k) break;
		int lc = q.size();
		for (int i = 0; i < lc; i++) {
			int cur = q.front();
			q.pop();
			for (int dst : graph[cur]) {
				distance_from_X[dst] = distance_from_X[dst] > step ? step : distance_from_X[dst];
				if (!visited[dst]) {
					q.push(dst);
					visited[dst] = true;
				}
			}
		}
		step++;
	}
	bool exist = false;
	for (int i = 1; i < distance_from_X.size(); i++) {
		if (distance_from_X[i] == k) {
			exist = true;
			cout << i << '\n';
		}
	}
	if (!exist) cout << -1;
}
//sol 2
#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	int n, m, k, x;
	cin >> n >> m >> k >> x;
	vector<vector<int>> graph(n + 1);
	vector<int> distance_from_X(n + 1, 2000000);
	vector<int> visited(n + 1);
	distance_from_X[x] = 0;
	visited[x] = true;
	for (int i = 1; i <= m; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
	}
	queue<int> q;
	q.push(x);
	int step = 1;
	vector<int> result;
	while (!q.empty()) {
		if (step > k) break;
		int lc = q.size();
		for (int i = 0; i < lc; i++) {
			int cur = q.front();
			q.pop();
			for (int dst : graph[cur]) {
				if (distance_from_X[dst] > step) {
					distance_from_X[dst] = step;
					if (step == k) result.push_back(dst);
				}
				if (!visited[dst]) {
					q.push(dst);
					visited[dst] = true;
				}
			}
		}
		step++;
	}
	if (result.size() == 0) {
		cout << -1;
		return 0;
	}
	sort(result.begin(), result.end());
	for (int i : result) {
		cout << i <<'\n';
	}
}
