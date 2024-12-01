//처음 시작하는 색의 끝 인덱스까지 색을 칠하고 사이에 다른 색을 칠하면 됨.
//반례보고 풂.
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	int n;
	cin >> n;
	vector<char> arr(n);
	int rb_idx = 0;
	int rr_idx = 0;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (arr[i] == 'B') {
			rb_idx = i;
		}
		else if (arr[i] == 'R') {
			rr_idx = i;
		}
	}
	char painted = arr[0];
	int painted_rnd = rb_idx;
	if (arr[0] == 'R') painted_rnd = rr_idx;
	int st = -1;
	int workCnt = 1;
	if (painted_rnd != n - 1) workCnt++;
	for (int i = 0; i <= painted_rnd; i++) {
		if (arr[i] == painted && st >= 0) {
			workCnt++;
			st = -1;
		}
		else if (arr[i] != painted && st < 0) st = i;
	}
	cout << workCnt;
}
