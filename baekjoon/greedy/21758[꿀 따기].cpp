#include <iostream>
#include <vector>
using namespace std;

int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	vector<int> l2rSumStack(n);
	vector<int> r2lSumStack(n);
	for (int i = n - 2; i >= 0; i--) {
		l2rSumStack[i] = l2rSumStack[i + 1] + arr[i + 1];
	}
	for (int i = 1; i < n; i++) {
		r2lSumStack[i] = r2lSumStack[i - 1] + arr[i - 1];
	}
	int max = 0;
	for (int i = 1; i < n - 1; i++) {
		int cand1 = r2lSumStack[n - 1] + r2lSumStack[i] - arr[i];
		int cand2 = l2rSumStack[0] + l2rSumStack[i] - arr[i];
		int temp = cand1 > cand2 ? cand1 : cand2;
		if (temp > max) max = temp;
	}
	for (int i = 1; i < n - 1; i++) {
		int lr = l2rSumStack[0] - l2rSumStack[i];
		int rl = r2lSumStack[n - 1] - r2lSumStack[i];
		lr += rl;
		if (max < lr) max = lr;
	}
	cout << max;
	return 0;
}
