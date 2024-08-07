#include<iostream>
#include<vector>
#include<string>

using namespace std;
bool isValidPW(string src) {
	char prev('/0');
	int vowel(0);
	int consonant(0);
	bool hasVowel(false);
	for (char c : src) {
		if (c != 'e' && c != 'o' && prev == c) return false;
		if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
			++vowel;
			consonant = 0;
		}
		else {
			vowel = 0;
			++consonant;
		}
		if (vowel > 0) hasVowel = true;
		if (vowel > 2 || consonant > 2) return false;
		prev = c;
	}
	if (hasVowel) return true;
	else return false;
}
int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	string temp;
	while (true) {
		cin >> temp;
		if (temp.compare("end") == 0) break;
		if (isValidPW(temp)) cout << '<' << temp << "> is acceptable." << '\n';
		else cout << '<' << temp << "> is not acceptable." << '\n';
	}
	return 0;
}
