#include <string>
#include <vector>
#include <queue>
using namespace std;
//bfs
int solution1(vector<int> numbers, int target) {
    int answer = 0;
    int queueindex = 0;
    queue<int> queue;
    for(int i = 0; i < numbers.size(); i++){
        if(i == 0){
            queue.push(0+numbers[i]);
            queue.push(0-numbers[i]);
            continue;
        }
        int beforeQSize = queue.size();
        for(int j = 0; j < beforeQSize; j++){
            int temp = queue.front();
            queue.push(temp + numbers[i]);
            queue.push(temp - numbers[i]);
            queue.pop();
        }
    }
    
    while(!queue.empty()){
        if(queue.front() == target) answer++;
        queue.pop();
    }
    return answer;
}
//bfs
int solution2(vector<int> numbers, int target) {
    int answer = 0;
    int queueindex = 0;
    vector<int> queue;
    for (int i = 0; i < numbers.size(); i++) {
        if (i == 0) {
            queue.push_back(0 + numbers[i]);
            queue.push_back(0 - numbers[i]);
            continue;
        }
        int beforeQSize = queue.size();
        for (int j = queueindex; j < beforeQSize; j++) {
            queue.push_back(queue[j] + numbers[i]);
            queue.push_back(queue[j] - numbers[i]);
        }
        queueindex = beforeQSize;
    }

    for (int k = queueindex; k < queue.size(); k++) {
        if (queue[k] == target) answer++;
    }
    return answer;
}
