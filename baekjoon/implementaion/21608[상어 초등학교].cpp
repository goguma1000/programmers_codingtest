#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <cmath>
using namespace std;
bool comp(pair<pair<int,int>,int>& a, pair<pair<int, int>, int>& b) {
	if (a.second > b.second) return true;
	else if (a.second < b.second) return false;
	else {
		if (a.first.first < b.first.first) return true;
		else if (a.first.first > b.first.first) return false;
		else {
			if (a.first.second < b.first.second) return true;
			else return false;
		}
	}
}
int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	int n;
	cin >> n;
	vector<vector<int>> _class((n + 2));
	vector<vector<int>> students(n*n + 1);
	vector<pair<int,int>> student_pos(n*n + 1);
	queue<int> q;
	const pair<int, int> dydx[4] = { {-1,0}, {0,-1},{0,1},{1,0} };
	_class[0].resize(n + 2, -1);
	_class[n + 1].resize(n + 2, -1);
	for (int i = 1; i <= n; i++) {
		_class[i].resize(n + 2, -1);
		for (int j = 1; j <= n; j++) {
			_class[i][j] = 0;
			int num, s1, s2, s3, s4;
			cin >> num >> s1 >> s2 >> s3 >> s4;
			q.push(num);
			students[num].push_back(s1);
			students[num].push_back(s2);
			students[num].push_back(s3);
			students[num].push_back(s4);
		}
	}
	while (!q.empty()) {
		int student = q.front();
		q.pop();
		map<pair<int, int>, int> candidates;
		for (int want_s : students[student]) {
			auto pos = student_pos[want_s];
			if (pos.first != 0 && pos.second != 0) {
				for (const auto& _dydx : dydx) {
					int newY = pos.first + _dydx.first;
					int newX = pos.second + _dydx.second;
					if (newY < 1 || newY > n || newX < 1 || newX > n || _class[newY][newX] > 0) continue;
					pair<int, int> key = { newY, newX };
					if (candidates.find(key) == candidates.end()) {
						candidates.insert({key,1 });
					}
					else {
						candidates.at(key)++;
					}
				}
			}
		}
		if (candidates.empty()) {
			int maxCount = -1;
			pair<int, int> idx = { 1,1 };
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) {
					if (_class[i][j] != 0) continue;
					int temp = 0;
					for (const auto& _dydx : dydx) {
						int newY = i + _dydx.first;
						int newX = j + _dydx.second;
						if (_class[newY][newX] == 0) temp++;
					}
					if (maxCount < temp) {
						idx = { i,j };
						maxCount = temp;
					}
					if (maxCount == 4) break;
				}
				if (maxCount == 4) break;
			}
			_class[idx.first][idx.second] = student;
			student_pos[student] = idx;
			continue;
		}
		vector<pair<pair<int, int>, int>> candidates_Vec(candidates.begin(),candidates.end());
		sort(candidates_Vec.begin(), candidates_Vec.end(), comp);
		int maxScore = candidates_Vec[0].second;
		int maxCount = 0;
		pair<int, int> finalIdx = candidates_Vec[0].first;
		for (auto& candidate : candidates_Vec) {
			int emptyCount = 0;
			if (candidate.second != maxScore) break;
			for (const auto& _dydx : dydx) {
				int newY = candidate.first.first + _dydx.first;
				int newX = candidate.first.second + _dydx.second;
				if (_class[newY][newX] == 0) emptyCount++;
			}
			if (emptyCount == 4) {
				finalIdx = candidate.first;
				break;
			}
			else if (maxCount < emptyCount) {
				finalIdx = candidate.first;
				maxCount = emptyCount;
			}
		}
		_class[finalIdx.first][finalIdx.second] = student;
		student_pos[student] = finalIdx;
	}
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int temp = 0;
			int student = _class[i][j];
			for (int want_s : students[student]) {
				int diff = abs(i - student_pos[want_s].first) + abs(j - student_pos[want_s].second);
				if (diff == 1) temp++;
			}
			if (temp != 0)sum += pow(10, temp - 1);
		}
	}
	cout << sum;
	return 0;
}
