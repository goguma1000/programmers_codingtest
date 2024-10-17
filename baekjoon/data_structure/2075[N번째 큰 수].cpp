//sol 1 그냥 vector에 넣어도 메모리가 문제 조건보다 덜 쓰이므로 vector에 넣고 정렬함. 미리 vector에 size를 정해둬서 가능했음.
#include<queue>
#include<vector>
#include<algorithm>
#include <iostream>
using namespace std;

int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	int n;
	cin >> n;
	vector<int> arr(n*n);
	for (int i = 0; i < n * n; i++) {
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end(), greater<int>());
	cout << arr[n - 1];
}

//sol 2 priority queue에 원소의 개수 5개 이상 넣지 않음.
#include<queue>
#include<vector>
#include <iostream>
using namespace std;

int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	priority_queue<int,vector<int>,greater<int>> pq;
	int n;
	cin >> n;
	for (int i = 0; i < n * n; i++) {
		int temp;
		cin >> temp;
		pq.push(temp);
		if (pq.size() > n) pq.pop();
	}
	cout << pq.top();
}
