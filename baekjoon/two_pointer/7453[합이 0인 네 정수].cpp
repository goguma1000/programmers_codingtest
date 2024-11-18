//답 봄.
//문제를 잘못읽어서 n이 배열의 갯수인줄 앎.
//두개씩 묶어서 합을 배열에 넣고 두 배열을 비교하는 아이디어가 있다는 것을 알 수 있었던 문제.
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	int n; 
	cin >> n;
	vector<vector<int>>arrs(4);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 4; j++) {
			int temp;
			cin >> temp;  
			arrs[j].push_back(temp);
		}
	}
	vector<int> ab_sum;
	vector<int> cd_sum;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ab_sum.push_back(arrs[0][i] + arrs[1][j]);
			cd_sum.push_back(arrs[2][i] + arrs[3][j]);
		}
	}
	sort(cd_sum.begin(), cd_sum.end());
	long long total = 0;
	for (int i = 0; i < ab_sum.size(); i++) {
		int target = ab_sum[i];

		int left = lower_bound(cd_sum.begin(), cd_sum.end(), -target) - cd_sum.begin();
		int right = upper_bound(cd_sum.begin(), cd_sum.end(), -target) - cd_sum.begin();
		total += static_cast<long long>(right - left);
	}
	cout << total;
}
