#include <iostream>
using namespace std;

//Summary: Find the Nth node of any linked list.

struct node {
  int val;
  node *next = 0;
};

int main(){
    
    node *root = 0;
    node *current = 0;
    node *prev = 0;
    
    int n = 3; //The given element to find
    int count = 0;
    
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
    
   
   
    while (current != 0)
    {
       if (count == n) break;
       count++;
       current = current->next;
    }
    
    cout << current->val;
}