#include <iostream>
using namespace std;

//Summary: Write a function to determine the number of bits 
//you would need to flip to convert integer A to integer B.

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

unsigned input1 = 29;
unsigned input2 = 15;
unsigned i = (input1^input2);


cout << countOnes(i) << " bits must be flipped to transform " << input1 << " to " << input2 << ".";

return 0;
}