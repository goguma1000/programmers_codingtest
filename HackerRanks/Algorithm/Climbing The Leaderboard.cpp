vector<int> climbingLeaderboard(vector<int> ranked, vector<int> player) {
    int cur_Score = ranked.size();
    int cur_Rank = ranked.size();
    vector<int> ranks ={1};
    vector<int> answer;
    for(int i = 1; i < ranked.size(); i++){
        if(ranked[i - 1] == ranked[i]) ranks.push_back(ranks[i - 1]);
        if(ranked[i - 1] > ranked[i]) ranks.push_back(ranks[i - 1] + 1);
    }

    for(int i = 0; i < player.size(); i++){
        cur_Score = player[i];
        if(i != 0 && player[i] == player[i - 1]) {
            answer.push_back(answer[answer.size()-1]);
            continue;
        }
        for(int  j = cur_Rank - 1; j >= 0; j--){
            cur_Rank = j + 1;
            if(cur_Score > ranked[j]) {
                if(j == 0) {
                    answer.push_back(1);
                    break;
                }
                continue;
            }
            else if( cur_Score == ranked[j]){
                answer.push_back(ranks[j]);
                break;
            }
            else{
                answer.push_back(ranks[j] + 1);
                break;
            }
        }
        
    }
    return answer;
}
