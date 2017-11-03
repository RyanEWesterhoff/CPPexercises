#include <iostream>
using namespace std;

//Summary: you have an integer and you may flip one 0 to a 1, find the longest string on 1s  in the integer.

int flipToWin(unsigned i) {
	int curMax = -1;
	int count = 0;
	bool zeroFound = false;
	bool allOnes = true;



	while (i != 0) {

		if ((i & 1) == 1) {
			count++;
			i >>= 1;
		} else {
			allOnes = false;
			if (zeroFound == false) {
				int temp = i;
				temp >>= 1;

				//multiple zeroes in a row
				if ((temp & 1) == 0) {
					zeroFound = false;
					if (curMax < count)
						curMax = count;
					else {
						count = 0;
						i >>= 1;
					}
				} else { // zero found but next is 1
					zeroFound = true;
					count++;
					i >>= 1;
				}

			} else { //zero found but one found previously
				zeroFound = false;
				if (curMax < count)
					curMax = count;
				count = 0;

			}
		}
	}
	if(curMax == -1) curMax = count;

	if(allOnes == true) curMax++;

	return curMax;
}


int main() {

    cout << flipToWin(1775);
    cout << endl;

    cout << flipToWin(45);

return 0;
}

