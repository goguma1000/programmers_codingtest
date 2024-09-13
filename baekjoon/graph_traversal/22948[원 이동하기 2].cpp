//처음엔 전체 트리를 만들고 bfs를 타는 방식으로 구현함. 트리 생성시간이 O(n^2)이라 시간초과.
//답 봄.
//a의 부모들과 b의 부모들을 구하고 제일 먼저 만나는 부모가 연결점.

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
struct tree {
	int num;
	int x;
	int r;

	tree(int _num = 0, int _x = 0, int _r = 2000000) :num(_num), x(_x), r(_r){
	
	}
};
bool comp(tree a, tree b) {
	if (a.r < b.r) return true;
	else return false;
}
int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	int n;
	cin >> n;
	vector<tree> nodes(n + 1);
	vector<bool> visited(n + 1);

	for (int i = 0; i < n; ++i) {
		int num, x, r;
		cin >> num >> x >> r;
		nodes[num].num = num;
		nodes[num].x = x;
		nodes[num].r = r;
	}
	sort(nodes.begin(), nodes.end(), comp);
	int a, b;
	cin >> a >> b;
	int idx_A = 0, idx_B = 0, idx_intersection = 0;
	bool findA = false, findB = false;
	vector<int> a2root;
	vector<int> b2root;
	for (int i = 0; i <= n; i++) {
		if (nodes[i].num == a) {
			findA = true;
			idx_A = i;
		}
		if (nodes[i].num == b) {
			findB = true;
			idx_B = i;
		}
		if (findA) {
			if (abs(nodes[i].x - nodes[idx_A].x) < abs(nodes[i].r - nodes[idx_A].r) || i == idx_A) {
				visited[i] = true;
				a2root.push_back(i);
			}
		}
		if (findB) {
			if (abs(nodes[i].x - nodes[idx_B].x) < abs(nodes[i].r - nodes[idx_B].r) || i == idx_B) {
				if (visited[i]) {
					idx_intersection = i;
					break;
				}
				b2root.push_back(i);
			}
		}
	}
	int step = a2root.size() + b2root.size();
	cout << step << '\n';
	for (int i = 0; i < a2root.size(); i++) {
		cout << nodes[a2root[i]].num << ' ';
		if (a2root[i] == idx_intersection) break;
	}
	for (int j = b2root.size() - 1; j >= 0; j--) {
		cout << nodes[b2root[j]].num << ' ';
	}
	return 0;
}

///처음풀이
/*
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <cmath>
using namespace std;
struct tree {
	int x;
	int r;
	vector<int> children;
	int parent;

	tree(int _num = 0, int _x = 0, int _r = 2000000, int _parent = -1) : x(_x), r(_r), parent(_parent){
	
	}
};
int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	int n;
	cin >> n;
	vector<tree> nodes(n + 1);
	//make tree
	for (int i = 0; i < n; ++i) {
		int root = 0;
		int num, x, r;
		cin >> num >> x >> r;
		nodes[num].x = x;
		nodes[num].r = r;
		if (i == 0) {
			nodes[0].children.push_back(num);
			nodes[num].parent = 0;
			continue;
		}
		while (true) {
			bool isInserted = false;
			for (int j = 0; j < nodes[root].children.size(); ++j) {
				int child = nodes[root].children[j];
				if (abs(nodes[child].x - x) < abs(nodes[child].r - r)) {
					if (nodes[child].r < r) {
						nodes[root].children[j] = num;
						nodes[child].parent = num;
						nodes[num].parent = root;
						nodes[num].children.push_back(child);
						isInserted = true;
						break;
					}
					else {
						root = child;
						j = -1;
						continue;
					}
				}
			}
			if (!isInserted) {
				nodes[root].children.push_back(num);
				nodes[num].parent = root;
			}
			break;
		}
	}
	
	return 0;
}
*/
