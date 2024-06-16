#include<iostream>

int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	int n;
	std::cin >> n;
	if (n % 2 != 0) std::cout << "SK";
	else std::cout << "CY";
	return 0;
}
