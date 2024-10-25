//sol 1.
//s와 t를 쪼개서 각각 vector에 넣은 뒤 정렬함(좌표에서 시작 값과 끝 값으로 생각)
//stack에 각 좌표를 넣으면서 현재 넣으려는 좌표가 t값이면 어느 강의실에 수업이 끝남을 의미 -> 남은 강의실 수를 증가시킴.
//현재 넣으려는 좌표가 s값이면 남아있는 강의실이 있으면 그 값만 줄여주고 아니면 roomcount를 증가시키고 push한다.
//roomCount값이 답.

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	int n;
	cin >> n;
	vector<pair<int, int>>times;
	for (int i = 0; i < n; i++) {
		int s, t;
		cin >> s >> t;
		times.push_back({ s ,1 });
		times.push_back({ t,0 });
	}
	sort(times.begin(), times.end());
	int left = 0;
	int roomCount = 0;
	stack<pair<int, int>>s;
	for (auto& data : times) {
		int time = data.first;
		int is_s = data.second;
		if (!s.empty()){
			if (is_s == 1) {
				if (left == 0) {
					roomCount++;
				}
				else {
					left--;
				}
				s.push(data);
			}
			else{
				left++;
			}
		}
		else {
			roomCount++;
			s.push(data);
		}
	}
	cout << roomCount;
	return 0;
}

//sol 2.
//답 참고.
//입력 값을 정렬하고, priority_queue에 수업 끝나는 시간을 push한다.
//만약 현재 입력하려는 수업의 시작시간이 priority_queue의 top보다 작으면 push
//크면 top의 강의실의 수업이 끝나고 수업을 진행할 수 있으므로 pop하고 끝나는시간을 push
//pq의 size가 답.

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	int n;
	cin >> n;
	vector<pair<int, int>>times;
	for (int i = 0; i < n; i++) {
		int s, t;
		cin >> s >> t;
		times.push_back({ s,t });
	}
	sort(times.begin(), times.end());
	priority_queue<int, vector<int>, greater<int>> pq;
	pq.push(times[0].second);
	for (int i = 1; i < times.size(); i++) {
		if (pq.top() > times[i].first) {
			pq.push(times[i].second);
		}
		else {
			pq.pop();
			pq.push(times[i].second);
		}
	}
	cout << pq.size();
	return 0;
}
