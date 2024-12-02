#include <iostream>

using namespace std;

int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	int a, b;
	cin >> a >> b;
	int work = 1;
	while (true) {
		if (a == b) break;
		else if (a > b) {
			cout << -1;
			return 0;
		}
		int digit = b % 10;
		if (digit % 2 == 0) {
			b /= 2;
			work++;
		}
		else if (digit == 1) {
			b /= 10;
			work++;
		}
		else {
			cout << -1;
			return 0;
		}
	}
	cout << work;
	return 0;
}
