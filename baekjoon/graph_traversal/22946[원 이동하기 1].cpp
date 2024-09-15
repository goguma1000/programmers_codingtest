#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;
struct circle {
	int x;
	int y;
	int r;
	int parent;
	vector<int> children;
	circle(int _x = 0, int _y = 0, int _r = INT_MAX, int _p = -1) : x(_x), y(_y), r(_r), parent(_p){

	}
};
bool comp(circle c1, circle c2) {
	if (c1.r > c2.r) return true;
	else return false;
}

int dfs(const vector<circle>& nodes, vector<vector<int>>& nodeVal, int root, int max) {
	int result[2] = { 0,0 };
	for (int i = 0; i < nodes[root].children.size(); i++) {
		int child = nodes[root].children[i];
		int temp = dfs(nodes, nodeVal, child, max);
		if (temp > max) max = temp;
		if (nodeVal[child][0] >= result[0]) {
			result[1] = result[0];
			result[0] = nodeVal[child][0];
		}
		else if (nodeVal[child][0] > result[1]) {
			result[1] = nodeVal[child][0];
		}
	}
	nodeVal[root][0] = result[0] + 1;
	nodeVal[root][1] = result[0] + result[1];
	if (nodeVal[root][1] > max) max = nodeVal[root][1];
	return max;
}
int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	int n;
	cin >> n;
	vector<circle> nodes(n + 1);
	vector<vector<int>> nodeVal(n + 1);
	nodeVal[0].resize(2);
	//make tree
	for (int i = 1; i <= n; i++) {
		cin >> nodes[i].x >> nodes[i].y >> nodes[i].r;
		nodeVal[i].resize(2);
	}
	sort(nodes.begin(), nodes.end(), comp);
	for (int i = 1; i <= n; i++) {
		nodes[i].parent = 0;
		int root(0);
		if (i == 1) {
			nodes[root].children.push_back(i);
			continue;
		}

		bool isInserted = false;
		for (int j = 0; j < nodes[root].children.size(); j++) {
			int child = nodes[root].children[j];
			long long pow_dy = pow(nodes[child].y - nodes[i].y,2);
			long long pow_dx = pow(nodes[child].x - nodes[i].x,2);
			if ((double)abs(nodes[child].r- nodes[i].r) > sqrt(pow_dy + pow_dx)) {
				if (nodes[child].r > nodes[i].r) {
					root = child;
					j = -1;
					continue;
				}
				else {
					//insert
					nodes[child].parent = i;
					nodes[root].children[j] = i;
					nodes[i].parent = root;
					isInserted = true;
					break;
				}
			}
		}
		if (!isInserted) {
			nodes[i].parent = root;
			nodes[root].children.push_back(i);
		}
	}
	cout << dfs(nodes, nodeVal, 0, 0);
	return 0;
}
