#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    priority_queue<int> pq;
    for(int i = 0; i < operations.size(); i++){
        char operation = operations[i][0];
        int value = stoi(operations[i].substr(2, operations[i].length()));
        switch(operation){
            case 'I':
                pq.push(value);
                break;
             case 'D':
                 if(pq.empty()) continue;
                 if(value == -1){
                    vector<int> temp;
                    while(!pq.empty()){
                        int cur_top = pq.top();
                        pq.pop();
                        if(!pq.empty())temp.push_back(cur_top);
                    }
                    for(int i = 0; i < temp.size(); i++){
                         pq.push(temp[i]);
                    }
                }
                if(value == 1){
                     pq.pop();
                }
                break;
            default: continue;
        }
    }
    if(pq.empty()) answer = {0,0};
    else{
        answer.push_back(pq.top());
        while(!pq.empty()){
            int cur_top = pq.top();
            pq.pop();
            if(pq.empty())answer.push_back(cur_top);
        }
    }
    return answer;
}
