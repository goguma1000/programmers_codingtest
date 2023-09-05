#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int s1[5] = {1,2,3,4,5};
    int s2[8] = {2,1,2,3,2,4,2,5};
    int s3[10] = {3,3,1,1,2,2,4,4,5,5};
    int count[3] = {0,0,0};
    //1번 1-2-3-4-5
    //2번 2-1-2-3-2-4-2-5
    //3번 3-3-1-1-2-2-4-4-5-5
    //채점
    for(int i = 0; i < answers.size(); i++){
        if(s1[i % 5] == answers[i])
            count[0] += 1;
        if(s2[i % 8] == answers[i])
            count[1] += 1;
        if(s3[i % 10] == answers[i])
            count[2] += 1;
    } 
    vector<int>index = {0,1,2};
    
    for(int i = 0; i < index.size(); i++){
        for(int j = 0; j < index.size() - 1; j++){
            if(count[index[j]] < count[index[j + 1]]){
                cout<<index[0]<<index[1]<<index[2]<<endl;
                swap(index[j], index[j + 1]);
            }
            else if(count[index[j]] == count[index[j+1]]){
                if(index[j] > index[j+1]){
                    cout<<index[0]<<index[1]<<index[2]<<endl;
                    swap(index[j], index[j + 1]);
                }
            }
        }
    }
    answer.push_back(index[0] + 1);
    for(int i = 1; i < index.size(); i++){
        if(count[index[0]] == count[index[i]])
            answer.push_back(index[i] + 1);
    }
    return answer;
}

void swap(int& a, int& b){
    int temp = a;
    a = b;
    b = temp;
}
