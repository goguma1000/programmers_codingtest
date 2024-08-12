#include<iostream>
#include<vector>
#include<string>
#include<regex>

using namespace std;

int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	regex regex("(A|B|C|D|E|F)?A+F+C+(A|B|C|D|E|F)?");
	int T;
	cin >> T;
	for (int i = 0; i < T; ++i) {
		string src;
		cin >> src;
		if (regex_match(src, regex)) cout << "Infected!" << '\n';
		else cout << "Good" << '\n';
	}
	return 0;
}
