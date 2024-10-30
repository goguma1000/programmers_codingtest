//답 봄.
//각 동전 case일때 경우의 수를 미리 구해놔서 더할 생각을 못함.
// OOOO는 DOOO랑 동일하고 DOOO는 OOO와 DDOO로 쪼개짐 이를 바탕으로 점화식을 세울 수 있음
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
