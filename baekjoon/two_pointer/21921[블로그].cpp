#include <iostream>
#include<algorithm>
#include <vector>
using namespace std;

int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<int>arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int st = 0, end = m - 1;
	int max = 0;
	for (int i = st; i < m; i++) {
		max += arr[i];
	}
	int duration = 1;
	int cur_Sum = max;
	while (end < arr.size() - 1) {
		cur_Sum -= arr[st];
		st++;
		end++;
		cur_Sum += arr[end];
		if (max < cur_Sum) {
			max = cur_Sum;
			duration = 1;
		}
		else if (max == cur_Sum) duration++;
	}
	if (max == 0) cout << "SAD";
	else cout << max << '\n' << duration;
	return 0;
}
