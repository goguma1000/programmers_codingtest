//sol 1 memory : 8556kb, 44ms
//sol 2 memory : 3688kb, 24ms

//sol 1.
//회의 시작시간으로 정렬하고 각 시간을 open과 close로 나누어 배열에 둔 뒤 정렬함.
// 그후 close가 나왔을때 open시간이 이전 end 크거나 같을 경우 회의를 시작한다.
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	int n;
	cin >> n;
	vector<pair<int, int>>arr;
	vector<pair<int, pair<int,int>>> splitArr;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		arr.push_back({ a,b });
	}
	sort(arr.begin(), arr.end());
	for (int i = 0; i < n; i++) {
		splitArr.push_back({ arr[i].first ,{i, 0} }); //0 : open 1 : close
		splitArr.push_back({ arr[i].second, {i, 1} });
	}
	sort(splitArr.begin(), splitArr.end());

	int result = 0;
	int end = 0;
	for (int i = 0; i < splitArr.size(); i++) {
		if (splitArr[i].second.second == 1) {
			if (arr[splitArr[i].second.first].first >= end) {
				result++;
				end = arr[splitArr[i].second.first].second;
			}
		}
	}
	cout << result;
	return 0;
}

//sol 2.
//답 봄
//arr를 종료시간 순으로 정렬한다. 그 다음 이전 종료시간보다 시작시간이 크거나 같을 경우 회의를 시작한다.
//sol 1과 아이디어는 비슷하지만 정렬 2번하는 과정과 쪼개서 저장하는 측면에서 메모리와 시간 모두 sol 2가 훨씬 효율적이다.
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	int n;
	cin >> n;
	vector<pair<int, int>>arr;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		arr.push_back({ b,a });
	}
	sort(arr.begin(), arr.end());
	int endT = arr[0].first;
	int result = 1;
	for (int i = 1; i < n; i++) {
		if (arr[i].second >= endT) {
			result++;
			endT = arr[i].first;
		}
	}
	cout << result;
	return 0;
}
