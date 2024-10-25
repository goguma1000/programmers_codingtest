#include <iostream>
#include <string>
using namespace std;

int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	string pattern1 = "AAAA";
	string pattern2 = "BB";
	string src;
	cin >> src;
	int count = 0;
	string result = "";
	for (int i = 0; i < src.length(); i++) {
		if (src[i] == 'X') count++;
		else {
			if (count % 2 != 0) {
				cout << -1;
				return 0;
			}
			int pt1Count = count / 4;
			count %= 4;
			int pt2Count = count / 2;
			for (int j = 0; j < pt1Count; j++)result += pattern1;
			for (int j = 0; j < pt2Count; j++)result += pattern2;
			result += src[i];
			count = 0;
		}
	}
	if (count != 0) {
		if (count % 2 != 0) {
			cout << -1;
			return 0;
		}
		int pt1Count = count / 4;
		count %= 4;
		int pt2Count = count / 2;
		for (int j = 0; j < pt1Count; j++)result += pattern1;
		for (int j = 0; j < pt2Count; j++)result += pattern2;
		count = 0;
	}
	cout << result;
	return 0;
}


