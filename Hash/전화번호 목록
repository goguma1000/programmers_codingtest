#include <string>
#include <vector>
#include <map>
using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    int minlength = 22;
    map<string, vector<string>> phone_dic;
    for (int i = 0; i < phone_book.size(); i++) {
        if (phone_book[i].length() < minlength) minlength = phone_book[i].length();
    }

    for (int i = 0; i < phone_book.size(); i++) {
        if (phone_dic.count(phone_book[i].substr(0, minlength)) > 0) {
            for (string s : phone_dic[phone_book[i].substr(0, minlength)]) {
                int minsize = min(phone_book[i].length(), s.length());
                string subs1 = s.substr(0, minsize);
                string subs2 = phone_book[i].substr(0, minsize);
                if (subs1.compare(subs2) == 0) return !answer;
            }
            phone_dic[phone_book[i].substr(0, minlength)].push_back(phone_book[i]);
        }
        else {
            vector<string> elements;
            elements.push_back(phone_book[i]);
            phone_dic.insert({ phone_book[i].substr(0,minlength), elements });
        }
    }
    return answer;
}
