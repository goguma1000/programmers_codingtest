#include<iostream>
#include<string>
#include<map>

using namespace std;

int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	map<string, int> Dir;
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		string src;
		cin >> src;
		string ext = src.substr(src.find('.') + 1, src.length());
		if (Dir.find(ext) == Dir.end()) Dir.insert({ ext,1 });
		else Dir[ext]++;
	}
	for (auto ext : Dir) {
		cout << ext.first << ' ' << ext.second << '\n';
	}
	return 0;
}
