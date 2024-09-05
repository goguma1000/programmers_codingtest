#include <iostream>
#include <vector>
#include <stack>
#include <string.h>

using namespace std;
int students[100001];
int visited[100001];

int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		for (int j = 1; j <= n; j++) {
			cin >> students[j];
		}
		memset(visited, 0, sizeof(int) * 100001);
		int answer = n;
		for (int j = 1; j <= n; j++) {
			if (visited[j]) continue;
			stack<int> group;
			group.push(j);
			visited[j] = true;
			while (true) {
				int temp = students[group.top()];
				if (!visited[temp]) {
					visited[temp] = true;
					group.push(temp);
				}
				else {
					int remove = 0;
					while (!group.empty()) {
						remove++;
						if (group.top() == temp) {
							answer -= remove;
							break;
						}
						else group.pop();
					}
					break;
				}
			}
		}
		cout << answer << '\n';
	}
	return 0;
}
