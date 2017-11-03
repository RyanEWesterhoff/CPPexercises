#include <iostream>
using namespace std;

//Summary: Check if a given array contains duplicate elements within k distance from each other.

int main() {
    int ary[6]={1, 4, 2, 1, 2, 5};
    int k = 3;
    bool isTrue = false;
    
    //look for values at distance k or less
    for(int i = 0; i < sizeof(ary)/sizeof(ary[0]); i++){
        for(int j = 1; j <= k; j++){
            if(ary[i] == ary[i+j]){
                if(isTrue == false){
                    isTrue = true;
                    cout << "Output: True" << endl;
                }
                cout << ary[i] << " is repeated at distance " << j << endl;
            }
        }
    }
    
    if(isTrue == false){
        cout << "Output: False" << endl;
    }

}