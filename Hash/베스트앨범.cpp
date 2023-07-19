#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

struct GenreInfo{
    long playCount = 0;
    int top2[2] = {-1,-1};
};

bool compare(pair<string,GenreInfo>a, pair<string,GenreInfo>b){
    return a.second.playCount > b.second.playCount;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    unordered_map<string, GenreInfo> category;
    for(int i = 0; i < plays.size(); i++){
        if(category.count(genres[i]) > 0){
            GenreInfo* info = &category[genres[i]];
            info->playCount += plays[i];
            if(info->top2[1] == -1){
                if(plays[info->top2[0]] < plays[i]){
                    info->top2[1] = info->top2[0];
                    info->top2[0] = i;    
                }
                else{
                    info->top2[1] = i;    
                }
            }
            else if(plays[info->top2[0]] < plays[i] || (plays[info->top2[0]] == plays[i] && info->top2[0] > i)){
                info->top2[1] = info->top2[0];
                info->top2[0] = i;
            }
            else if(plays[info->top2[1]] < plays[i] || (plays[info->top2[1]] == plays[i] && info->top2[1] > i)){
                info->top2[1] = i;
            }
        }
        else{
            GenreInfo temp;
            temp.playCount += plays[i];
            temp.top2[0] = i; 
            category.insert({genres[i], temp});
        }
    }
    
    vector<pair<string, GenreInfo>> sortedCategory(category.begin(), category.end());
    sort(sortedCategory.begin(), sortedCategory.end(), compare);
    
    for(int i = 0; i < sortedCategory.size(); i++){
        for(int j : sortedCategory[i].second.top2){
            if(j > -1) answer.push_back(j);
        }
    }
    return answer;
}
