#include <iostream>
#include<vector>
#include<queue>
using namespace std;

int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	int n, s;
	cin >> n >> s;
	int minLen = 0;
	vector<int>arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int st = 0; int end = 0;
	int sum = arr[0];
	while (st < n) {
		if (sum >= s) {
			int len = end - st + 1;
			if (minLen == 0 || minLen > len) minLen = len;
			sum -= arr[st];
			if (st == end) {
				end++;
			}
			st++;
		}
		else {
			if (end < n - 1) {
				end++;
				sum += arr[end];
			}
			else break;
		}
	}
	cout << minLen;
	return 0; 
}
