#include <iostream>
#include <stack>
using namespace std;

//Summary: Write a queue

struct MyQueue {
	stack<int> s;
	int frontVal;
	int backVal;

	void push(int x) {
		if (s.empty())
			frontVal = x;
		s.push(x);
		if (s.top() == frontVal) {
			backVal = frontVal;
		} else {
			backVal = s.top();
		}
	}

	void pop() {
		if (!s.empty()) {
			stack<int> tempStack;
			while (s.top() != frontVal) {
				tempStack.push(s.top());
				s.pop();
			}

			if (!tempStack.empty()) {
				frontVal = tempStack.top();
				s.pop();
				s.push(tempStack.top());
				tempStack.pop();
			}else{
				s.pop();
			}

			while (!tempStack.empty()) {
				s.push(tempStack.top());
				tempStack.pop();
			}

			if(s.empty())frontVal = backVal = 0;
			else backVal = s.top();


		} else {
			frontVal = backVal = 0;
		}
	}

	int back() {
		return backVal;
	}

	int front() {
		return frontVal;
	}

};

int main() {
	MyQueue q;

	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	q.push(5);

	cout << "front: " << q.front() << endl;
	cout << "back: " << q.back() << endl;

	q.pop();

	cout << "front: " << q.front() << endl;
	cout << "back: " << q.back() << endl;

	q.pop();
	q.pop();
	q.pop();
	q.pop();

	cout << "front: " << q.front() << endl;
	cout << "back: " << q.back() << endl;
}

