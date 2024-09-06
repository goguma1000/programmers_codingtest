#include <iostream>
#include <vector>


using namespace std;

int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	int n, k;
	cin >> n >> k;
	vector<int> s(n + 1);
	vector<int>d(n+ 1);
	for (int i = 1; i <= n; i++) {
		cin >> s[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> d[i];
	}
	for (int i =0; i < k; i++) {
		vector<int> temp(n + 1);
		for (int j = 1; j <= n; j++) {
			temp[d[j]] = s[j];
		}
		s = temp;
	}
	for (int i = 1; i <= n; i++) {
		cout << s[i] << ' ';
	}
	return 0;
}
