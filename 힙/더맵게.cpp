#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq(scoville.begin(), scoville.end());
    
    while(pq.size() > 1 && pq.top() < K){
        int v1 = pq.top();
        pq.pop();
        int v2 = pq.top();
        pq.pop();
        pq.push(v1 + 2 * v2);
        answer++;
    }
    if(pq.top() < K) return -1;
    else return answer;
}
