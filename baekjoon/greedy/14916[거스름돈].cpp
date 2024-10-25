#include <iostream>
using namespace std;

int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	int  n;
	int result = 0;
	cin >> n;
	while (n != 0) {
		if (n < 2) {
			cout << -1;
			return 0;
		}
		if (n % 5 == 0) {
			result += n / 5;
			n %= 5;
		}
		else {
			result++;
			n -= 2;
		}
	}
	cout << result;
	return 0;
}
