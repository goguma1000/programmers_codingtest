#include<iostream>
#include<stdio.h>
#include<vector>

int main() {
	int n;
	std::cin >> n;
	int Fi_2 = 0, Fi_1 = 1;
	int Fi = 0;
	for (int i = 2; i <= n; i++) {
		Fi = Fi_2 + Fi_1;
		Fi_2 = Fi_1;
		Fi_1 = Fi;
	}
	if (n == 0) std::cout << Fi_2;
	else if (n == 1) std::cout << Fi_1;
	else std::cout << Fi;
	return 0;
}
