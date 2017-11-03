#include <iostream>
using namespace std;

//Summary: Given an array and positive integer k, find K’th largest element in the array.

void insertionSort(int ary[], int n)
{
   int key;
   int j;

   for (int i = 1; i < n; i++)
   {
       key = ary[i];
       j = i-1;

       while (j >= 0 && ary[j] > key)
       {
           ary[j+1] = ary[j];
           j = j-1;
       }
       ary[j+1] = key;
   }
}

int main() {

	int ary[] = {7, 4, 6, 3, 9, 1};
	int k = 2;

	int arySize = sizeof(ary)/sizeof(int);

	insertionSort(ary, arySize);

	cout << "K’th largest element in the array is " << ary[arySize-k];


	return 0;
}

