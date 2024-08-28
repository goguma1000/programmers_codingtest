#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> rights(n + 1);
	for (int i = 1; i <= n; ++i) cin >> rights[i];
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		int gender, card;
		cin >> gender >> card;
		if (gender == 1) {
			int i = 1;
			while (card * i <= n) {
				rights[card * i] = 1 - rights[card * i];
				++i;
			}
		}
		else{
			int offset(0);
			while (1 <= card - offset && card + offset <= n) {
				if (rights[card - offset] == rights[card + offset]) {
					if (offset == 0) rights[card] = 1 - rights[card];
					else {
						rights[card - offset] = 1 - rights[card - offset];
						rights[card + offset] = 1 - rights[card + offset];
					}
					++offset;
				}
				else break;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		cout << rights[i] << ' ';
		if (i % 20 == 0) cout << '\n';
	}
	return 0;
}
