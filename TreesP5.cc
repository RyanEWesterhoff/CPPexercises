#include <iostream>
#include <string>
#include <array>
using namespace std;


/* Summary: Given an array, write a program that prints 1 if array represents Inorder traversal of a BST, else prints 0. Note that all keys in BST must be unique.

Input

The first line of input contains an integer T denoting the number of test cases.
The first line of each test case is N, N is the size of array.
The second line of each test case contains N input C[i].
Output
Print 1 array represents BST, else 0.

Constraints
1 ≤ T ≤ 100
1 ≤ N ≤ 500
1 ≤ Keys in BST ≤ 1200

*/

int main() {
	int numTests;
	string numTestsIn;
	int ary[500];
	string arySizeIn;
	int arySize;
	bool isBST = true;
	string aryIn;

	cout << "number of test cases: ";
	std::getline (std::cin, numTestsIn);
	numTests = stoi(numTestsIn);

	for(int i = 0; i < numTests; i++){
		cout << "array size: ";
		std::getline (std::cin, arySizeIn);
		arySize = stoi(arySizeIn);

		cout << "array values: ";
		std::getline (std::cin, aryIn);




		// read values into array
		int k = 0;
		for(unsigned j = 0; j < aryIn.length(); j++){
			if(isdigit((aryIn[j])) || (aryIn[j] == '-')){
				ary[k] = atoi(&aryIn[j]);
				while((isdigit(aryIn[j])) || (aryIn[j] == '-')) j++;
				k++;
			}
		}

		//test if BST
		int prev = ary[0];
		for(int j = 1; j < arySize; j++){
			if(prev >= ary[j]){
				cout << "0" << endl;
				isBST = false;
				break;
			}
			prev = ary[j];
		}

		if(isBST == true) cout << "1" << endl;
	}


	return 0;
}

