//답 봄
//처음에 dp문제 같았지만 깊게 고민하진 않음
//답 보고 dp점화식으로 풀린다는 걸 알고 점화식 자체는 보지않고 직접 찾아서 구현
//(n-1,n-1)상태에서 마지막 카드만 비교하면 최대인줄 알았지만 생각해보니
//(i,n-1)상태에서 계속 왼쪽 카드만 버리면서 (n-1,n-1)까지 내려가면 
//마지막 오른쪽 카드 점수를 못 먹는 경우가 생길 수 있음.
//최종점수는 (n-1,j)값들하고 (i,n)값들임.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	int n, numL, numR, leftMax;
	cin >> n;
	vector<int> leftCards(n);
	vector<int> rightCards(n);
	vector<vector<int>>dp(n);
	for (int i = 0; i < n; i++) {
		cin >> leftCards[i];
		dp[i].resize(n+1,-1);
	}
	for (int i = 0; i < n; i++) {
		cin >> rightCards[i];
	}
	dp[0][0] = 0;
	int sol = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= n; j++) {
			if (i == 0 && j == 0) continue;
			int temp = -1;
			if (j != 0 && dp[i][j-1] >= 0 && leftCards[i] > rightCards[j-1]) {
				temp = dp[i][j - 1] + rightCards[j-1];
			}
			int max = -1;
			if (i - 1 >= 0 && j < n) max = dp[i - 1][j];
			if (i - 1 >= 0 && j - 1 >= 0) max = dp[i - 1][j - 1] > dp[i - 1][j] ? dp[i - 1][j - 1] : dp[i - 1][j];
			max = max > temp ? max : temp;
			dp[i][j] = max;
			sol = dp[i][j] > sol ? dp[i][j] : sol;
		}
	}
	cout << sol;
	return 0;
}
