#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	int n;
	cin >> n;
	vector<long long> load(n - 1);
	vector<long long> price(n);
	for (int i = 0; i < n - 1; i++) {
		cin >> load[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> price[i];
	}
	long long cost = 0;
	long long cur = 0;
	long long distSum = 0;
	for (int i = 1; i < n; i++) {
		distSum += load[i - 1];
		if (price[cur] > price[i] || i == n - 1) {
			cost += price[cur] * distSum;
			cur = i;
			distSum = 0;
		}
	}
	cout << cost;
}
