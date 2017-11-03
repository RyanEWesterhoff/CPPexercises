#include<iostream>
#include<math.h>
using namespace std;

//Summary: A thief is robbing a store and can carry a maximal weight of W into his knapsack. There are n items available in the store and weight of ith item is wi and its profit is pi. What items should the thief take?


int knapSack(int cap, int wts[], int vals[], int n)
{
   int i, j;
   int maxTable[n+1][cap+1];

   for (i = 0; i <= n; i++)
   {
       for (j = 0; j <= cap; j++)
       {
           if (i==0 || j==0)
               maxTable[i][j] = 0;
           else if (wts[i-1] <= j)
                 maxTable[i][j] = max(vals[i-1] + maxTable[i-1][j-wts[i-1]],  maxTable[i-1][j]);
           else
                 maxTable[i][j] = maxTable[i-1][j];
       }
   }

//   for(int i = 0; i < n; i++){
// 	   for(int j = 0; j < cap; j++){
// 		   cout << maxTable[i][j] << " ";
// 	   }
// 	   cout << endl;
//   }

   return maxTable[n][cap];
}

int main()
{
    int val[] = {5, 10, 6, 9, 7, 2};
    int wt[] = {1, 2, 3, 2, 3, 4};
    int  maxWeight = 5;
    int n = sizeof(val)/sizeof(val[0]);

    cout << knapSack(maxWeight, wt, val, n);
    return 0;
}

