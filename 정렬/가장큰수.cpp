#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
vector<int> copyarr(vector<int>src){
    vector<int> result;
    for(int i = 0; i < src.size(); i++){
        result.push_back(src[i]);
    }
    return result;
}


bool compare(int a, int b){
    string s1 = to_string(a) + to_string(b);
    string s2 = to_string(b) + to_string(a);
    if(s1 > s2) return true;
    else return false;
}
void merge(vector<int>&src, int start, int mid ,int end, vector<int>&res){
    int i = start;
    int j = mid;
    for(int k = start; k < end; k++){
        if(i < mid && (j >= end || compare(src[i] , src[j]))){
            res[k] = src[i];
            i++;
        }
        else{
            res[k] = src[j];
            j++;
        }
    }
    
}
void mergesort(vector<int>&src, int start, int end, vector<int>&res){
    if(end - start <= 1){
        return;
    }
    int mid = (start + end) / 2;
    mergesort(res, start, mid, src);
    mergesort(res, mid, end, src);
    merge(src, start, mid, end ,res);
}
string solution(vector<int> numbers) {
    string answer = "";
    vector<int> res = copyarr(numbers);
    mergesort(numbers, 0, numbers.size(), res);
    for(int i : res){
       answer += to_string(i);
    }
    if(answer[0] == '0') return "0";
    return answer;
}
