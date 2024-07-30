#include<iostream>
#include<vector>
#include<queue>
struct Node {
	int row;
	int col;
	bool hasSword;
	Node(int r, int c, bool hs) : row(r), col(c), hasSword(hs) {};
};
int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	int N, M, T;
	std::cin >> N >> M >> T;
	std::vector<std::vector<bool>> visited(N);
	std::vector<std::vector<bool>> visitedWithSword(N);
	std::vector<std::vector<int>> map(N);
	for (int i = 0; i < N; i++) {
		visited[i].resize(M);
		visitedWithSword[i].resize(M);
		map[i].resize(M);
		for (int j = 0; j < M; j++) {
			std::cin >> map[i][j];
		}
	}
	int result(-1);
	int time(0);
	int dx[4] = { 0, 1, 0, -1 };
	int dy[4] = { 1, 0, -1, 0 };
	std::queue<Node> pos_Q;
	pos_Q.push(Node(0, 0, false));
	visited[0][0] = true;
	while (!pos_Q.empty() && result == -1) {
		if (time > T) break;
		for (int lc = pos_Q.size(); lc > 0; --lc) {
			Node node(pos_Q.front());
			pos_Q.pop();
			for (int i = 0; i < 4; ++i) {
				int newR = node.row + dy[i];
				int newC = node.col + dx[i];

				if (newR == N - 1 && newC == M - 1) {
					result = time + 1;
					break;
				}

				if (newR < 0 || newR >= N || newC < 0 || newC >= M) continue;

				Node temp(newR, newC, node.hasSword);
				if (!visited[newR][newC]) {
					if (map[newR][newC] == 2) {
						temp.hasSword = true;
					}
					if (map[newR][newC] == 1 && !node.hasSword) continue;
					pos_Q.push(temp);
					visited[newR][newC] = true;
					if (temp.hasSword) visitedWithSword[newR][newC] = true;
				}
				else if (node.hasSword && !visitedWithSword[newR][newC]) {
					pos_Q.push(temp);
					visitedWithSword[newR][newC] = true;
				}
			}
		}
		++time;
	}
	if (result == -1) std::cout << "Fail";
	else std::cout << result;
	return 0;
}
