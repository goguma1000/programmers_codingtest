#include <iostream>
#include <queue>
using namespace std;

int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	priority_queue<int, vector<int>, greater<int>>pq;
	int n;
	cin >> n;
	while (n > 0) {
		int val;
		cin >> val;
		if (val == 0) {
			if (pq.empty()) cout << 0 << '\n';
			else {
				cout << pq.top() << '\n';
				pq.pop();
			}
		}
		else pq.push(val);
		n--;
	}
	return 0;
}


