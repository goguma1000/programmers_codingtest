#include<string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    stack<char> Parentheses;
    for(int i = 0; i < s.length(); i++){
        if(Parentheses.empty() && s[i] == ')'){
            return false;
        }
        if(s[i] == '(') Parentheses.push(s[i]);
        else{
            Parentheses.pop();
        }
    }
    if(Parentheses.empty()) return  true;
    else return false;
   
}
