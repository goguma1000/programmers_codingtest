#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(vector<int> a, vector<int> b){
    if(a[0] < b[0]) return true;
    else return false;
}

int solution(vector<vector<int>> routes) {
    int answer = 0;
    vector<vector<int>> overlap_routes;
    sort(routes.begin(), routes.end(), compare);
    for(int  i = 0; i < routes.size(); i++){
        bool isOverlap = false;
        for(int j = 0; j < overlap_routes.size(); j++){
            if((overlap_routes[j][0] <= routes[i][0] && routes[i][0] <= overlap_routes[j][1]) 
               || (overlap_routes[j][0] <= routes[i][1] && routes[i][1] <= overlap_routes[j][1])){
                isOverlap = true;
                overlap_routes[j][0] = routes[i][0] > overlap_routes[j][0] ? routes[i][0] : overlap_routes[j][0];
                overlap_routes[j][1] = routes[i][1] < overlap_routes[j][1] ? routes[i][1] : overlap_routes[j][1];
                break;
            } 
        }
        if(!isOverlap)  overlap_routes.push_back(routes[i]);
    }
    answer = overlap_routes.size();

    return answer;
}
