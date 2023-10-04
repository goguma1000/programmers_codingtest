#include <string>
#include <vector>
#include <queue>

using namespace std;
struct node{
    int priority;
    int location;
    node(int p, int l): priority(p), location(l){};
};

int solution(vector<int> priorities, int location) {

    int answer = 0;
    int priority[9] = {0,0,0,0,0,0,0,0,0};
    queue<node> q;
    for(int i = 0; i < priorities.size(); i++){
        q.push(node(priorities[i], i));
        priority[priorities[i] - 1]++;
    }
    for(int cur_priority = 8; cur_priority > -1 ; cur_priority--){
        if(priority[cur_priority] == 0) continue;
        while(priority[cur_priority] != 0){
            node n = q.front();
            if(n.priority == cur_priority + 1) {
                if(n.location == location) return answer + 1;
                priority[cur_priority]--;
                answer++;
            }
            else q.push(n);
            q.pop();
        }
    }
}
