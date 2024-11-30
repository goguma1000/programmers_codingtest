#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	int n;
	cin >> n;
	int max = -1;
	long long total = 0;
	for (int i = 0; i < n; i++) {
		int cur;
		cin >> cur;
		if (max < 0 || max < cur) max = cur;
		total += cur;
	}
	total -= max;
	float temp = (float)total / 2.0f;
	temp += max;
	cout << temp;
}
