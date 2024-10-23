//sol 2 답 봄. min_priority queue 와 max_priority queue 이전 중앙 값을 기준으로 가장 가까운 원소 2개를 queue 탑에 위치시키는 아이디어.
// 두 큐의 수가 다르면 많은 쪽 queue의 top이 중앙값. 이전 중앙값은 적은쪽 queue에 삽입.
#include <iostream>
#include <queue>

using namespace std;

int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	int  t;
	cin >> t;
	while (t > 0) {
		int m;
		cin >> m;
		cout << (m + 1) / 2 << '\n';
		priority_queue<int, vector<int>, greater<int>> min_pq; //중앙값보다 큰 원소가 들어가야함
		priority_queue<int, vector<int>, less<int>> max_pq;    //중앙값보다 작은 원소가 들어가야함
		int num_i;
		cin >> num_i;
		int mid = num_i;
		cout << mid << ' ';
		for (int i = 2; i <= m; i++) {
			cin >> num_i;
			if (mid > num_i) max_pq.push(num_i);
			else min_pq.push(num_i);
			if (i % 2 != 0) {
				if (max_pq.size() < min_pq.size()) {
					max_pq.push(mid);
					mid = min_pq.top();
					min_pq.pop();
				}
				else if (max_pq.size() > min_pq.size()) {
					min_pq.push(mid);
					mid = max_pq.top();
					max_pq.pop();
				}
				cout << mid << ' ';
			}
		}
		cout << '\n';
		t--;
	}
	return 0;
}

//sol 1 multiset에 넣은 뒤 begin부터 중앙까지 iterator를 옮겨서 출력헸음. 시간 초과 날 줄 알았지만 안 나서 당황.
#include <iostream>
#include <set>

using namespace std;

int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	int  t;
	cin >> t;
	while (t > 0) {
		int m;
		cin >> m;
		cout << (m + 1) / 2 << '\n';
		multiset<int> arr;
		int num_i;
		cin >> num_i;
		arr.insert(num_i);
		cout << num_i << ' ';
		auto prev = arr.begin();
		for (int i = 2; i <= m; i++) {
			cin >> num_i;
			arr.insert(num_i);
			if (i % 2 != 0) {
				auto temp = arr.begin();
				for (int j = 0; j < i / 2; j++) {
					temp++;
				}
				cout << *temp << ' ';
			}
		}
		cout << '\n';
		t--;
	}
	return 0;
}

