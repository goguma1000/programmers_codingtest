#include<iostream>
int main() {
	int n;
	std::cin >> n;
	long long Fi_2 = 0, Fi_1 = 1;
	long long Fi = 0;
	for (int i = 2; i <= n; i++) {
		Fi = Fi_2 + Fi_1;
		Fi_2 = Fi_1;
		Fi_1 = Fi;
	}
	if (n == 1) std::cout << Fi_1;
	else std::cout << Fi;
	return 0;
}
