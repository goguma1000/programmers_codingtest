#include<iostream>
#include<stdio.h>
#include<vector>

//bst는 왼쪽 서브트리는 서브트리의 루트보다 작은 값, 오른쪽 서브트리는 큰값.
//post order traversal은 left right mid
void Post_Order(const std::vector<int>& stream, int start, int end) {
	if (start == end) {
		std::cout << stream[start] << "\n";
		return;
	}
	if (start > end) return;
	int leftEnd = start + 1;
	while (leftEnd <= end) {
		if (stream[start] < stream[leftEnd]) break;
		++leftEnd;
	}
	Post_Order(stream, start + 1, leftEnd - 1);
	Post_Order(stream, leftEnd, end);
	std::cout << stream[start] << "\n";
}
int main() {
	int n = 0;
	std::vector<int>stream;
	while (std::cin >> n) {
		stream.push_back(n);
	}
	Post_Order(stream, 0, stream.size()-1);
	return 0;
}
