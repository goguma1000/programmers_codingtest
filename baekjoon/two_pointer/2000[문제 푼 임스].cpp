//dp 문제인데 투포인터로 풂.
#include <iostream>
#include<algorithm>
#include <vector>
#include <cmath>
using namespace std;

int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	float c; 
	int n;
	cin >> c >> n;
	vector<int> solved(n);
	for (int i = 0; i < n; i++) {
		cin >> solved[i];
	}
	int leftStrick = c / 0.99;
	int useStrick = 0;
	int maxSolCount = 0;
	int maxDay = 0;
	int st = 0, end = 0;
	while(end < n){
		if (solved[end] > 0) {
			if (maxSolCount < solved[end]) maxSolCount = solved[end];
			end++;
		}
		else {
			if (leftStrick > 0 && useStrick != 2) {
				leftStrick--;
				useStrick++;
				end++;
			}
			else {
				if (st == end) {
					st++;
					end++;

				}
				else {
					int day = end - st;
					if (maxDay < day) maxDay = day;
					while (st <= end)
					{
						if (solved[st] > 0) {
							st++;
						}
						else {
							useStrick--;
							leftStrick++;
							st++;
							break;
						}
					}
				}
			}
		}
	}
	int day = end - st;
	if (maxDay < day) maxDay = day;
	cout  << maxDay << '\n' << maxSolCount;
	return 0; 
}
