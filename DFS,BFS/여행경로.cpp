#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

bool comp(string s1, string s2){
    return s1 < s2;
}

void dfs(unordered_map<string, vector<string>> m, string TO, vector<string> path, int maxDepth, vector<string>& answer){
    if(!answer.empty()) return;
    
    path.push_back(TO); 
    for(int i = 0; i < m[TO].size(); i++){
        if(m[TO][i].compare("") != 0){
            string temp = m[TO][i];
            m[TO][i] = "";
            dfs(m,temp, path, maxDepth, answer);
            m[TO][i] = temp;
        }
    }
    
    if(path.size() == maxDepth && answer.empty()){
        answer = path;
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    unordered_map<string, vector<string>> m;
    for(int i = 0; i < tickets.size(); i++){
        if(m.count(tickets[i][0]) == 0){
            vector<string> v;
            v.push_back(tickets[i][1]);
            m.insert(pair<string, vector<string>>(tickets[i][0],v));
        }
        else{
           m[tickets[i][0]].push_back(tickets[i][1]); 
        }
    }
    
    for(pair<string,vector<string>> p : m){
        sort(m[p.first].begin(), m[p.first].end(), comp);
    }
    
    vector<string> path;
    dfs(m, "ICN", path,tickets.size() + 1, answer);
    return answer;
}
