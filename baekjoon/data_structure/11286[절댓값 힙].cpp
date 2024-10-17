#include <queue>
#include <vector>
#include <cmath>
#include <functional>
#include <iostream>
using namespace std;
/*class compare {
	bool operator()(long long& a, long long& b) {
		if (abs(a) > abs(b)) return true;
		else if (abs(a) < abs(b)) return false;
		else return a > b;
	}
};

priority_queue<long long,vector<long long>,compare>> pq;
*/

bool comp(long long& a, long long& b) {
	if (abs(a) > abs(b)) return true;
	else if (abs(a) < abs(b)) return false;
	else return a > b;
}
int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	priority_queue<long long,vector<long long>,function<bool(long long&, long long&)>> pq(comp);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		long long x;
		cin >> x;
		if (x == 0) {
			if (pq.size() == 0) {
				cout << 0 << '\n';
			}
			else {
				cout << pq.top() << '\n';
				pq.pop();
			}
		}
		else {
			pq.push(x);
		}
	}
}
