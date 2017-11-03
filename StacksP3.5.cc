#include <iostream>
#include <stack>
using namespace std;

//Summary: Sort a stack of ints.

void sortStack(stack<int> &stk) {
	stack<int> temp;
	int smallVal = stk.top();
	int count = 0;
	int numSorted = 0;
	int topSortedVal;

	while (!stk.empty()) {
		temp.push(stk.top());
		stk.pop();
		count++;
	}
	while (!temp.empty()) {
		stk.push(temp.top());
		temp.pop();
	}

	while (numSorted < count) {
		smallVal = stk.top();
		while (!stk.empty()) {
			if (stk.top() < smallVal)
				smallVal = stk.top();
			temp.push(stk.top());
			stk.pop();
		}
		while ((!temp.empty()) && (temp.top() != topSortedVal)) {
			if (temp.top() != smallVal)
				stk.push(temp.top());
			temp.pop();
		}
		temp.push(smallVal);
		topSortedVal = temp.top();
		numSorted++;
	}

	while(!temp.empty()){
		stk.push(temp.top());
		temp.pop();
	}
}
int main() {

	stack<int> s;
	s.push(3);
	s.push(2);
	s.push(1);
	s.push(4);
	s.push(5);

	sortStack(s);

	while (!s.empty()) {
		cout << s.top() << " ";
		s.pop();
	}

}

