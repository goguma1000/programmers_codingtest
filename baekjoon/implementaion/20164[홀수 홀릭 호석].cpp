#include <iostream>
#include <vector>
#include <string>
#include <climits>
using namespace std;
int Cut2(string n, int sum) {
	int t1 = (n[0] - '0');
	int t2 = (n[1] - '0');
	if (t1 % 2 != 0) sum++;
	if (t2 % 2 != 0) sum++;
	t1 += t2;
	if (t1 > 9) {
		string temp = to_string(t1);
		return Cut2(temp, sum);
	}
	else {
		if (t1 % 2 != 0) return sum + 1;
		else return sum;
	}
}

int* Cut3(string n, int p1, int p2, int sum, int minmax[2]) {
	for (int i = 0; i < n.length(); i++) {
		if ((n[i] - '0') % 2 != 0) sum++;
	}
	int t1 = stol(n.substr(0, p1));
	int t2 = stoi(n.substr(p1, p2 - p1));
	int t3 = stoi(n.substr(p2,n.length()));
	t1 = t1 + t2 + t3;
	string temp = to_string(t1);
	if (temp.length() >= 3) {
		for (int i = 1; i < temp.length() - 1; i++) {
			for (int j = i + 1; j < temp.length(); j++) {
				int* result;
				result = Cut3(temp, i, j, sum, minmax);
				minmax[0] = minmax[0] > *result ? *result : minmax[0];
				minmax[1] = minmax[1] < *(result + 1)? *(result + 1) : minmax[1];
			}
		}
	}
	else {
		if (temp.length() == 2) {
			sum = Cut2(temp, sum);
		}
		else if (temp.length() == 1) {
			if (t1 % 2 != 0) sum++;
		}
		minmax[0] = minmax[0] > sum ? sum : minmax[0];
		minmax[1] = minmax[1] < sum ? sum : minmax[1];
	}
	return minmax;
}
int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	string n;
	cin >> n;
	int min = INT_MAX;
	int max = 0;
	int sum = 0;
	if (n.length() == 1) {
		if ((n[0] - '0') % 2 != 0) sum++;
	}
	else if (n.length() == 2) {
		sum+=Cut2(n, sum);
	}
	else {
		for (int i = 1; i < n.length() - 1; i++) {
			for (int j = i + 1; j < n.length(); j++) {
				int* temp;
				int minmax[2] = { min,max };
				temp = Cut3(n, i, j, sum, minmax);
				min = min > *temp ? *temp : min;
				max = max < *(temp+1) ?  *(temp + 1) : max;
			}
		}
	}
	if (n.length() < 3) {
		min = min > sum ? sum : min;
		max = max < sum ? sum : max;
	}
	cout << min << ' ' << max;
	return 0;
}
