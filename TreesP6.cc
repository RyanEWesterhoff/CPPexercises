#include <iostream>
using namespace std;

/*Summary:

Given a binary tree, find the maximum path sum. The path may start and end at any node in the tree. Every node contains distinct data.

Input
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case contains an integer n denoting the number of edges of the tree. The next line contains the edges of the binary tree.

Output
Print the maximum path sum in the binary tree.

Constraints
1<=T<=100
1<=n<=100
-100<=data of node<=100

*/

int maxSum = 0;

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


void preorderAdd(node* node, int sum)
{
    if (!node){
    	if(sum > maxSum)maxSum = sum;
    	return;
    }
    sum += node->data;
    preorderAdd(node->left, sum);
    preorderAdd(node->right, sum);
}


int main() {

    //Enter values in PREORDER to build tree
	int ary[7] = {1,2,3,4,5,6,7};

	node* root = bstFromAry(ary, 0, 6);

	preorderAdd(root,0);

	cout << maxSum;


	return 0;
}

