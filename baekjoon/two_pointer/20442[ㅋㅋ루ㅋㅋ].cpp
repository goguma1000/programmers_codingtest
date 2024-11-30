#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	string str;
	cin >> str;
	int total_R = 0;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == 'R') total_R++;
	}
	int kCnt = 0;
	int rCnt = 0;
	int st = 0, end = str.length() - 1;
	int max = 0;
	while (st <= end) {
		if (str[st] == 'K' && str[end] == 'K') {
			kCnt += 2;
			st++;
			end--;
		}
		else {
			int subLen = kCnt + (total_R - rCnt);
			if (max < subLen) max = subLen;
			if (str[st] == 'R') {
				rCnt++;
				st++;
			}
			if (str[end] == 'R') {
				rCnt++;
				end--;
			}
		}
	}
	cout << max;
}
