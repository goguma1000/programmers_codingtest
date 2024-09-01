#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int keyPos[26][2] = { {1,0}, {2,4}, {2,2}, {1,2}, {0,2},{1,3},
					{1,4},{1,5},{0,7},{1,6}, {1,7},{1,8},{2,6},
					{2,5},{0,8},{0,9},{0,0},{0,3},{1,1},{0,4},
					{0,6},{2,3},{0,1},{2,1},{0,5},{2,0} };
bool isvowel(char c) {
	int x = keyPos[c - 'a'][1];
	if (c == 'b' || x >= 5) return true;
	else return false;
}
int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	char left, right;
	string str;
	cin >> left >> right;
	cin >> str;
	int result(0);
	for (int i = 0; i < str.length(); i++) {
		if (!isvowel(str[i])) {
			result += abs(keyPos[str[i] - 'a'][0] - keyPos[left - 'a'][0]) + abs(keyPos[str[i] - 'a'][1] - keyPos[left - 'a'][1]) + 1;
			left = str[i];
		}
		else {
			result += abs(keyPos[str[i] - 'a'][0] - keyPos[right - 'a'][0]) + abs(keyPos[str[i] - 'a'][1] - keyPos[right - 'a'][1]) + 1;
			right = str[i];
		}
	}
	cout << result;
	return 0;
}
