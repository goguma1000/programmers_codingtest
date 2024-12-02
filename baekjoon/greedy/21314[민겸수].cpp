#include <iostream>

using namespace std;

int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	char c;
	int mCnt = 0;
	string maxStr = "";
	string minStr = "";
	while (cin >> c) {
		if (c == 'M') {
			mCnt++;
			continue;
		}
		if (c == 'K') {
			if(mCnt != 0) minStr += '1';
			for (int i = 0; i < mCnt - 1; i++) {
				minStr += '0';
			}
			minStr += '5';

			maxStr += '5';
			for (int i = 0; i < mCnt; i++) {
				maxStr += '0';
			}
			mCnt = 0;
		}
	}
  //마지막끝에 m만 있을 때 최대값은 다 1붙이는거.
  //반례보고 알게 됨.
	if (mCnt != 0) {
		maxStr += '1';
		minStr += '1';
		for (int i = 0; i < mCnt - 1; i++) {
			minStr += '0';
			maxStr += '1';
		}
	}
	cout << maxStr << '\n' << minStr;
	return 0;
}
