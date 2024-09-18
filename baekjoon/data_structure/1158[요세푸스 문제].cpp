#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	int n, k;
	cin >> n >> k;
	cout << '<';
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		q.push(i);
	}
	for (int i = 0; i < n; i++) {
		int step = k;
		while (step > 0) {
			if (step == 1) {
				cout << q.front();
			}
			else {
				q.push(q.front());
			}
			q.pop();
			step--;
		}
		if (i != n - 1) cout << ", ";
	}
	cout << '>';
	return 0;
}
