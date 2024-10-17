#include<map>
#include<string>
#include <iostream>
using namespace std;

int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	string tree_type;
	map<string, int> tree_dic;
	int count = 0;
	while (true) {
		getline(cin, tree_type);
		if (tree_type == "") break;
		if (tree_dic.find(tree_type) == tree_dic.end()) {
			tree_dic.insert({ tree_type, 1 });
		}
		else {
			tree_dic[tree_type]++;
		}
		count++;
	}
	cout << fixed;
	cout.precision(4);
	for (const auto& tree : tree_dic) {
		cout << tree.first << ' ' << (tree.second / (float)count) * 100 << '\n';
	}
}
