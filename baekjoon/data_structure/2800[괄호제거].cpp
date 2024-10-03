#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <set>
using namespace std;
string decode(const vector<bool>& deleted, const string& src) {
	string result = "";
	for (int i = 0; i < deleted.size(); i++) {
		if (deleted[i] == false) {
			result += src[i];
		}
	}
	return result;
}
void DeleteBracket(set<string>& result,vector<bool>& deleted, const vector<pair<int,int>>& bracketPair ,string src, int start) {
	for (int i = start; i <bracketPair.size(); i++) {
		deleted[bracketPair[i].first]= true;
		deleted[bracketPair[i].second] = true;
		result.insert(decode(deleted, src));
		DeleteBracket(result, deleted, bracketPair, src, i + 1);
		deleted[bracketPair[i].first] = false;
		deleted[bracketPair[i].second] = false;
	}
}
int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	string str;
	cin >> str;
	vector<bool> deleted(str.length(),false);
	vector<pair<int, int>> bracketPair;
	stack<int> s;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '(') {
			s.push(i);
		}
		else if (str[i] == ')') {
			int temp = s.top();
			s.pop();
			bracketPair.push_back({ temp,i });
		}
	}
	set<string> result;
	DeleteBracket(result, deleted, bracketPair, str, 0);
	for (string temp : result) {
		cout << temp<<'\n';
	}
	return 0;
}
