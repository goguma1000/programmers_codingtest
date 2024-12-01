//답 봄.
//사용 안 한 운동기구중에 근손실의 최솟값들을 구하고 그 중 최대값을 선택하는 아이디어.
//루프를 돌 때마다 운동기구를 사용했다고 가정하고 현 상태에서 근손실값의 최소는 최대값 + 최소값.
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	int n;
	cin >> n;
	vector<long long>arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());
	long long max = -1;
	if (n % 2 == 0) {
		for (int i = 0; i < n / 2; i++) {
			long long temp = arr[i] + arr[n - 1 - i];
			if (max < 0 || max < temp) max = temp;
		}
	}
	else {
		max = arr[n - 1];
		for (int i = 0; i < n / 2; i++) {
			long long temp = arr[i] + arr[n - 2 - i];
			if (max < 0 || max < temp) max = temp;
		}
	}
	cout << max;
}
