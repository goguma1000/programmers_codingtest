#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for(int p = 0; p < commands.size(); p++){
        vector<int>temp;
        int i = commands[p][0];
        int j = commands[p][1];
        int k = commands[p][2];
        for(; i <= j; i++){
            temp.push_back(array[i - 1]);
        }
        sort(temp.begin(), temp.end());
        answer.push_back(temp[k - 1]);
    }
    return answer;
}
