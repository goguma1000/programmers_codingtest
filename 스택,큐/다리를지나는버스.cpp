#include <string>
#include <vector>
#include <queue>

using namespace std;
struct node{
    int weight;
    int inTime;
    node(int weight, int inTime):weight(weight),inTime(inTime){};
};

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int cur_weight = 0;
    int truck_idx = 0;
    int truckNum =truck_weights.size();
    queue<node> q;
    if(truck_weights[0] > weight) return 0;
    while(truck_idx != truckNum || !q.empty()){
        int i = 1;
        while(!(truck_idx == truckNum || cur_weight + truck_weights[truck_idx] > weight)){
            if(!q.empty()){
                node n = q.front();
                if(answer + i - n.inTime > bridge_length - 1){
                    cur_weight -= n.weight;
                    q.pop();
                }
            }
            cur_weight += truck_weights[truck_idx];
            q.push(node(truck_weights[truck_idx], answer + i));
            truck_idx++;
            i++;
        }
        node n = q.front();
        answer = n.inTime + bridge_length - 1;
        cur_weight -= n.weight;
        q.pop();
    }
    return answer + 1;
}
