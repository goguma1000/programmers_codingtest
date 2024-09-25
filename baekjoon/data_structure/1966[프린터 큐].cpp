#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	int t;
	cin >> t;
	while (t> 0) {
		int n, target;
		cin >> n >> target;
		vector<int> priorities;
		queue<pair<int,int>> q;
		for (int i = 0; i < n; i++) {
			int priority;
			cin >> priority;
			priorities.push_back(priority);
			q.push({priority,i});
		}
		sort(priorities.begin(), priorities.end(),greater<int>());
		int cur = 0;
		while (!q.empty()) {
			int cur_prior = priorities[cur];
			auto temp = q.front();
			q.pop();
			if (temp.first != cur_prior) {
				q.push(temp);
			}
			else { 
				cur++;
				if (temp.second == target) break;
			}
		}
		cout << cur << '\n';
		t--;
	}
	return 0;
}
