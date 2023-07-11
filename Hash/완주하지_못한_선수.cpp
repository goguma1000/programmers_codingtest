#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    map<string, int> cmap;
  
    for (string c : completion) {
        if (cmap.count(c) != 0) cmap[c] += 1;
        else cmap.insert({ c,1 });
    }

    for (string p : participant) {
        cmap[p] -=1;
        if(cmap[p] < 0) {
            answer = p;
            break;
        }
    }
    
    return answer;
}
