//벌금의 합은 overflow될 수 있음.
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <map>
#include <algorithm>
using namespace std;
const int Hour2min = 60;
const int Day2min = Hour2min * 24;
const int md[12] = { 0,31,28,31,30,31,30,31,31,30,31,30 };
struct TimeInfo {
	int timeMin = 0;
	TimeInfo() {};
	TimeInfo(int month, int day, int hour, int min) {
		timeMin = day * Day2min + hour * Hour2min + min;
		int sum = 0;
		for (int i = 0; i < month; i++) {
			sum += md[i];
		}
		timeMin += sum * Day2min;
	}
};
int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	int n, f;
	cin >> n;
	string rentalPeriod;
	cin >> rentalPeriod;
	cin >> f;
	int rentalPeriod_min = stoi(rentalPeriod.substr(0, 3)) * Day2min
		+ stoi(rentalPeriod.substr(4, 2)) * Hour2min
		+ stoi(rentalPeriod.substr(7, 2));
	map<pair<string, string>, TimeInfo> map;
	unordered_map<string, long long> result;
	for (int i = 0; i < n; i++) {
		string date, time, type, id;
		cin >> date >> time >> type >> id;
		TimeInfo info(stoi(date.substr(5, 2)), stoi(date.substr(8, 2)), stoi(time.substr(0, 2)), stoi(time.substr(3, 2)));
		pair<string, string> temp = { type, id };
		if (map.find(temp) == map.end()) {
			//대여
			map.insert({ temp,info });
		}
		else {
			//반납
			auto& time = map[temp];
			int diff = info.timeMin - time.timeMin - rentalPeriod_min;
			if (diff > 0) {
				int fine = diff * f;
				if (result.find(temp.second) == result.end()) result.insert({ temp.second, static_cast<long long>(fine) });
				else result[temp.second] += static_cast<long long>(fine);
			}
			map.erase(temp);
		}
	}
	vector<pair<string, long long>> sorted_result(result.begin(), result.end());
	sort(sorted_result.begin(), sorted_result.end(), less<pair<string, int>>());
	if (sorted_result.size() == 0) cout << -1;
	else {
		for (auto data : sorted_result) {
			cout << data.first << ' ' << data.second << '\n';
		}
	}
	return 0;
}

