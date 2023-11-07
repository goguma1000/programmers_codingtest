#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    sort(times.begin(), times.end());
    long long low = times[0];
    long long high = (long long)n * times[times.size() - 1];
    while(low <= high){
        long long mid = (low + high) / 2;
        long long processibleN = 0;
        for(int i = 0; i < times.size(); i++){
            processibleN += mid / times[i];
            if(processibleN > n) break;
        }
        if(processibleN >= n){
            high = mid - 1;
            if(answer == 0) answer = mid;
            else answer = mid < answer ? mid : answer;
        } 
        else low = mid + 1;
    }
    return answer;
}
