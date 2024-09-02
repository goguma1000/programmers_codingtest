//첨엔 하나씩 해보는 방식으로 해서 시간초과. 질문게시판 살짝 참고해서 0주변 그룹의 모양 갯수로 최대값 구함.

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <set>
using namespace std;
const pair<int, int> dydx[4] = { {-1,0}, {0,1},{1,0},{0,-1} };
int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> map(n);
	vector<pair<int, int>> indices;
	vector<vector<bool>> visited(n);
	unordered_map<int, int> groups;
	set<pair<int, int>> zero_Indices;
	for (int i = 0; i < n; ++i) {
		map[i].resize(m);
		visited[i].resize(m);
		for (int j = 0; j < m; ++j) {
			cin >> map[i][j];
			if (map[i][j] == 1) indices.push_back({ i,j });
		}
	}
	int groupName = 2;
	for (const auto& idx : indices) {
		if (!visited[idx.first][idx.second]) {
			queue<pair<int, int>> bfs_Q;
			queue<pair<int, int>> group_Q;
			bfs_Q.push(idx);
			group_Q.push(idx);
			visited[idx.first][idx.second] = true;
			while (!bfs_Q.empty())
			{
				auto temp = bfs_Q.front();
				bfs_Q.pop();
				for (const auto& _dydx : dydx) {
					int newY = temp.first + _dydx.first;
					int newX = temp.second + _dydx.second;
					if (newY < 0 || newY >= n || newX < 0 || newX >= m) continue;
					if (map[newY][newX] == 1 && !visited[newY][newX]) {
						bfs_Q.push({ newY,newX });
						group_Q.push({ newY,newX });
						visited[newY][newX] = true;
					}
					else if (map[newY][newX] == 0) zero_Indices.insert({ newY, newX });
				}
			}
			int num = group_Q.size();
			groups.insert({ groupName, num });
			while(!group_Q.empty())
			{
				auto temp = group_Q.front();
				group_Q.pop();
				map[temp.first][temp.second] = groupName;
			}
			++groupName;
		}
	}
	int max(0);
	for (const auto& idx : zero_Indices) {
		set<int> tempSet;
		for (const auto& _dydx : dydx) {
			int newY = idx.first + _dydx.first;
			int newX = idx.second + _dydx.second;
			if (newY < 0 || newY >= n || newX < 0 || newX >= m) continue;
			if (map[newY][newX] > 1) tempSet.insert(map[newY][newX]);
		}
		int temp = 1;
		for (int t : tempSet) {
			temp += groups[t];
		}
		max = max > temp ? max : temp;
	}
	cout << max;
	return 0;
}
