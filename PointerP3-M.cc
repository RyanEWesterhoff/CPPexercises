#include <iostream>
using namespace std;

//Summary: Find the mid point of linked list by scanning the list only once.

struct node {
	int val;
	node *next = 0;
};

int main() {

	int n = 5;
	node *root = 0;
	node *current = 0;
	node *prev = 0;
	node *mid = 0; // mid = n/2 for even lists

	//create list of n elements
	root = new node;
	root->val = 0;
	prev = root;
	for (int i = 1; i < n; i++) {
		current = new node;
		current->val = i;
		prev->next = current;
		prev = current;
	}
	current = root;
	
	int count = 0;
	mid = root;
	while(current != 0){
	    count++;
	    if(count % 2 != 0) mid = mid->next;
	    current = current->next;
	}
	
	cout << mid->val;

}