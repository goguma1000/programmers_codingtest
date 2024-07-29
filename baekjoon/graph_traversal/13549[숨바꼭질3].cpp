#include<iostream>
#include<vector>
#include<math.h>
#include<queue>
int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	std::vector<bool> visited(200000);
	int N, K;
	std::cin >> N >> K;
	std::queue<int> pos_Q;
	std::queue<int> ttime_Q;
	pos_Q.push(N);
	ttime_Q.push(0);
	visited[N] = true;
	int result(INT32_MAX);
	while (!pos_Q.empty())
	{
		int pos(pos_Q.front());
		pos_Q.pop();
		int cur_time(ttime_Q.front());
		ttime_Q.pop();
		if (pos == K) {
			result = result > cur_time ? cur_time : result;
			continue;
		}
		for (int i = -1; i < 2; ++i) {
			int newPos(pos);
			if (i == 0) newPos *= 2;
			else newPos += i;
			int newTime(cur_time + std::abs(i));

			if (
				((pos < newPos && pos < K) || (pos > newPos && pos > 0 )) &&
				!visited[newPos]) {
				pos_Q.push(newPos);
				ttime_Q.push(newTime);
				visited[newPos] = true;
			}
		}
	}
	std::cout << result;
	return 0;
}
