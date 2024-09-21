#include <iostream>
#include <queue>
using namespace std;
int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	int n;
	cin >> n;
	queue<int> queue;
	for (int i = 1; i <= n; i++) {
		queue.push(i);
	}
	while (queue.size() != 1) {
		queue.pop();
		queue.push(queue.front());
		queue.pop();
	}
	cout << queue.front();
	return 0;
}
