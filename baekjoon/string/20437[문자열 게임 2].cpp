#include<iostream>
#include<vector>
#include<string>
using namespace std;



int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	int t;
	cin >> t;
	while (t > 0) {
		string str;
		vector<vector<int>> arr(26);
		int k;
		vector<int> indices;
		cin >> str;
		cin >> k;
		bool validCondition(false);
		int i = 0;
		for (char c : str) {
			arr[c - 'a'].push_back(i);
			if (arr[c - 'a'].size() == k) {
				validCondition = true;
				indices.push_back(c - 'a');
			}
			++i;
		}
		if (!validCondition) cout << -1<<'\n';
		else {
			int min(1000000);
			int max(0);
			for (int idx : indices) {
				for (int j = 0; j + k <= arr[idx].size(); ++j) {
					int temp = arr[idx][j + k - 1] - arr[idx][j] + 1;
					min = min > temp ? temp : min;
					max = max > temp ? max : temp;
				}
			}
			cout << min << ' ' << max << '\n';
		}
		--t;
	}
	
	return 0;
}
