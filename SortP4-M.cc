#include <iostream>
using namespace std;

//Summary: Given a boolean 2D array, where each row is sorted. Find the row with the maximum number of 1s.

int main(){
	int input[4][4] = {{0,1,1,1},
					   {0,0,1,1},
					   {1,1,1,1},
					   {0,0,0,0}};

	bool allOne = false;
	int rows =  sizeof input / sizeof input[0];
	int cols = sizeof input[0] / sizeof(int);
	int fullRow;

	for(int i = 0; i < rows; i++){
		allOne = true;
		for(int j = 0; j < cols; j++){
			if(input[i][j] == 0) allOne = false;
		}
		if(allOne == true){
			fullRow = i;
			break;
		}
	}

	if(allOne == true){
		cout << fullRow;
	}else{
		cout << "No row found!";
	}


}