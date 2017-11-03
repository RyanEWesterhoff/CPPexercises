//Hilariously slow, improve when time permits
#include<iostream>
#include <vector>
using namespace std;

//Summary: Given a chess board, print all sequences of moves of a knight on a chessboard such that the knight visits every square only once.



bool found = false;

void printAry(vector<vector<int>> ary, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << ary[i][j] << " ";
		}
		cout << endl;
	}
	cout << "              " << endl;
}

bool knightsTour(vector<vector<int>> ary, int row, int col, int count) {
	if (found == true)
		return true;
	if (ary[row][col] == 0) {
		count++;
		ary[row][col] = count;
		if (count == 64) {
			found = true;
			printAry(ary, 8);
			return true;
		} else {
			if ((row - 2 >= 0) && (col + 1 < 8))
				knightsTour(ary, row - 2, col + 1, count);
			if ((row - 1 >= 0) && (col + 2 < 8))
				knightsTour(ary, row - 1, col + 2, count);
			if ((row + 1 < 8) && (col + 2 < 8))
				knightsTour(ary, row + 1, col + 2, count);
			if ((row + 2 < 8) && (col + 1 < 8))
				knightsTour(ary, row + 2, col + 1, count);
			if ((row + 2 < 8) && (col - 1 >= 0))
				knightsTour(ary, row + 2, col - 1, count);
			if ((row + 1 < 8) && (col - 2 >= 0))
				knightsTour(ary, row + 1, col - 2, count);
			if ((row - 1 >= 0) && (col - 2 >= 0))
				knightsTour(ary, row - 1, col - 2, count);
			if ((row - 2 >= 0) && (col - 1 >= 0))
				knightsTour(ary, row - 2, col - 1, count);

		}
	}
	return false;
}

int main() {

	vector<vector<int>> board(8, vector<int>(8, 0));

	knightsTour(board, 0, 0, 0);

	return 0;
}
