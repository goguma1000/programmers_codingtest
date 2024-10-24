#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	int n;
	cin >> n;
	bool map[52][52] = {false, };
	for (int i = 0; i < n; i++) {
		char p, q;
		string temp;
		cin >> p;
		cin >> temp;
		cin >> q;
		int p_idx = 0, q_idx = 0;
		if ('A' <= p && p <= 'Z') p_idx = p - 'A';
		else if('a' <= p && p <= 'z') p_idx = p - 'a' + 26;
		if ('A' <= q && q <= 'Z') q_idx = q - 'A';
		else if ('a' <= q && q <= 'z') q_idx = q - 'a'+26;
		map[p_idx][q_idx] = true;
	}
	for (int i = 0; i < 52; i++) {
		for (int j = 0; j < 52; j++) {
			if (i == j || !map[j][i]) continue;
			for (int k = 0; k < 52; k++) {
				if (j == k || !map[i][k]) continue;
				map[j][k] = map[j][i] & map[i][k];
			}
		}
	}
	vector<pair<int, int>> result;
	for (int i = 0; i < 52; i++) {
		for (int j = 0; j < 52; j++) {
			if (map[i][j] && i != j) result.push_back({ i,j });
		}
	}
	cout << result.size()<<'\n';
	for (auto& temp : result) {
		char p, q;
		if (temp.first > 25) p = temp.first - 26 + 'a';
		else p = temp.first + 'A';
		if (temp.second > 25) q = temp.second - 26 + 'a';
		else q = temp.second + 'A';
		cout << p << " => " << q << '\n';
	}
	return 0;
}

