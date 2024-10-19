//답 봄. 처음에 이중 우선순위 큐를 구현하려다가 자료구조를 어떻게 설계해야할지 몰라서 실패.
//맞춘사람중 이진트리를 이용해서 푼 사람의 코드 나중에 분석해볼것 
#include <queue>
#include <unordered_map>
#include <vector>
#include <iostream>
using namespace std;

int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	int t;
	cin >> t;
	while (t > 0) {
		priority_queue<int, vector<int>, greater<int>> min_pq;
		priority_queue<int, vector<int>, less<int>> max_pq;
		unordered_map<int, int> num_infos;
		int k;
		cin >> k;
		for (int i = 0; i < k; i++) {
			char cmd;
			int val;
			cin >> cmd >> val;
			if (cmd == 'D') {
				if (min_pq.empty() || max_pq.empty()) continue;
				if (val == -1) {
					while (!min_pq.empty()) {
						int temp = min_pq.top();
						min_pq.pop();
						if (num_infos[temp] > 0) {
							num_infos[temp]--;
							break;
						}
					}
				}
				else if (val == 1) {
					while (!max_pq.empty()) {
						int temp = max_pq.top();
						max_pq.pop();
						if (num_infos[temp] > 0) {
							num_infos[temp]--;
							break;
						}
					}
				}
			}
			else {
				num_infos[val]++;
				min_pq.push(val);
				max_pq.push(val);
			}
		}
		while (!max_pq.empty())
		{
			int temp = max_pq.top();
			if (num_infos[temp] > 0) {
				cout << temp << ' ';
				break;
			}
			else {
				max_pq.pop();
			}
		}
		if (max_pq.empty()) {
			cout << "EMPTY" << '\n';
			t--;
			continue;
		}
		while (!min_pq.empty()) {
			int temp = min_pq.top();
			if (num_infos[temp] > 0) {
				cout << temp << '\n';
				break;
			}
			else {
				min_pq.pop();
			}
		}
		t--;
	}
}
