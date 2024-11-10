#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int st = 0, end = n - 1;
	int max = 0;
	while(st < end){
		int val = (end - st - 1) * min(arr[st],arr[end]);
		if (max < val) max = val;
		if (arr[st] < arr[end]) st++;
		else end--;
	}
	cout << max;
	return 0;
}
