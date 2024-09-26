#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int calander[1001][366] = {0, };
bool comp(const pair<int, int>& a, const pair<int, int>& b) {
	if (a.first < b.first)return true;
	else if (a.first > b.first) return false;
	else {
		if (a.second > b.second) return true;
		else return false;
	}
}
int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	int n;
	cin >> n;
	std::vector<pair<int, int>> works;
	for (int i = 0; i < n; i++) {
		int s, e;
		cin >> s >> e;
		works.push_back({ s,e });
	}
	sort(works.begin(), works.end(), comp);
	for (const auto& work : works) {
		for (int i = 1; i <= n; i++) {
			bool doAdd = true;
			for (int j = work.first; j <= work.second; j++) {
				if (calander[i][j] != 0) {
					doAdd = false;
					break;
				}
			}
			if (doAdd) {
				for (int j = work.first; j <= work.second; j++) {
					calander[i][j] = 1;
					if (calander[0][j] < i) calander[0][j] = i;
				}
				break;
			}
		}
	}
	int sum = 0;
	int start = 0;
	int maxheight = 0;
	for (int i = 1; i <= 365; i++) {
		if (calander[0][i] != 0) {
			if (start == 0) {
				start = i;
			}
			if (maxheight < calander[0][i]) maxheight = calander[0][i];
		}
		else {
			if (start != 0) {
				sum += (i - start) * maxheight;
				start = 0;
				maxheight = 0;
			}
		}
	}
	if (start != 0) sum += (366 - start) * maxheight;
	cout << sum;
	return 0;
}
