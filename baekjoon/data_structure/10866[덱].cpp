#include <iostream>
using namespace std;
struct node {
	int num;
	node* prev;
	node* next;
	node(int n) :num(n), prev(nullptr), next(nullptr) {}
};
struct deque {
	node* fp = nullptr;
	node* bp = nullptr;
	int _size = 0;
	void push_front(int n) {
		node* temp = new node(n);
		if (_size == 0) {
			fp = temp;
			bp = temp;
		}
		else {
			temp->next = fp;
			fp->prev = temp;
			fp = temp;
		}
		_size++;
	}
	void push_back(int n) {
		node* temp = new node(n);
		if (_size == 0) {
			fp = temp;
			bp = temp;
		}
		else {
			temp->prev = bp;
			bp->next = temp;
			bp = temp;
		}
		_size++;
	}
	int pop_front() {
		if (fp == nullptr) return -1;
		int temp = fp->num;
		node* deleteNode = fp;
		fp = fp->next;
		if(fp != nullptr) fp->prev = nullptr;
		delete deleteNode;
		_size--;
		if (_size == 0) bp = nullptr;
		return temp;
	}
	int pop_back() {
		if (bp == nullptr) return -1;
		int temp = bp->num;
		node* deleteNode = bp;
		bp = bp->prev;
		if(bp != nullptr)bp->next = nullptr;
		delete deleteNode;
		_size--;
		if (_size == 0) fp = nullptr;
		return temp;
	}
	int size() {
		return _size;
	}
	int empty() {
		if (_size == 0) return 1;
		else return 0;
	}
	int front() {
		if (fp == nullptr) return -1;
		else return fp->num;
	}
	int back() {
		if (bp == nullptr) return -1;
		else return bp->num;
	}
	~deque() {
		if (fp == nullptr) return;
		while (fp->next != nullptr) {
			node* temp = fp->next;
			delete fp;
			fp = temp;
		}
		delete bp;
	}
};
int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	int n;
	cin >> n;
	deque deck;
	for (int i = 0; i < n; i++) {
		string commd;
		cin >> commd;
		if (commd.compare("push_back") == 0) {
			int data;
			cin >> data;
			deck.push_back(data);
		}
		else if (commd.compare("push_front") == 0) {
			int data;
			cin >> data;
			deck.push_front(data);
		}
		else if (commd.compare("front") == 0) {
			cout << deck.front() << '\n';
		}
		else if (commd.compare("back") == 0) {
			cout << deck.back() << '\n';
		}
		else if (commd.compare("empty") == 0) {
			cout << deck.empty() << '\n';
		}
		else if (commd.compare("pop_front") == 0) {
			cout << deck.pop_front() << '\n';
		}
		else if (commd.compare("pop_back") == 0) {
			cout << deck.pop_back() << '\n';
		}
		else if (commd.compare("size") == 0) {
			cout << deck.size() << '\n';
		}
	}
	return 0;
}
