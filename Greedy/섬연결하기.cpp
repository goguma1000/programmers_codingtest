#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(vector<int> a, vector<int>b){
    if(a[2] < b[2]) return true;
    else return false;
}

int find(int x, vector<int> np){
    if(np[x] == x) return x;
    else return find(np[x], np);
}

int kruskal(vector<vector<int>> costs, int n){
    
    vector<int> node_parent;
    int cost = 0;
    sort(costs.begin(), costs.end(), compare);
    
    for(int i = 0; i < n; i++){
        node_parent.push_back(i);
    }
    
    for(int i = 0; i < costs.size(); i++){
        int lParent = find(costs[i][0], node_parent);
        int rParent = find(costs[i][1], node_parent);
        if(lParent != rParent){
            node_parent[rParent] = lParent;
            cost += costs[i][2];
        } 
    }

    return cost;
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    answer = kruskal(costs, n);
    return answer;
}
