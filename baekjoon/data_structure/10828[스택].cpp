#include <iostream>
#include <vector>
#include <string>
using namespace std;
struct stack {
private:
	vector<int> elements;
	int sp = -1;
public:
	int size() {
		return sp + 1;
	}
	int empty() {
		if (sp == -1) return 1;
		else return 0;
	}
	int top() {
		if (sp == -1) {
			return -1;
		}
		else return elements[sp];
	}
	void push(int data) {
		if (elements.size() - 1 == sp) elements.push_back(data);
		else elements[sp + 1] = data;
		sp++;
	}
	int pop() {
		if (sp == -1) return -1;
		sp--;
		return(elements[sp + 1]);
	}
};
int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	int n;
	cin >> n;
	stack temp;
	for (int i = 0; i < n; i++) {
		string command;
		int data;
		cin >> command;
		if (command.compare("push") == 0) {
			cin >> data;
			temp.push(data);
		}
		else if (command.compare("top") == 0) {
			cout << temp.top() << '\n';
		}
		else if (command.compare("size") == 0) {
			cout << temp.size() << '\n';
		}
		else if (command.compare("empty") == 0) {
			cout << temp.empty() << '\n';
		}
		else if (command.compare("pop") == 0) {
			cout << temp.pop() << '\n';
		}
	}
	return 0;
}
