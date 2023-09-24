#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int nextWork = 0;
    while(nextWork != progresses.size()){
        for(int i = 0; i < progresses.size(); i++){
            progresses[i]  = progresses[i] + speeds[i] > 100 ? 100 : progresses[i] + speeds[i];
        }
        int preWork = nextWork;
        while(nextWork != progresses.size()){
            if(progresses[nextWork] >= 100) nextWork++;
            else break;
        }
        int temp = nextWork - preWork;
        if(temp != 0) answer.push_back(temp);
    }
    return answer;
}
