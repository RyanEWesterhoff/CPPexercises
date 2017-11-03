#include <iostream>
#include <stack>
using namespace std;

//Summary: Prints the elements of a singly linked list in reverse order.

struct node {
  int val;
  node *next = 0;
};

int main() {

    node *root = 0;
    node *current = 0;
    node *prev = 0;

    //create list of 5 elements
    root = new node;
    root -> val = 0;
    prev = root;
    for(int i = 1; i < 5; i++){
        current = new node;
        current -> val = i;
        prev -> next = current;
        prev = current;
    }
    current = root;


    //reverse list
    stack<node*> nodeStack;
    while(current != 0){
        nodeStack.push(current);
        current = current -> next;
    }

    while(nodeStack.empty() == false){
        cout << nodeStack.top() -> val << " ";
        nodeStack.pop();
    }

}