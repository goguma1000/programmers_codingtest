#include <iostream>

using namespace std;
void PrintPattern(int n) {
	int lc = 4 * n - 3;
	for (int i = 0; i < lc; i++) {
		int cnt = i / 2;
		if (cnt >=  n -1) {
			cnt = (lc / 2) - cnt;
			if (i % 2 != 0 ) cnt -= 1;
		}
		for (int j = 0; j < lc; j++) {
			if (i % 2 == 0) {
				if (j % 2 == 0 && (j <= 2 * cnt || j >= (lc - 1) - 2 * cnt)) {
					cout << '*';
				}
				else if (2 * cnt < j && j < (lc - 1) - 2 * cnt) {
					cout << '*';
				}
				else cout << ' ';
			}
			else {
				if (j % 2 == 0 && (j <= 2 * cnt || j >= (lc - 1) - 2 * cnt)){
					cout << '*';
				}
				else{
					cout << ' ';
				}
			}
		}
		cout << '\n';
	}
};
int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	int n;
	cin >> n;
	PrintPattern(n);
	return 0;
}
