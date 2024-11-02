#include <iostream>
#include<algorithm>
#include <vector>
#include <cmath>
using namespace std;

int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	int  n, k;
	cin >> n >> k;
	vector<int>arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int leftK = k;
	int st = 0; int end = 0;
	int max = 0;
	while (end < arr.size()) {
		if (arr[end] % 2 != 0 && st == end) {
			st++;
			end++;
		}
		else if (arr[end] % 2 != 0 && st != end) {
			if (leftK == 0) {
				int len = end - st - k;
				if (max < len) max = len;
				do {
					if (arr[st] % 2 != 0) leftK++;
					st++;
				} while (arr[st] % 2 != 0 && st < end);
			}
			if (leftK > 0) {
				leftK--;
				end++;
			}
		}
		else if (arr[end] % 2 == 0) end++;
	}
	int len = end - st - (k - leftK);
	if (max < len) max = len;
	cout << max;
	return 0;
}
