//답 봄.
//처음엔 문자열을 인덱스를 포함하여 정렬한 다음 이전 인덱스보다 현재 인덱스가 더 크면 추가시키고, 작으면 남은 문자의 인덱스 중 가장 큰 값을 선택함.
//예제케이스는 통과하지만 대다수의 것들에서 문제가 발생.

#include <iostream>
#include <string>
#include <set>
using namespace std;
void solution(const string& str, set<int>& picked, int start, int end) {
	if (start >= end) return;
	char min = 'Z' + 1;
	int minIDX = 0;
	for (int i = start; i < end; i++) {
		if (str[i] < min) {
			min = str[i];
			minIDX = i;
		}
	}
	picked.insert(minIDX);
	for (int idx : picked) {
		cout << str[idx];
	}
	cout << '\n';

	solution(str, picked, minIDX + 1, end);
	solution(str, picked, start, minIDX);
}
int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	string src;
	cin >> src;
	set<int> picked;
	solution(src, picked, 0, src.length());
	return 0;
}
