#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
bool comp(vector<int> a,  vector<int> b){
    if(a[0] < b[0]) return true;
    else return false;
}
int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int cur_time = 0;
    int min_idx = 0;
    sort(jobs.begin(), jobs.end(), comp);
    for(int i = 0; i < jobs.size(); i++){
        int min_procTime = -1;
        bool isWorking = false;
        
        for(int j = 0; j < jobs.size(); j++){
            if(jobs[j][0] == -1) continue;
            if(cur_time < jobs[j][0]) break;
            if(min_procTime == -1 || min_procTime > jobs[j][1]){
                min_procTime = jobs[j][1];
                min_idx = j;
                isWorking = true;
            }
        }
        
        if(isWorking){
            answer += jobs[min_idx][1] + cur_time - jobs[min_idx][0];
            cur_time += jobs[min_idx][1];
            jobs[min_idx][0] = -1;
        }
        else{
            int next_reqTime = -1;
            for(int j = 0; j < jobs.size(); j++){
                if(jobs[j][0] != -1){
                    if(next_reqTime == -1) {
                        next_reqTime = jobs[j][0];
                        min_idx = j;
                    }
                    else if(next_reqTime == jobs[j][0] && jobs[j][1] < jobs[min_idx][1]){
                        min_idx = j;
                    }
                    else break;
                }
            }
            answer += jobs[min_idx][1];
            cur_time += jobs[min_idx][1] + jobs[min_idx][0] - cur_time;
            jobs[min_idx][0] = -1;
        }
    }
    return answer / jobs.size();
}
