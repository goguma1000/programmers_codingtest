#include <string>
#include <vector>
#include <queue>
using namespace std;

struct node{
    string value;
    int index;
    node(string s, int i): value(s), index(i){};
};

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    vector<bool> inQueue;
    queue<node> q;
    
    for(int i = 0; i < words.size(); i++) {inQueue.push_back(false);}
    
    do{
        int loopcount = q.size() != 0 ? q.size() : 1;
        for(int k = 0; k < loopcount; k++){
            if(!q.empty()){
                 node n = q.front();
                inQueue[n.index] = true;
                if(target.compare(n.value) == 0) return answer;
                begin = n.value;
                q.pop();
            }
            for(int i = 0; i < words.size(); i++){
            
                int diff = 0;
            
                if(inQueue[i]) continue;
            
                for(int j = 0; j < begin.size(); j++){
                    int temp = begin[j] - words[i][j];
                    diff = temp != 0 ? diff+1 : diff;
                }   
            
                if(diff == 1){
                    q.push(node(words[i],i));
                }
            }
        }
        answer++;
    }while(!q.empty());
    
    answer = 0;
    return answer;
}
