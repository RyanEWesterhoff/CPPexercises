#include <iostream>
#include <queue>
using namespace std;

//Summary: Given a binary tree, check whether it’s a binary search tree or not.

queue<int> inOrd;

struct node {
	int data;
	node* left;
	node* right;
};


struct node* newNode(int data)
{
    struct node* node = (struct node*) malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return node;
}

struct node* bstFromAry(int arr[], int start, int end)
{
    if (start > end)
      return NULL;

    int mid = (start + end)/2;
    struct node *root = newNode(arr[mid]);

    root->left =  bstFromAry(arr, start, mid-1);

    root->right = bstFromAry(arr, mid+1, end);

    return root;
}


void inorder(node* node)
{
    if (!node)
       return;
    inorder(node->left);
    inOrd.push(node->data);
    inorder(node->right);
}

bool checkForBST(queue<int> inOrd){
	int prev;
	prev = inOrd.front();
	inOrd.pop();

	while(!inOrd.empty()){
		if(prev > inOrd.front()) return false;
		prev = inOrd.front();
		inOrd.pop();
	}
	return true;
}

int main() {

	//Enter values in PREORDER to build tree
	int ary[9] = {1,2,3,4,5,6,7,8,9};

	node* root = bstFromAry(ary, 0, 8);

	inorder(root);

	if(checkForBST(inOrd) == true){
		cout << "This is a BST";
	}else{
		cout << "This is NOT a BST";
	}

	return 0;
}

