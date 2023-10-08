#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    int helpNum = 0;
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());
    for(int i = 0; i < lost.size(); i++){
        for(int j = 0; j < reserve.size(); j++){
            int diff = reserve[j] - lost[i];
            if(diff == 0){
                lost[i] = -1;
                reserve[j] = -1;
                helpNum++;
                break;
            }
        }
    }    
    for(int i = 0; i < lost.size(); i++){
        if(lost[i] == -1) continue;
        for(int j = 0; j < reserve.size(); j++){
            if(reserve[j] == -1) continue;
            int diff = reserve[j] - lost[i];
            if(diff == 1 || diff == -1){
                helpNum++;
                reserve[j] = -1;
                break;
            }
        }
    }
    answer = n - lost.size() + helpNum;
    return answer;
}
