#include<iostream>
#include<stdio.h>
#include<vector>

int main() {
	int n(0);
	double w(0), leafNum(0);
	std::vector<int> graph;
	std::cin >> n >> w;
	graph.resize(n);
	for (int i = 0; i < n - 1; i++) {
		int n1, n2;
		std::cin >> n1 >> n2;
		graph[n1 - 1]++;
		graph[n2 - 1]++;
	}
	for (int i = 1; i < n; i++) {
		if (graph[i] == 1) ++leafNum;
	}
	printf("%.10f", w / leafNum);
}
