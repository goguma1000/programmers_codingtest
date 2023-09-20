#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(int a, int b){
    if(a > b) return true;
    else return false;
}
int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.begin(), citations.end(), compare);
    int index = 0;
    while(index < citations.size()){
        int h = citations[index];
        while(1){
            if(index == citations.size()) break;
            if(citations[index] == h) index++;
            else break;
        }
        
        if(h <= index){
            answer = h > answer ? h : answer;
            break;
        }
        else answer = index;
    }
    return answer;
}
