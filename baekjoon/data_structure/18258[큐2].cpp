#include <iostream>
#include <vector>
using namespace std;
struct node {
	int data = -1;
	node* next = nullptr;
	node(int d) : data(d) {}
};
struct queue {
private:
	int _size = 0;
	node* fp = nullptr;
	node* bp = nullptr;
public:
	void push(int data) {
		node* temp = new node(data);
		if (fp == nullptr) {
			fp = temp;
			bp = fp;
		}
		else {
			bp->next = temp;
			bp = temp;
		}
		_size++;
	}
	int pop() {
		if (fp != nullptr) {
			int temp = fp->data;
			node* ntemp = fp->next;
			delete fp;
			fp = ntemp;
			_size--;
			if (_size == 0) bp = ntemp;
			return temp;
		}
		else return -1;
	}
	int size() {
		return _size;
	}
	int empty() {
		if (fp == nullptr) return 1;
		else return 0;
	}
	int front() {
		if (fp == nullptr) return -1;
		else return fp->data;
	}
	int back() {
		if (bp == nullptr) return -1;
		else return bp->data;
	}
	~queue() {
		while (fp->next != nullptr) {
			node* deltemp = fp->next;
			delete fp;
			fp = deltemp;
		}
		delete bp;
	}
};

int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	queue q;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string command;
		int data;
		cin >> command;
		if (command.compare("push") == 0) {
			cin >> data;
			q.push(data);
		}
		else if (command.compare("front") == 0) {
			cout << q.front() << '\n';
		}
		else if (command.compare("size") == 0) {
			cout << q.size() << '\n';
		}
		else if (command.compare("empty") == 0) {
			cout << q.empty() << '\n';
		}
		else if (command.compare("pop") == 0) {
			cout << q.pop() << '\n';
		}
		else if (command.compare("back") == 0) {
			cout << q.back() << '\n';
		}
	}
	return 0;
}
