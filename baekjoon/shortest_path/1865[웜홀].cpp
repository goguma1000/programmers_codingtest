//sol 1 2152kb 28ms, sol 2 3076kb 708ms

//sol 1.
//bellman ford 알고리즘으로 음수 사이클이 있는지 확인함.
//처음에는 몇 번 노드에서 출발하는지 모르니까 bellman ford알고리즘을 n번 돌리는 생각을 해서 floyd warshall 알고리즘 보다. 느릴 것이라 생각함.
//시작노드를 임의로 정해도 사이클이 생기면 사이클에 속해있는 노드는 처음 출발보다 시간이 이전으로 갔다고 판단이 되기 때문에 상관없음.
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
int INF = 50000000;
int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	int t;
	cin >> t;
	while (t > 0) {
		int n, m, w;
		cin >> n >> m >> w;
		vector<vector<pair<int, int>>> graph(n + 1);
		for (int i = 0; i < m; i++) {
			int s, e, t;
			cin >> s >> e >> t;
			graph[s].push_back({ e,t });
			graph[e].push_back({ s,t });
		}
		for (int i = 0; i < w; i++) {
			int s, e, t;
			cin >> s >> e >> t;
			graph[s].push_back({ e ,-t });
		}
		bool isFind = false;
		vector<int> dist(n + 1, INF);
		for (int i = 1; i < n; i++) {
			for (int j = 1; j <= n; j++) {
				for (auto edge : graph[j]) {
					int newDist = dist[j] + edge.second;
					if (dist[edge.first] > newDist) dist[edge.first] = newDist;
				}
			}
		}
		for (int j = 1; j <= n; j++) {
			for (auto edge : graph[j]) {
				int newDist = dist[j] + edge.second;
				if (dist[edge.first] > newDist) {
					isFind = true;
					break;
				}
			}
		}
		if (!isFind) cout << "NO" << '\n';
		else cout << "YES" << '\n';
		t--;
	}

	return 0;
}


//sol 2. 
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int INF = 50000000;
int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	int t;
	cin >> t;
	while (t > 0) {
		int n, m, w;
		cin >> n >> m >> w;
		vector<vector<int>> board(n + 1);
		for (int i = 1; i <= n; i++) {
			board[i].resize(n + 1, INF);
			board[i][i] = 0;
		}
		for (int i = 0; i < m; i++) {
			int s, e, t;
			cin >> s >> e >> t;
			if(board[s][e] > t) board[s][e] = t;
			if(board[e][s] > t) board[e][s] = t;
		}
		for (int i = 0; i < w; i++) {
			int s, e, t;
			cin >> s >> e >> t;
			if (board[s][e] > -t) board[s][e] = -t;
		}
		for (int k = 1; k <= n; k++) {
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) {
					int temp = board[i][k] + board[k][j];
					if (board[i][j] > temp) board[i][j] = temp;
				}
			}
		}
		bool isFind = false;
		for (int i = 1; i <= n; i++) {
			if (board[i][i] < 0) {
				isFind = true;
				break;
			}
		}
		if (!isFind) cout << "NO" << '\n';
		else cout << "YES" << '\n';
		t--;
	}
	
	return 0;
}
