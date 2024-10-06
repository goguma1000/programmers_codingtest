#include <iostream>
#include <vector>

using namespace std;
struct Node {
	int parent = -1;
	int left = -1;
	int right = -1;
};

int in_order_like_traversal(const vector<Node>& tree, int root, int end) {
	int sum = -1;
	int cur = root;
	vector<bool> visited(tree.size() + 1, false);
	while (true) {
		visited[cur] = true;
		if (tree[cur].left > 0 && !visited[tree[cur].left]) {
			cur = tree[cur].left;
		}
		else if (tree[cur].right > 0 && !visited[tree[cur].right]) {
			cur = tree[cur].right;
		}
		else if (cur == end) {
			++sum;
			break;
		}
		else if (tree[cur].parent > 0) {
			cur = tree[cur].parent;
		}
		++sum;
	}
	return sum;
}

int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	int n;
	cin >> n;
	vector<Node> tree(n + 1);
	for (int i = 0; i < n; i++) {
		int num, l, r;
		cin >> num >> l >> r;
		tree[num].left = l;
		tree[num].right = r;
		if(l > 0) tree[l].parent = num;
		if(r > 0) tree[r].parent = num;
	}
	int root = 1;
	int end = 1;
	while (true) {
		if (tree[root].right < 0) {
			end = root;
			break;
		}
		else root = tree[root].right;
	}
	cout << in_order_like_traversal(tree, 1, end);
	return 0;
}
