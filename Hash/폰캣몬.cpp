#include <vector>
#include <map>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    map<int,int> species;
    for(int i  : nums){
        if(species.count(i) == 0) species.insert({i,1});
    }
    answer = species.size() < nums.size()/2 ? species.size() : nums.size()/2;
    return answer;
}
