//sol 1) 원을 크기순으로 정렬 후 원 내부 영역을 칠하면서 확인함. 맞춘사람 페이지에서 꼴등.800ms
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
bool comp(pair<int, int>& a, pair<int, int>& b) {
	return a.second < b.second;
}
const int offset = 1010000;
int coord[(offset * 2) + 1] = { 0, };

int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	int n;
	cin >> n;

	vector<pair<int, int>> circles(n);

	for (int i = 0; i < n; i++) {
		cin >> circles[i].first >> circles[i].second;
	}
	sort(circles.begin(), circles.end(), comp);
	for (const auto& circle : circles) {
		int c, r;
		c = circle.first;
		r = circle.second;
		if (coord[c - r + offset] > 0 || coord[c + r + offset] > 0) {
			cout << "NO";
			return 0;
		}
		for (int j = c - r + offset; j <= c + r + offset; j++) {
			coord[j]++;
		}
	}
	cout << "YES";
	return 0;
}
//sol 2) 답 봄. 원 좌표를 좌끝, 우끝으로 쪼개서 정렬 후 스택에 좌표를 넣어가면서 좌표 짝이 안 맞으면 교점 생김.
#include <string>
#include <vector>
#include <tuple>
#include <algorithm>
#include <stack>
#include <iostream>
using namespace std;
bool comp(tuple<int, int,int>& a, tuple<int, int,int>& b) {
	return std::get<0>(a) < std::get<0>(b);
}

int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	int n;
	cin >> n;

	vector<tuple<int,int,int>> circle_Infos;

	for (int i = 0; i < n; i++) {
		int x, r;
		cin >> x >> r;
		circle_Infos.push_back(make_tuple(x - r, 1, i));
		circle_Infos.push_back(make_tuple(x + r, 0, i));
	}
	sort(circle_Infos.begin(), circle_Infos.end(), comp);
	stack<tuple<int, int, int>> s;
	string ans = "YES";
	for (const auto& info : circle_Infos) {
		int pos, left;
		pos = get<0>(info);
		left = get<1>(info);
		if (s.empty()) {
			s.push(info);
			continue;
		}
		if (pos != get<0>(s.top())) {
			if (left == 1) s.push(info);
			else if (get<2>(info) == get<2>(s.top())) {
				s.pop();
			}
			else {
				ans = "NO";
				break;
			}
		}
		else {
			ans = "NO";
			break;
		}
	}
	cout << ans;
	return 0;
}
