#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    if(op_start <= pos && pos <= op_end) pos = op_end;
    string answer = pos;
    for(string cmd : commands){
        int cur_min = stoi(answer.substr(0,2));
        int cur_sec = stoi(answer.substr(3,2));
        if(cmd.compare("prev") == 0){
            int temp = cur_sec - 10;
            if(temp < 0){
                cur_sec = cur_min == 0 ? 0 : temp + 60;
                cur_min = cur_min > 0 ? cur_min -1 : 0;
            }
            else cur_sec = temp;
        }
        else if(cmd.compare("next") == 0){
            cur_min += (cur_sec + 10) / 60;
            cur_sec = (cur_sec + 10) % 60;
        }
        answer = "";
        if(cur_min < 10){
            answer += '0';
        }
        answer += to_string(cur_min);
        answer += ':';
        if(cur_sec < 10){
            answer += '0';
        }
        answer += to_string(cur_sec);
        if(op_start <= answer && answer <= op_end) answer = op_end;
        else if(answer > video_len) answer = video_len;
    }
    return answer;
}
