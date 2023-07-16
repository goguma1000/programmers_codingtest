#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    unordered_map<string, int> categorizedCloset;
    for (vector<string> v : clothes) {
        if (categorizedCloset.count(v[1]) != 0) categorizedCloset[v[1]] += 1;
        else categorizedCloset.insert({ v[1], 2 });
    }
    for (pair<string, int> c : categorizedCloset) {
        answer *= c.second;
    }
    return answer - 1;
}
