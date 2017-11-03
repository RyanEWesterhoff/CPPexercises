#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

//Summary: Uses a 100x100 array to simulate a flood fill command.

void floodfill(int x, int y, int oldC, int newC, int maxX, int maxY,
		int screen[100][100]) {

	if (screen[y][x] != oldC)
		return;

	screen[y][x] = newC;
	if (y + 1 < maxY)
		floodfill(x, y + 1, oldC, newC, maxX, maxY, screen);
	if (x + 1 < maxX)
		floodfill(x + 1, y, oldC, newC, maxX, maxY, screen);
	if (y - 1 >= 0)
		floodfill(x, y - 1, oldC, newC, maxX, maxY, screen);
	if (x - 1 >= 0)
		floodfill(x - 1, y, oldC, newC, maxX, maxY, screen);

}
int main() {
	int tests;
	string tIn;
	int sizX, sizY;
	int x, y, k;
	int oldC;
	string mIn;
	string mVals;
	string xyk;
	int screen[100][100];

	cout << "Test Cases: " << endl;
	getline(cin, tIn);
	tests = stoi(tIn);

	for (int t = 0; t < tests; t++) {
		cout << "Matrix size: " << endl;
		getline(cin, mIn);
		stringstream s1(mIn);
		s1 >> sizY;
		s1 >> sizX;

		cout << "Pixel values: " << endl;
		getline(cin, mVals);
		stringstream s2(mVals);

		for (int i = 0; i < sizY; i++) {
			for (int j = 0; j < sizX; j++) {
				s2 >> screen[i][j];
			}
		}

		cout << "X Y & K values: " << endl;
		getline(cin, xyk);
		cout << endl;
		stringstream s3(xyk);
		s3 >> x;
		s3 >> y;
		s3 >> k;

		for (int i = 0; i < sizY; i++) {
			for (int j = 0; j < sizX; j++) {
				cout << screen[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;

		oldC = screen[y][x];
		floodfill(x, y, oldC, k, sizX, sizY, screen);

		for (int i = 0; i < sizY; i++) {
			for (int j = 0; j < sizX; j++) {
				cout << screen[i][j] << " ";
			}
			cout << endl;
		}
	}
	return 0;
}
