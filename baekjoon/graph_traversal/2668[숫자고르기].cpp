#include<iostream>
#include<vector>
#include<set>

std::set<int> result;
void PushSet(const std::vector<int>& arr, std::vector<bool>& pushed, int start, int end) {
	while (true) {
		result.insert(start);
		pushed[start] = true;
		if (start == end) break;
		start = arr[start];

	}
}
void DFS(const std::vector<int>& arr, std::vector<bool>& visited, std::vector<bool>& pushed, int idx) {
	visited[idx] =  true;
	int next(arr[idx]);
	if (visited[next]) {
		PushSet(arr, pushed, next, idx);
	}
	else {
		DFS(arr, visited, pushed, next);
	}
}
int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	int N;
	std::cin >> N;
	std::vector<int> arr(N + 1);
	std::vector<bool> pushed(N + 1);
	for (int i = 1; i <= N; ++i) {
		std::cin >> arr[i];
	}
	std::vector<bool> visited(N + 1);
	for (int i = 1; i <= N; ++i) {
		if (pushed[i]) continue;
		else {
			DFS(arr, visited, pushed, i);
			visited.clear();
			visited.resize(N + 1);
		}
	}
	std::cout << result.size() << '\n';
	for (int v : result)std::cout << v << '\n';
	return 0;
}
