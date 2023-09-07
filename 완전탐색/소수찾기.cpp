#include <string>
#include <vector>
#include <unordered_set>
#include <cmath>

using namespace std;
unordered_set<int> primeNums;
void permutation(vector<int> cards, int r, int depth, string number){
    
    if(depth == r){
        primeNums.insert(stoi(number));
        return;
    }
    
    for(int i = 0; i < cards.size(); i++){
        if(cards[i] == -1) continue;
        int temp = cards[i];
        number += to_string(cards[i]);
        cards[i] = -1;
        permutation(cards, r, depth + 1, number);
        number = number.substr(0, number.length() - 1);
        cards[i] = temp;
    }
    
}

bool checkPrimeNum(int num){
    if(num == 0 || num == 1) return false;
    if(num == 2) return true;
    for(int i = 2; i < sqrtf(num) + 1; i++){
        if(num % i == 0) return false;
    }
    return true;
}

int solution(string numbers) {
    int answer = 0;
    vector<int> cards;
    for(int i = 0; i < numbers.length(); i++){
        cards.push_back(numbers[i] - '0');
    }
    
    for(int i = 1; i <= numbers.length(); i++){
        permutation(cards, i, 0, "");
    }
    
    for(int i : primeNums){
        if(checkPrimeNum(i))
            answer++;
    }
    return answer;
}
