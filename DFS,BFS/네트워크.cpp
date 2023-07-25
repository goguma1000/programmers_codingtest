#include <string>
#include <vector>

using namespace std;

void dfs(vector<vector<int>>&computers, int n, int from, int to){
    if(computers[to][to] == 0) return;
    else computers[to][to] = 0;
    
    computers[to][from] = 0;                   
    
    for(int i = 0; i < n; i++){
        if(computers[to][i] != 0){
            computers[to][i] = 0;
            dfs(computers, n, to, i);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    for(int i = 0; i < n; i++){
        if(computers[i][i] == 1){
            answer++;
            dfs(computers, n, i, i);
        }
    }
    return answer;
}
