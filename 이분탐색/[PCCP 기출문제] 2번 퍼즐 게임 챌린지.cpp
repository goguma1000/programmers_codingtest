#include <string>
#include <vector>

using namespace std;
int binary_search(const vector<int>& diffs, const vector<int>& time, int low, int high, const long long limit){
    if(low == high) return low;
    int level = (low + high) / 2;
    long long cur_time = 0;
    bool isFail = false;
    for(int i = 0; i < diffs.size(); i++){
        long long temp =0; 
        if(diffs[i] <= level){
            temp = (long long)time[i];
        }
        else{
            temp = static_cast<long long>(diffs[i] - level) * static_cast<long long>(time[i -1] + time[i])
                   + static_cast<long long>(time[i]);
        }
        if(cur_time > limit || limit - cur_time < temp) {
            isFail = true;
            break;
        }
        else{
            cur_time += temp;
        }
    }
    if(isFail) return binary_search(diffs, time, level + 1, high, limit);
    else return binary_search(diffs, time, low, level, limit);
}

int solution(vector<int> diffs, vector<int> times, long long limit) {
    int answer = 0;
    int high = 0;
    int low = 100001;
    for(int i = 0; i < diffs.size(); i++){
        high = high < diffs[i] ? diffs[i] : high;
        low = low > diffs[i] ? diffs[i] : low;
    }
    answer = binary_search(diffs, times, low, high, limit);
    return answer;
}
