#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    int left_idx = 0;
    int right_idx = people.size() - 1; 
    sort(people.begin(), people.end());
    while(right_idx > left_idx){
        if(people[left_idx] + people[right_idx] <= limit){
            left_idx++;
            right_idx--;
        }
        else{
            right_idx--;
        }
        answer++;
        if(left_idx == right_idx){
            answer++;
            break;
        }
    }
    return answer;
}
