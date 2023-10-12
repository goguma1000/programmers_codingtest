#include <string>
#include <vector>
using namespace std;

string solution(string number, int k) {
    string answer = "";
    int pickCount = number.length() - k;
    int cur_picked = -1;

    while(k > 0 && pickCount != 0){
        int max_idx = -1;
        int max = -1;
        for(int i = cur_picked + 1 ; i + pickCount - 1 < number.length(); i++){
            int temp = number[i] - '0'; 
            if(max < temp){
                max = temp;
                max_idx = i;
            }
        }
        if(max_idx == -1) break;
        answer += (max + '0');
        k -= (max_idx - cur_picked - 1);
        cur_picked = max_idx;
        pickCount--;
    }
    if(pickCount != 0) answer += number.substr(cur_picked + 1, number.length());
    return answer;
}
