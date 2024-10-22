//sol 2 using symetric min max heap
#include <iostream>
#include <functional>
#include <queue>
#include <vector>
using namespace std;
/// <Symetric min max heap>
/// P1. 각 노드의 원소는 오른쪽 형제 원소보다 작거나 같다.
/// P2.조부모를 가진 모든 노드에 대해, 조부모의 왼쪽 자식에 있는 원소는 작거나 같다.
/// P3.조부모를 가진 모든 노드에 대해, 조부모의 오른쪽 자식에 있는 원소는 크거나 같다.
/// </Symetric min max heap>
struct Double_priority_Queue {
	vector<int> arr;
	int last = 1;

	Double_priority_Queue() {
		arr.resize(2);
	}

	void push(int val) {
		arr.push_back(val);
		last++;
		int cur = last;
		if (last % 2 == 1 && arr[last - 1] > arr[last]) {
			swap(arr[last - 1], arr[last]);
			cur = last - 1;
		}
		while (cur / 4 >= 1) {
			int gLC, gRC;
			gLC = 2 * (cur / 4);
			gRC = 2 * (cur / 4) + 1;
			//P2 위배
			if (arr[gLC] > arr[cur]) {
				swap(arr[gLC], arr[cur]);
				cur = gLC;
			}
			//P3위배
			else if (arr[gRC] < arr[cur]) {
				swap(arr[gRC], arr[cur]);
				cur = gRC;
			}
			else break;
		}
	}
	void pop_min() {
		if (last < 2) return;
		swap(arr[2], arr[last]);
		arr.erase(arr.end() - 1);
		last--;
		int cur = 2;
		while (cur <= last) {
			int rsLC, LC;
			rsLC = 2 * (cur + 1);
			LC = cur * 2;
			int minC = LC;
			if (LC > last) break;
			else if (rsLC <= last && arr[rsLC] < arr[LC]) minC = rsLC;
		
			//P2위배
			if (arr[minC] < arr[cur]) {
				swap(arr[minC], arr[cur]);
				cur = minC;
				//P1 위배
				if (cur < last && arr[cur] > arr[cur + 1]) {
					swap(arr[cur], arr[cur + 1]);
				}
			}
			else break;
		}
	}
	void pop_max() {
		if (last < 2) return;
		int cur = 3;
		if (last == 2) cur = 2;
		swap(arr[cur], arr[last]);
		arr.erase(arr.end() - 1);
		last--;
		while (cur <= last)
		{
			int lsRC, RC;
			lsRC = 2 * cur - 1;
			RC = 2 * cur + 1;
			int maxC = lsRC;
			if (lsRC > last) break;
			else if (RC <= last && arr[lsRC] < arr[RC]) maxC = RC;

			//P3위배
			if (arr[maxC] > arr[cur]) {
				swap(arr[cur], arr[maxC]);
				cur = maxC;
				//P1위배
				if (cur <= last && arr[cur] < arr[cur - 1]) {
					swap(arr[cur], arr[cur - 1]);
				}
			}
			else break;
		}
	}
	void printMinMAx() {
		if (last == 1) cout << "EMPTY" << '\n';
		else if (last == 2) cout << arr[2] << ' ' << arr[2] << '\n';
		else cout << arr[3] << ' ' << arr[2] << '\n';
	}
};
int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	int t;
	cin >> t;
	while (t > 0) {
		Double_priority_Queue dpq;
		int k;
		cin >> k;
		for (int i = 0; i < k; i++) {
			char cmd;
			int val;
			cin >> cmd >> val;
			if (cmd == 'D') {
				if (val == -1) {
					dpq.pop_min();
				}
				else {
					dpq.pop_max();
				}
			}
			else {
				dpq.push(val);
			}
		}
		dpq.printMinMAx();
		t--;
	}
	return 0;
}

//sol 1
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
