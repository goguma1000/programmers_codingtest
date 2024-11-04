//sol 1. set을 이용한 풀이
#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	int n, d, k, c;
	cin >> n >> d >> k >> c;
	vector<int> lane(n);
	for (int i = 0; i < n; i++) {
		cin >> lane[i];
	}
	vector<int> totalPicked(d + 1, 0);
	unordered_set<int> pickedType;
	for (int i = 0; i < k; i++) {
		totalPicked[lane[i]]++;
		pickedType.insert(lane[i]);
	}
	int max = pickedType.size();
	if (pickedType.find(c) == pickedType.end()) max++;
	for (int i = 0; i < n; i++) {
		int newIDX = (i + k) % n;
		int type = lane[newIDX];
		int deleteType = lane[i];
		totalPicked[deleteType]--;
		if (totalPicked[deleteType] == 0) {
			pickedType.erase(deleteType);
		}
		totalPicked[type]++;
		pickedType.insert(type);
		int temp = pickedType.size();
		if (pickedType.find(c) == pickedType.end()) temp++;
		if (max < temp) max = temp;
	}
	cout << max;
	return 0; 
}

//sol 2. 초밥 타입별 vector를 만들고 뽑히면 해당 타입의 값을 올려주는 방식. set을 사용한 것보다 메모리 사용도 적고 속도도 빠름.
#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	int n, d, k, c;
	cin >> n >> d >> k >> c;
	vector<int> lane(n);
	for (int i = 0; i < n; i++) {
		cin >> lane[i];
	}
	vector<int> totalPicked(d + 1, 0);
	int max = 0;
	bool eat_c = false;
	int pickedTypeNum = 0;
	for (int i = 0; i < n + k; i++) {
		int type = lane[i % n];
		if(i >= k){
			totalPicked[lane[i - k]]--;
			if (totalPicked[lane[i - k]] == 0) {
				pickedTypeNum--;
				if (lane[i - k] == c) eat_c = false;
			}
		}
		if (totalPicked[type] == 0) pickedTypeNum++;
		if (type == c) eat_c = true;
		totalPicked[type]++;
		if (!eat_c && max < pickedTypeNum + 1) max = pickedTypeNum + 1;
		else if (max < pickedTypeNum) max = pickedTypeNum;
	}
	cout << max;
	return 0; 
}
