//답봄
//각 좌표별로 졍렬까지는 생각했고, x,y,z별 거리를 따로 볼 생각도 했지만 무조건 맞나는 확신이 없어서 시도하지 않음. 근데 그게 맞았음.
//union-find사용. find할 때 parent를 업데이트 하지 않으면 최악의 경우 부모를 찾을때 n의 시간이 걸림. 
//따라서 find연산 수행할 때마다 parent를 업데이트 하여 찾는 속도를 상수time으로 유지.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int Find(vector<int>& parents,int x) {
	if (parents[x] == x) return x;
	else return parents[x] = Find(parents, parents[x]);
}
int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	int n;
	cin >> n;
	vector<pair<int, int>>xPos(n);
	vector<pair<int, int>>yPos(n);
	vector<pair<int, int>>zPos(n);
	for (int i = 0; i < n; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		xPos[i] = { x,i };
		yPos[i] = { y,i };
		zPos[i] = { z,i };
	}
	sort(xPos.begin(), xPos.end());
	sort(yPos.begin(), yPos.end());
	sort(zPos.begin(), zPos.end());
	vector<pair<int, pair<int, int>>> edges;
	for (int i = 0; i < n - 1; i++) {
		edges.push_back({ abs(xPos[i].first - xPos[i + 1].first), {xPos[i].second, xPos[i + 1].second} });
		edges.push_back({ abs(yPos[i].first - yPos[i + 1].first), {yPos[i].second, yPos[i + 1].second} });
		edges.push_back({ abs(zPos[i].first - zPos[i + 1].first), {zPos[i].second, zPos[i + 1].second} });
	}
	sort(edges.begin(), edges.end());
	vector<int> parent(n);
	for (int i = 0; i < n; i++) {
		parent[i] = i;
	}
	int totalCost = 0;
	for (int i = 0; i < edges.size(); i++) {
		int cost = edges[i].first;
		auto& ab = edges[i].second;
		int parentA = Find(parent, ab.first);
		int parentB = Find(parent, ab.second);
		//부모가 같으면 사이클.
		if (parentA != parentB) {
			totalCost += cost;
			//union
			parent[parentB] = parentA;
		}
	}
	cout << totalCost;
	return 0;
}
