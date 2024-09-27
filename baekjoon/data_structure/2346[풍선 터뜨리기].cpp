#include <iostream>
#include <queue>
using namespace std;

int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	int n;
	cin >> n;
	deque<pair<int,int>> balloons;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		balloons.push_back({ temp,i + 1 });
	}
	auto prev = balloons.front();
	balloons.pop_front();
	while (!balloons.empty()) {
		cout << prev.second << ' ';
		if (prev.first > 0) {
			for (int i = 0; i < prev.first - 1; i++) {
				balloons.push_back(balloons.front());
				balloons.pop_front();
			}
			prev = balloons.front();
			balloons.pop_front();
		}
		else {
			for (int i = 0; i < -prev.first - 1; i++) {
				balloons.push_front(balloons.back());
				balloons.pop_back();
			}
			prev = balloons.back();
			balloons.pop_back();
		}
	}
	cout << prev.second;
}
