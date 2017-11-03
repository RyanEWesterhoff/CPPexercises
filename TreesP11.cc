#include <iostream>
#include <time.h>
using namespace std;

//Summary: Tree that has an inorder function, and a function that retrieves a random node.

struct node {
	int data;
	node* left;
	node* right;
};

node* root;
int numNodes = 0;
int count = 0;

struct node* newNode(int data) {
	struct node* node = (struct node*) malloc(sizeof(struct node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;

	return node;
}

//print nodes out inorder
void inorder(node* node) {
	if (!node)
		return;
	inorder(node->left);
	cout << node->data << " ";
	inorder(node->right);
}

void addNode(int data) {

	// empty tree
	if (!root) {
		root = newNode(data);
		numNodes++;
	} else {
		node *curNode = root;
		while (true) { //loop until return
			if (curNode->data > data) {
				// if curNode > data, send newNode left
				if (curNode->left != NULL) {
					curNode = curNode->left;
					continue;
				} else { //found empty left space
					curNode->left = newNode(data);
					numNodes++;
					return;
				}
			} else {
				// curNode < data, send newNode right
				if (curNode->right != NULL) {
					curNode = curNode->right;
					continue;
				} else { //found empty right space
					curNode->right = newNode(data);
					numNodes++;
					return;
				}
			}
		}
	}
}

node* find(int val) {
	node* node = root;
	while (node != NULL) {
		if (node->data == val) {
			return node;
		} else if (val < node->data) {
			node = node->left;
		} else {
			node = node->right;
		}
	}
	return NULL;
}

//finds a node at a given position inorder
void inorderSearch(node* node, int pos) {
	if (!node)
		return;
	inorderSearch(node->left, pos);
	count++;
	if (count == pos)
		cout << node->data;
	inorderSearch(node->right, pos);
}

//construct a RNG
void initRand() {
	srand(time(NULL));
}

void randomNode() {
	count = 0;
	int randPos = (rand() % numNodes) + 1;
	inorderSearch(root, randPos);
}

int main() {

	for (int i = 1; i <= 7; i++) {
		addNode(i);
	}
	initRand();
	addNode(12);

	addNode(9);

	inorder(root);

	cout << endl;
	randomNode();
	cout << endl;

	randomNode();
	cout << endl;

	randomNode();
	cout << endl;

	node* n = find(9);
	cout << n->data;

	return 0;
}

