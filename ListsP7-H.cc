#include <iostream>
#include <stack>
using namespace std;

//Summary: Given a list of N elements, reverses the last K elements in the list.

struct node {
	int val;
	node *next = 0;
};

int main() {

	node *root = 0;
	node *current = 0;
	node *prev = 0;
	int k = 2; //last k elements of the list
	int n = 0; //total number of elements

	//create list of 5 elements
	root = new node;
	n++;
	root->val = 0;
	prev = root;
	for (int i = 1; i < 5; i++) {
		current = new node;
		current->val = i;
		prev->next = current;
		prev = current;
		n++;
	}
	current = root;

	//move current to last k
	for (int i = 0; i < n - k; i++) {
		current = current->next;
	}

	//reverse list
	stack<node*> nodeStack;
	while (current != 0) {
		nodeStack.push(current);
		current = current->next;
	}

	current = root;
	//move current to last k
	for (int i = 0; i < n - k - 1; i++) {
		current = current->next;
	}

	while (nodeStack.empty() == false) {
		current->next = nodeStack.top();
		nodeStack.pop();
		current = current->next;
	}
	current->next = 0;

	current = root;
	while (current != 0) {
		cout << current->val << " ";
		current = current->next;
	}

}