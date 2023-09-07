#include <string>
#include <vector>
#include <cmath>
using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    float linear = (brown + 4) / 2;
    float constant = brown + yellow;
    int width = (linear + sqrtf(linear * linear - 4 * constant)) / 2;
    int height = (brown - 2 * width) / 2 + 2;
    answer = {width, height};
    return answer;
}
