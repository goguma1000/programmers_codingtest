//답 봄. 
//처음엔 dfs로 사이클 찾은 후 사이클 길이 구해서 모든 노드 탑색하는 방식으로 작성하였지만 잘 안됨.
//플로이드 와샬 쓸 생각을 못함. 사이클찾는것에 포커스를 둠. 사이클이란건 i->i로 오는 것으로 생각해도 됨.
//다익스트라 풀이도 해볼예정

#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int int_max = 50000000;
int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	int n,m; 
	cin >> n >> m;
	vector<vector<int>> map(n + 1);
	for (int i = 1; i <= n; i++) {
		map[i].resize(n + 1, int_max);
	}

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		map[a][b] = c;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				int temp = map[j][i] + map[i][k];
				map[j][k] = map[j][k] > temp ? temp : map[j][k];
			}
		}
	}
	int result = int_max;
	for (int i = 1; i <= n; i++) {
		result = result > map[i][i] ? map[i][i] : result;
	}
	if (result == int_max) cout << -1;
	else cout << result;
	return 0;
}


