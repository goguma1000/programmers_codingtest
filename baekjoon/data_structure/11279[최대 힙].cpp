//c++에서 priority queue는 greater로 하면 값이 작은게 top으로 올라옴.
#include<queue>
#include<vector>
#include <iostream>
using namespace std;

int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	priority_queue<long long,vector<long long>,less<long long>> pq;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		long long cmd;
		cin >> cmd;
		if (cmd == 0) {
			if (pq.empty()) cout << 0 << '\n';
			else {
				cout << pq.top() <<'\n';
				pq.pop();
			}
		}
		else pq.push(cmd);
	}
}
