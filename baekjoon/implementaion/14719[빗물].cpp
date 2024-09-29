#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	int w, h;
	cin >> h >> w;
	vector<int> heights;
	for (int i = 0; i < w; i++) {
		int temp;
		cin >> temp;
		heights.push_back(temp);
	}
	int sum = 0;
	for (int height = 1; height <= h; height++) {
		int start = -1;
		for (int i = 0; i < w; i++) {
			if (heights[i] >= height) {
				if (start < 0) start = i;
				else {
					sum += i - start - 1;
					start = i;
				}
			}
		}
	}
	cout << sum;
}
