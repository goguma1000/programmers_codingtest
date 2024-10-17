#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	unordered_map<string, string> dogam_key_name;
	vector<string> dogam_key_num;
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		string name;
		cin >> name;
		dogam_key_name.insert({name,to_string(i)});
		dogam_key_num.push_back(name);
	}
	for (int i = 0; i < m; i++) {
		string q;
		cin >> q;
		if ('0' <= q[0] && q[0] <= '9') {
			cout << dogam_key_num[stoi(q)-1] << '\n';
		}
		else cout << dogam_key_name[q] << '\n';
	}
}
