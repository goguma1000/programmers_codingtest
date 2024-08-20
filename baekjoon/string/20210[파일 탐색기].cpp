#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

void separateWord(vector<string>& result, const string& str) {
	string decimal;
	for (char c : str) {
		if ('0' <= c && c <= '9') {
			decimal += c;
		}
		else {
			if (decimal.length() != 0) {
				result.push_back(decimal);
				decimal = "";
			}
			string temp;
			temp += c;
			result.push_back(temp);
		}
	}
	if (decimal.length() != 0) result.push_back(decimal);
}
int compareDec(const string& d1, const string& d2) {
	bool isdifferent(false);
	string temp1;
	for (int i = 0; i < d1.length(); ++i) {
		if (d1[i] != '0') {
			temp1 = d1.substr(i, d1.length());
			break;
		}
	}

	string temp2;
	for (int i = 0; i < d2.length(); ++i) {
		if (d2[i] != '0') {
			temp2 = d2.substr(i, d2.length());
			break;
		}
	}

	if (temp1.length() < temp2.length()) return 1;
	else if (temp1.length() > temp2.length()) return -1;
	else {
		for (int i = 0; i < temp1.length(); ++i) {
			if (temp1[i] == temp2[i]) continue;
			else {
				if (temp1[i] < temp2[i]) return 1;
				else return -1;
			}
		}
		if (d1.length() - temp1.length() == d2.length() - temp2.length()) return 0;
		else if (d1.length() - temp1.length() < d2.length() - temp2.length()) return 1;
		else return -1;
	}
}

bool NaturalCompare(const vector<string>& s1, const vector<string>& s2) {
	int lc = s1.size() < s2.size() ? s1.size() : s2.size();
	for (int i = 0; i < lc; ++i) {
		if (s1[i][0] > '9' && s2[i][0] > '9') {
			if (s1[i][0] == s2[i][0]) continue;
      
			char c1 = s1[i][0];
			if ('A' <= c1 && c1 <= 'Z') c1 -= 'A';
			else c1 -= 'a';

			char c2 = s2[i][0];
			if ('A' <= c2 && c2 <= 'Z') c2 -= 'A';
			else c2 -= 'a';

			if (c1 == c2) { return s1[i][0] < s2[i][0]; }
			else return c1 < c2;
		}
		else if (s1[i][0] <= '9' && s2[i][0] <= '9') {
			int result = compareDec(s1[i], s2[i]);
			if (result == 1) return true;
			else if (result == 0) continue;
			else return false;
		}
		else {
			if (s1[i][0] < s2[i][0]) return true;
			else return false;
		}
	}
	return s1.size() < s2.size();
}

int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	int n;
	cin >> n;
	vector<vector<string>> strings(n);
	for (int i = 0; i < n; ++i) {
		string temp;
		cin >> temp;
		separateWord(strings[i], temp);
	}
	sort(strings.begin(), strings.end(), NaturalCompare);
	for (int i = 0; i < strings.size(); ++i) {
		string out;
		for (int j = 0; j < strings[i].size(); ++j) {
			out += strings[i][j];
		}
		cout << out << '\n';
	}
	return 0;
}
