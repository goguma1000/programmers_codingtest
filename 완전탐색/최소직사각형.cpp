#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    int maxWidth = 0, maxHeight = 0;
    for(int i = 0; i < sizes.size(); i++){
        if(sizes[i][0] < sizes[i][1]){
            int temp = sizes[i][0];
            sizes[i][0] = sizes[i][1];
            sizes[i][1] = temp;
        }
        maxWidth = maxWidth > sizes[i][0] ? maxWidth : sizes[i][0];
        maxHeight = maxHeight > sizes[i][1] ? maxHeight : sizes[i][1];
    }
    answer = maxWidth * maxHeight;
    return answer;
}
