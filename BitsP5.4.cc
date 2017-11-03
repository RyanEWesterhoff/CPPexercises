#include <iostream>
using namespace std;

//Summary: Given a positive integer, print the next smallest and 
//next largest number that have the same number of 1 bits in their binary representation.

unsigned int countOnes(unsigned int i)
{
  unsigned int count = 0;
  while(i)
  {
    count += (i & 1);
    i >>= 1;
  }
  return count;
}


int main() {

   unsigned input = 11;
   unsigned nextLargest = input;
   unsigned nextSmallest = input;
   unsigned inOnes = countOnes(input);

   nextLargest++;
   while(countOnes(nextLargest) != inOnes)nextLargest++;

   nextSmallest--;
   while(countOnes(nextSmallest) != inOnes)nextSmallest--;

   cout << "Number of on bits: " << inOnes << endl;
   cout << "Input: " << input << endl;
   cout << "Next Largest: " << nextLargest << endl;
   cout << "Next Smallest: " << nextSmallest << endl;


return 0;
}

