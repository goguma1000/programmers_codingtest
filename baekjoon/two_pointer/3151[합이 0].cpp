//sol 1 1828ms, sol 2 2764ms 
//sol 1. target의 제일 왼쪽과 제일 오른쪽을 찾음. lower_bound , upper_bound 직접 구현.
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int GetLeft(const vector<int>& arr, int st, int end, int target) {
	while (st < end) {
		int mid = (st + end) / 2;
		if (arr[mid] < target) st = mid + 1;
		else end = mid;
	}
	return st;
}
int GetRight(const vector<int>& arr, int st, int end, int target) {
	while (st < end) {
		int mid = (st + end) / 2;
		if (arr[mid] <= target) st = mid + 1;
		else end = mid;
	}
	return end;
}
int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	long long total = 0;
	sort(arr.begin(), arr.end());
	for (int i = 0; i < n - 2; i++) {
		for (int j = i + 1; j < n - 1; j++) {
			int target = -(arr[i] + arr[j]);
			int left = GetLeft(arr, j + 1, n, target);
			int right = GetRight(arr, j + 1, n, target);
			total += right - left;
		}
	}
	cout << total;
	return 0;
}

//sol 2. 이분탐색으로 target이 있는 index 찾고 그 값을 기준으로 제일 왼쪽, 오른쪽 인덱스 찾음. 
//sol 1 과 접근 방식은 동일하지만 left와 right찾는 과정에서 불필요한 연산 생김.
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int BinarySearch(const vector<int>& arr, int st, int end, int target, int size) {
	int mid = (st + end )/ 2;
	if (mid == size) return -1;
	if (arr[mid] == target) return mid;
	else if (st == end) return -1;
	else if (arr[mid] > target) return BinarySearch(arr, st, mid, target, size);
	else return BinarySearch(arr, mid + 1, end, target, size);
}
int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	long long total = 0;
	sort(arr.begin(), arr.end());
	for (int i = 0; i < n - 2; i++) {
		for (int j = i + 1; j < n - 1; j++) {
			int target = -(arr[i] + arr[j]);
			int searchResult = BinarySearch(arr,j + 1, n, target, n);
			if (searchResult == -1) continue;
			else {
				int left = searchResult;
				int right = searchResult;
				while (true) {
					int temp = BinarySearch(arr, j + 1, left, target, left);
					if (temp == -1) break;
					else left = temp;
				}
				while (true) {
					int temp = BinarySearch(arr, right + 1, n, target, n);
					if (temp == -1) break;
					else right = temp;
				}
				total += right - left + 1;
			}
		}
	}
	cout << total;
	return 0;
}
