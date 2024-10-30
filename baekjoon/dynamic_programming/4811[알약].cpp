#include <iostream>
#include<algorithm>
#include <vector>
using namespace std;

int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	while (true) {
		int n;
		cin >> n;
		if (n == 0) break;
		vector<vector<long long>>dp_mat(n);
		for (int i = 0; i < n; i++) {
			dp_mat[i].resize(n + 1 , 1);
		}
		dp_mat[0][0] = 0;
		for (int i = 1; i < n; i++) {
			for (int j = 0; j <= n; j++) {
				if (j == 0) dp_mat[i][j] = dp_mat[i - 1][j + 1];
				else if (j == n) dp_mat[i][j] = dp_mat[i][j - 1] + 1;
				else {
					dp_mat[i][j] = dp_mat[i][j - 1] + dp_mat[i - 1][j + 1];
				}

				if (i == n - 1 && j == 1) break;
			}
		}
		cout << dp_mat[n - 1][1] << '\n';
	}
	return 0;
}
