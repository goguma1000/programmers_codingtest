#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	int n;
	cin >> n;
	vector<int> snowBall(n);
	for (int i = 0; i < n; i++) {
		cin >> snowBall[i];
	}
	sort(snowBall.begin(), snowBall.end());
	int min = -1;
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			int st = 0; int end = n - 1;
			int snowman1 = snowBall[i] + snowBall[j];
			while (st < end) {
				if (i == st || j == st) {
					st++;
					continue;
				}

				if (i == end || j == end) {
					end--;
					continue;
				}

				int snowman2 = snowBall[st] + snowBall[end];
				int diff = abs(snowman1 - snowman2);
				if (min < 0 || min > diff) min = diff;

				if (snowman1 == snowman2) break;
				else if (snowman1 > snowman2) st++;
				else end--;
			}
			if (min == 0) break;
		}
		if (min == 0) break;
	}
	cout << min;
	return 0;
}
