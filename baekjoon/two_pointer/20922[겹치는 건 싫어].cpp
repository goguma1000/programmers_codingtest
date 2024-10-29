#include <iostream>
#include<algorithm>
#include <vector>
using namespace std;

int numCount[100001] = {0,};
int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	int n, k;
	cin >> n >> k;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int max = 0;
	int st = 0, end = 0;
	while (end < arr.size()) {
		if (numCount[arr[end]] == k) {
			if (max < end - st) max = end - st;
			while (true) {
				numCount[arr[st]]--;
				st++;
				if (arr[st - 1] == arr[end]) {
					break;
				}
			}
		}
		numCount[arr[end]]++;
		end++;
	}
	if (max < end - st) max = end - st;
	cout << max;
}
