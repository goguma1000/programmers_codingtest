#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	vector<int> pq;
	int max = 0;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int rope;
		cin >> rope;
		pq.push_back(rope);
	}
	sort(pq.begin(), pq.end(), greater<int>());
	int count = 0;
	for(int i = 0; i < n; i++){
		int weight = pq[i];
		weight *= (i + 1);
		max = max < weight ? weight : max;
	}
	cout << max;
	return 0;
}


