#include <string>
#include <regex>
#include <iostream>
using namespace std;
int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	string src;
	getline(cin, src);
	std::regex divRegex("<div title=\"([a-zA-Z0-9_ ]+)\">");
	std::regex divEndRegex("</div>");
	std::regex pRegex("<p>");
	std::regex pEndRegex("</p>");
	std::smatch divMatch;
	std::smatch pargMatch;
	while (regex_search(src, divMatch, divRegex)) {
		smatch match;
		string suffix = divMatch.suffix();
		string  temp = divMatch.str();
		regex_match(temp, match, divRegex);
		cout << "title : " << match[1].str() << '\n';
		regex_search(suffix, match, divEndRegex);
		string paragraphs = match.prefix();
		src = match.suffix();
		while (regex_search(paragraphs, pargMatch, pEndRegex)) {
			string paragraph = pargMatch.prefix().str().substr(3);
			bool pass = false;
			string result = "";
			for (int i = 0; i < paragraph.length(); i++) {
				if (paragraph[i] == '>') {
					pass = false;
					continue;
				}
				if (pass) continue;
				if (paragraph[i] == '<') {
					pass = true;
					continue;
				}
				else if (paragraph[i] == ' ') {
					if (result.length() == 0) continue;
					if (result[result.length() - 1] == ' ') continue;
				}
				result += paragraph[i];
			}
			cout << result << '\n';
			paragraphs = pargMatch.suffix();
		}
	}
	return 0;
}
