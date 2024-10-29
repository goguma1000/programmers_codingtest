#include <iostream>
#include<algorithm>
#include <vector>
using namespace std;


int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	int n, m;
	cin >> n;
	vector<int> cranes(n);
	vector<int> searchIDX(n);
	for (int i = 0; i < n; i++) {
		cin >> cranes[i];
	}
	cin >> m;
	vector<int> boxes(m);
	for (int i = 0; i < m; i++) {
		cin >> boxes[i];
	}
	sort(cranes.begin(), cranes.end(), greater<int>());
	sort(boxes.begin(), boxes.end(), greater<int>());
	if (boxes[0] > cranes[0]) {
		cout << -1;
		return 0;
	}
	int availableCrane = n - 1;
	for (int i = boxes.size() - 1; i >= 0; i--) {
		if (cranes[availableCrane] < boxes[i]) {
			searchIDX[availableCrane] = i + 1;
			availableCrane--;
			i++;
		}
	}
	int time = 0;
	availableCrane = n - 1;
	int leftBox = m;
	while (availableCrane >= 0) {
		for (int i = 0; i <= availableCrane; i++) {
			if (searchIDX[i] >= m) {
				availableCrane = i - 1;
				break;
			}
			while (true) {
				if (boxes[searchIDX[i]] != 0) {
					leftBox--;
					boxes[searchIDX[i]] = 0;
					searchIDX[i]++;
					break;
				}
				else {
					searchIDX[i]++;
					if (searchIDX[i] >= m) break;
				}
			}
		}
		time++;
		if (leftBox <= 0) break;
	}
	cout << time;
	return 0;
}



