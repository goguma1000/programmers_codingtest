//sol 1
#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>
using namespace std;
int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	unordered_map<int, int> problems; // key: pNum, value: level
	priority_queue<pair<int, int>, vector<pair<int,int>>,less<pair<int, int>>> maxPQ;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minPQ;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int pNum, lv;
		cin >> pNum >> lv;
		problems[pNum] = lv;
		maxPQ.push({ lv, pNum });
		minPQ.push({ lv,pNum });
	}
	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		string cmd;
		cin >> cmd;
		if (cmd.compare("add") == 0) {
			int pNum, lv;
			cin >> pNum >> lv;
			problems[pNum] = lv;
			maxPQ.push({ lv, pNum });
			minPQ.push({ lv, pNum });
		}
		else if (cmd.compare("recommend") == 0) {
			int type;
			cin >> type;
			if (type == 1) {
				while (true) {
					auto temp = maxPQ.top();
					if (problems.find(temp.second) != problems.end() && problems[temp.second] == temp.first) {
						cout << temp.second << '\n';
						break;
					}
					else maxPQ.pop();
				}
			}
			else if (type == -1) {
				while (true) {
					auto temp = minPQ.top();
					if (problems.find(temp.second) != problems.end() && problems[temp.second] == temp.first) {
						cout << temp.second << '\n';
						break;
					}
					else minPQ.pop();
				}
			}
		}
		else if(cmd.compare("solved") == 0) {
			int pNum;
			cin >> pNum;
			problems.erase(pNum);
		}
	}
	return 0;
}
//sol 2
//이진탐색트리를 이용한 풀이.
//stl의 set내부 구조가 균형이진트리이기 때문에 set에 넣어서 함.
#include <iostream>
#include <string>
#include <queue>
#include <set>
#include <unordered_map>
using namespace std;

int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	unordered_map<int, int> problems; // key: pNum, value: level
	set<pair<int, int>> pq;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int pNum, lv;
		cin >> pNum >> lv;
		problems[pNum] = lv;
		pq.insert({ lv, pNum });
	}
	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		string cmd;
		cin >> cmd;
		if (cmd.compare("add") == 0) {
			int pNum, lv;
			cin >> pNum >> lv;
			problems[pNum] = lv;
			pq.insert({ lv, pNum });
		}
		else if (cmd.compare("recommend") == 0) {
			int type;
			cin >> type;
			if (type == 1) {

				cout << (--pq.end())->second << '\n';
			}
			else if (type == -1) {
				cout << pq.begin()->second << '\n';
			}
		}
		else if(cmd.compare("solved") == 0) {
			int pNum;
			cin >> pNum;
			pq.erase({ problems[pNum], pNum });
			problems.erase(pNum);
		}
	}
	return 0;
}


