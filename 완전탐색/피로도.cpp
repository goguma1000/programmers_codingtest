#include <string>
#include <vector>
#include <iostream>

using namespace std;
void permutation(vector<vector<int>> dungeons,int k , int count ,int& max){
    if(max < count){
        max = count;
    }

    for(int i = 0; i < dungeons.size(); i++){
        if(dungeons[i][0] == -1 || dungeons[i][0] > k) continue;
        int temp = dungeons[i][0];
        dungeons[i][0] = -1;
        permutation(dungeons, k - dungeons[i][1], count + 1, max);
        dungeons[i][0] = temp;
    }

}
int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    int max = 0;
    permutation(dungeons, k, 0, max);
    answer = max;
    return answer;
}
