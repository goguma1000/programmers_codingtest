#include<iostream>
#include<string>
using namespace std;

bool isPseudoPalindrome(int rcursor, const string& str, const string& src) {
	
	for (int i = 0; i < str.length(); ++i) {
		if (str[i] != src[rcursor])return false;
		else {
			--rcursor;
		}
	}
	return true;
}

int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	string temp = "123";
	string temp2 = "123";
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		string str;
		cin >> str;
		int isPalindrome(0);
		int cursor(0);
		int rcursor(str.length() - 1);
		while (cursor <= rcursor) {
			if (str[cursor] == str[rcursor]) {
				++cursor;
				--rcursor;
			}
			else {
				string sub = str.substr(cursor, rcursor - cursor) + str.substr(rcursor + 1, str.length());
				string sub2 = str.substr(0,cursor) + str.substr(cursor + 1, rcursor - cursor);
				if (isPseudoPalindrome(rcursor - 1, sub, str) || isPseudoPalindrome(sub2.length() - 1,str.substr(cursor+1,str.length()), sub2)) {
					isPalindrome = 1;
				}
				else isPalindrome = 2;
				break;
			}	
		}
		cout << isPalindrome << '\n';
	}
	 
	return 0;
}
