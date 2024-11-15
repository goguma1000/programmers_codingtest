#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	int n;
	cin >> n;
	priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
	vector<vector<int>> board(n);
	vector<vector<int>> graph(n);
	for (int i = 0; i < n; i++) {
		board[i].resize(n);
		graph[i].resize(n, -1);
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
			if(i < j) pq.push({ board[i][j], { i,j } });
		}
	}
	int sum = 0;
	while (!pq.empty()) {
		auto& cur = pq.top();
		int time = cur.first;
		int a = cur.second.first;
		int b = cur.second.second;
		pq.pop();
		bool doAdd = true;
		for (int i = 0; i < n; i++) {
			if (graph[a][i] <= 0) continue;
			if (graph[a][i] + board[i][b] <= time) {
				if (graph[a][i] + board[i][b] < time) {
					cout << -1;
					return 0;
				}
				doAdd = false;
				break;
			}
		}
		if (doAdd) {
			graph[a][b] = time;
			graph[b][a] = time;
			sum += time;
		}
	}
	cout << sum;
	return 0;
}
