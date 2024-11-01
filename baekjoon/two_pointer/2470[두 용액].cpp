// sol 1
#include <iostream>
#include<algorithm>
#include <vector>
#include <cmath>
using namespace std;
bool comp(int& a, int& b) {
	int absA = abs(a);
	int absB = abs(b);
	return absA < absB;
}
int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	int n;
	cin >> n;
	vector<int> propertyValues(n);
	for (int i = 0; i < n; i++) {
		cin >> propertyValues[i];
	}
	sort(propertyValues.begin(), propertyValues.end(), comp);
	int val1 = 0, val2 = 0;
	int maxD = 2000000002;
	for (int i = 0; i < n - 1; i++) {
		int sum = propertyValues[i] + propertyValues[i + 1];
		int dist = abs(0 - sum);
		if (dist < maxD) {
			maxD = dist;
			val1 = propertyValues[i];
			val2 = propertyValues[i + 1];
		}
	}
	if (val1 < val2) cout << val1 << ' ' << val2;
	else cout << val2 << ' ' << val1;
	return 0;
}

//sol 2
#include <iostream>
#include<algorithm>
#include <vector>
#include <cmath>
using namespace std;

int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	int n;
	cin >> n;
	vector<int> propertyValues(n);
	for (int i = 0; i < n; i++) {
		cin >> propertyValues[i];
	}
	sort(propertyValues.begin(), propertyValues.end());
	int val1 = 0, val2 =  0;
	int pt1 = 0, pt2 = n - 1;
	int minD = 2000000002;
	while (pt1 < pt2) {
		int sum = propertyValues[pt1] + propertyValues[pt2];
		int dist = abs(0 - sum);
		if (minD > dist) {
			val1 = propertyValues[pt1];
			val2 = propertyValues[pt2];
			minD = dist;
		}
		if (sum == 0) break;
		else if (sum > 0) { //합이 양수면 0에 가까워 지려면 큰값을 작게 만들어야함
			pt2--;
		}
		else {				//합이 음수면 0에 가까워 지려면 작은값을 크게 만들어야 함
			pt1++;
		}
	}
	cout << val1 << ' ' << val2;
	return 0;
}
