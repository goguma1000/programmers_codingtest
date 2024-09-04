//처음에 각 단어가 들어갈 오리 인덱스를 포인팅하도록 했지만 오리가 한번에 2마리 빠질때 각 단어의 인덱스를 어떻게 줘야하는지 복잡해서 틀림
//그리디 알고리즘 카테고리라는 것을 알고 문자열을 읽으면서 q가 오면 quack을 다 체크해줘서 확인함.
//마지막으로 끝난 글자가 k가 아닐때 예외 처리를 못해서 답 참고

#include <iostream>
#include <string>
#include <vector>

using namespace std;
int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	string record;
	cin >> record;
	if (record.length() % 5 != 0) {
		cout << -1;
		return 0;
	}
	vector<bool>checked(record.size());
	int checkCount = 0;
	int result = 0;
	for (int i = 0; i < record.size(); i++) {
		if (checkCount == record.size()) break;
		if (checked[i]) continue;
		if (record[i] != 'q') {
			cout << -1;
			return 0;
		}
		else {
			checked[i] = true;
			checkCount++;
			char next = 'u';
			for (int j = i + 1; j < record.size(); j++) {
				if (checked[j]) continue;
				if (record[j] == next) {
					checked[j] = true;
					checkCount++;
					switch (next)
					{
					case 'q':
						next = 'u';
						break;
					case 'u':
						next = 'a';
						break;
					case 'a':
						next = 'c';
						break;
					case 'c':
						next = 'k';
						break;
					case 'k':
						next = 'q';
						break;
					default:
						break;
					}
				}
			}
			if (next != 'q') {
				cout << -1;
				return 0;
			}
			++result;
		}
	}
	cout << result;
	return 0;
}
